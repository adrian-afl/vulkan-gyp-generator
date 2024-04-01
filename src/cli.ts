import { XMLParser } from "fast-xml-parser";
import * as fs from "fs";
import { parseEnums, VulkanEnum } from "./specParsers/enums";
import { parseTypes } from "./specParsers/types";
import { parseConstants } from "./specParsers/constants";
import { parseStructs } from "./specParsers/structs";
import { parseCommands } from "./specParsers/commands";
import { parseBitmasks, VulkanBitmask } from "./specParsers/bitmasks";
import { parseExtensions } from "./specParsers/extensions";
import { generateCommandsH } from "./generators/commandsH";
import { generateInitH } from "./generators/initH";
import { generateDistTs } from "./generators/distTs";
import { generateAlignmentHTs } from "./generators/AlignmentHTs";

import { program } from "commander";
import { z } from "zod";
import * as path from "path";
import { generateDefinesAndIncludes } from "./generators/definesIncludes";
import { parseFeatures } from "./specParsers/features";

program.requiredOption("--config <config>", "configuration file");
program.option("--verbose <verbose>", "print more info");

program.parse();

const zodGeneratorConfig = z.object({
  specificationVersion: z
    .string()
    .regex(
      /\d\.\d\.\d+\.\d+/,
      "Vulkan version format incorrect, use for example 1.3.250.1"
    ),
  xml: z.string().endsWith(".xml", "Not an XML file judging by the extension"),
  outputDirectory: z.string().min(1),
  defines: z.record(z.string()),
  includes: z.array(z.string()),
  extensions: z.array(z.string()),
  vulkanSDKPath: z.string(),
  handlesSize: z.enum(["32", "64"]),
});

const zodCliArgs = z.object({
  config: z.string().min(1),
  verbose: z
    .enum(["true", "false"])
    .transform((value) => value === "true")
    .optional(),
});

const clioptions = zodCliArgs.parse(program.opts());

export const isVerbose = clioptions.verbose ?? false;

console.log(`Reading config ${clioptions.config}`);
const configPath = path.resolve(clioptions.config);

if (!fs.existsSync(configPath)) {
  throw new Error("Config file not found");
}

const config = zodGeneratorConfig.parse(
  JSON.parse(fs.readFileSync(clioptions.config).toString("utf-8"))
);

export const handlesSize = config.handlesSize;

const outDir = path.resolve(config.outputDirectory);

if (!fs.existsSync(outDir)) {
  fs.mkdirSync(outDir, { recursive: true });
}

console.log("Reading XML file...");

const options = {
  ignoreAttributes: false,
  attributeNamePrefix: "@_",
  allowBooleanAttributes: false,
  // preserveOrder: false,
  // trimValues: true,
  // alwaysCreateTextNode: true,
};
const parser = new XMLParser(options);
const xml = parser.parse(fs.readFileSync(config.xml));

console.log("Parsing enums...");
export const enums = parseEnums(xml);

console.log("Parsing bitmasks...");
export const bitmasks = parseBitmasks(xml);
console.log("Parsing commands...");
const allcommands = parseCommands(xml);
console.log("Parsing structs...");
const allstructs = parseStructs(xml);
console.log("Parsing constants...");
export const constants = parseConstants(xml);
console.log("Parsing some other types...");
export const types = parseTypes(xml);
console.log("Parsing extensions...");
parseFeatures(xml);
const enabledExtensions = config.extensions;
export const extensions = parseExtensions(xml, enabledExtensions);

const isTypeExtensionDisabled = (name: string): boolean =>
  extensions
    .filter((e) => e.types.includes(name) || e.commands.includes(name))
    .map((e) => e.name)
    .filter((e) => !enabledExtensions.includes(e)).length !== 0;

const disabledCommands: string[] = [
  "vkGetFaultData",
  "vkGetCommandPoolMemoryConsumption",
  // "vkCreateWin32SurfaceKHR",
];

export const commands = allcommands.filter(
  (cmd) =>
    !isTypeExtensionDisabled(cmd.name) && !disabledCommands.includes(cmd.name)
);

const disabledStructs: string[] = [
  // those seem to be from vulkansc but are not labelled correctly
  "VkPipelineOfflineCreateInfo",
  "VkPipelineShaderStageRequiredSubgroupSizeCreateInfo",
  "VkPipelineCacheStageValidationIndexEntry",
  "VkPipelineCacheSafetyCriticalIndexEntry",
  "VkPipelineCacheHeaderVersionSafetyCriticalOne",
  "VkFaultCallbackInfo",
  "VkFaultData",
  "VkPhysicalDeviceVulkanSC10Properties",
  "VkDeviceObjectReservationCreateInfo",
  "VkPipelinePoolSize",
  "VkCommandPoolMemoryReservationCreateInfo",
  "VkCommandPoolMemoryConsumption",
  "VkPhysicalDeviceVulkanSC10Features",
];

export const structs = allstructs.filter(
  (strcty) =>
    !isTypeExtensionDisabled(strcty.name) &&
    !disabledStructs.includes(strcty.name)
);

