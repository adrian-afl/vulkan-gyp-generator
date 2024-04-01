import { z } from "zod";
import { arraize } from "./utils";
import { countChar } from "./structs";
import { isVerbose } from "../cli";

const zodVulkanCommand = z.object({
  returnType: z.string(),
  name: z.string(),
  params: z.array(
    z.object({
      name: z.string(),
      type: z.string(),
      isPointer: z.boolean(),
      isArray: z.boolean(),
      modifiers: z.array(z.string()),
      optional: z.boolean(),
      isDoublePointer: z.boolean(),
      len: z.string(),
    })
  ),
  successCodes: z.array(z.string()),
  errorCodes: z.array(z.string()),
});

export type VulkanCommand = z.infer<typeof zodVulkanCommand>;

export function parseCommands(xml: any): VulkanCommand[] {
  const commands: VulkanCommand[] = [];
  xml.registry.commands.command.map((xmlcmd: any) => {
    if (!xmlcmd.proto) {
      return;
    }
    const api = xmlcmd["@_api"] ?? "vulkan";
    if (api !== "vulkan") {
      return;
    }
    const name = xmlcmd.proto.name;
    const isPointer = (xmlcmd.proto["#text"] ?? "").includes("*");
    const modifiers = (xmlcmd.proto["#text"] ?? "").replaceAll("*", "");
    const returnType = `${modifiers} ${xmlcmd.proto.type} ${
      isPointer ? "*" : ""
    }`.trim();
    const params = xmlcmd.param
      ? arraize(xmlcmd.param)
          .map((p: any) => {
            let paramname = p.name;
            if (paramname === "function") {
              paramname = "ffunction";
            }
            const isPointer = (p["#text"] ?? "").includes("*");
            const isArray = (p["#text"] ?? "").includes("[");
            const isDoublePointer = countChar(p["#text"] ?? "", "*") >= 2;
            const modifiers = (p["#text"] ?? "")
              .replaceAll("*", "")
              .replaceAll(/\[.*]/g, "")
              .trim()
              .replaceAll(/[ ]+/g, " ")
              .split(" ");
            const type = p.type.trim();
            const optional = p["@_optional"]
              ? p["@_optional"] === "true"
              : false;
            const api = p["@_api"] ?? "vulkan";
            const len = p["@_len"] ?? "";

            if (
              paramname.startsWith("p") &&
              paramname[1] === paramname[1].toUpperCase() && // detect camel case to prevent matching param and physical
              !isPointer
            ) {
              console.warn(
                `Warning, ${paramname} of type ${type} of struct ${name}: name suggest a pointer, but the type is not a pointer.`
              );
            }

            return {
              name: paramname,
              isPointer,
              modifiers,
              type,
              optional,
              isArray,
              api,
              isDoublePointer,
              len,
            };
          })
          .filter((x) => x.api === "vulkan")
      : [];
    const successCodes = xmlcmd["@_successcodes"]
      ? xmlcmd["@_successcodes"].split(",")
      : [];
    const errorCodes = xmlcmd["@_errorcodes"]
      ? xmlcmd["@_errorcodes"].split(",")
      : [];
    const cmd = { name, returnType, params, successCodes, errorCodes };
    zodVulkanCommand.parse(cmd);
    if (isVerbose) {
      console.log(`Found command ${name}`);
    }
    commands.push(cmd);
  });
  return commands;
}