export const findEnum = (name: string): VulkanEnum | undefined =>
  enums.find((e) => e.name === name);
export const findBitmask = (name: string): VulkanBitmask | undefined =>
  bitmasks.find((e) => e.name === name);

export const manualTypesMapNative = {
  VkSampleMask: "uint32_t",
  VkBool32: "uint32_t",
  VkFlags: "uint32_t",
  VkFlags64: "uint64_t",
  VkDeviceSize: "uint64_t",
  VkDeviceAddress: "uint64_t",
  void: "uint64_t",
};

export const manualTypesMapTS = {
  VkSampleMask: "uint32_t",
  VkBool32: "uint32_t",
  VkFlags: "uint32_t",
  VkFlags64: "uint64_t",
  VkDeviceSize: "uint64_t",
  VkDeviceAddress: "ptr64_t",
  void: "ptr64_t",
  HINSTANCE: "ptr64_t",
  HWND: "ptr64_t",
};

export const simplifyTypeNative = (
  original: string,
  withFns = true
): string => {
  const foundEnum = findEnum(original);
  const foundBitmask =
    findBitmask(original) ?? findBitmask(original.replace("Flags", "FlagBits"));
  if (foundEnum) {
    original = "int32_t";
  } else if (foundBitmask) {
    original = `uint${foundBitmask.bitWidth}_t`;
  }
  if (manualTypesMapNative[original as keyof typeof manualTypesMapNative]) {
    original =
      manualTypesMapNative[original as keyof typeof manualTypesMapNative];
  }
  if (types.bitmaskTypeNames.includes(original)) {
    // still a flags? probably empty def, default to 32
    original = "int32_t";
  }
  if (types.handleTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "uint64_t";
  }
  if (withFns && types.fnptrsTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "uint64_t";
  }
  return original;
};

export const simplifyTypeTS = (original: string, withFns = true): string => {
  const foundEnum = findEnum(original);
  const foundBitmask =
    findBitmask(original) ?? findBitmask(original.replace("Flags", "FlagBits"));
  if (foundEnum) {
    original = "int32_t";
  } else if (foundBitmask) {
    original = `uint${foundBitmask.bitWidth}_t`;
  }
  if (manualTypesMapTS[original as keyof typeof manualTypesMapTS]) {
    original = manualTypesMapTS[original as keyof typeof manualTypesMapTS];
  }
  if (types.bitmaskTypeNames.includes(original)) {
    // still a flags? probably empty def, default to 32
    original = "int32_t";
  }
  if (types.handleTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "ptr64_t";
  }
  if (withFns && types.fnptrsTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "ptr64_t";
  }
  return original;
};

export const simplifyTypeTSBaseTypes = (
  original: string,
  withFns = true
): string => {
  const foundEnum = findEnum(original);
  const foundBitmask =
    findBitmask(original) ?? findBitmask(original.replace("Flags", "FlagBits"));
  if (foundEnum) {
    original = "number";
  } else if (foundBitmask) {
    original = "number";
  }
  if (manualTypesMapTS[original as keyof typeof manualTypesMapTS]) {
    original = "number";
  }
  if (types.bitmaskTypeNames.includes(original)) {
    // still a flags? probably empty def, default to 32
    original = "number";
  }
  if (types.handleTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "number";
  }
  if (withFns && types.fnptrsTypeNames.includes(original)) {
    // very discussable, and only valid for x64 systems
    original = "number";
  }
  if (
    [
      "uint8_t",
      "uint16_t",
      "uint32_t",
      "uint64_t",
      "int8_t",
      "int16_t",
      "int32_t",
      "int64_t",
      //  "ptr64_t",
      "size_t",
      "float",
      "double",
    ].includes(original)
  ) {
    return "number";
  }
  return ""; // ehh
};

console.log("Populating directory with the template...");

fs.cpSync(path.resolve("gypTemplate"), outDir, {
  recursive: true,
  errorOnExist: false,
});

console.log("Updating gyp config...");

const gypcfg = JSON.parse(
  fs.readFileSync(`${outDir}/binding.gyp`).toString("utf-8")
);
gypcfg.variables.vkSDK = config.vulkanSDKPath;
fs.writeFileSync(`${outDir}/binding.gyp`, JSON.stringify(gypcfg, undefined, 4));

console.log("Writing init.h...");
generateInitH(`${outDir}/native/init.h`);

console.log("Writing commands.h...");
generateCommandsH(`${outDir}/native/commands.h`);

console.log("Writing alignment.h and alignmentValuesMap.json...");
generateAlignmentHTs(
  `${outDir}/native/alignment.h`,
  `${outDir}/node/alignmentValuesMap.json`
);

generateDefinesAndIncludes(
  `${outDir}/native/defines_includes.h`,
  config.defines,
  config.includes
);

console.log("Writing dist.ts...");
generateDistTs(`${outDir}/node/dist.ts`);

console.log("Done!");
