import { arraize } from "./utils";
import { bitmasks, enums, isVerbose } from "../cli";
export function parseExtensions(
  xml: any,
  enabledExtensions: string[]
): { name: string; platform: string; types: string[]; commands: string[] }[] {
  const extensionNodes = xml.registry.extensions.extension;
  const extensions: {
    name: string;
    platform: string;
    types: string[];
    commands: string[];
  }[] = [];
  for (const extnode of extensionNodes) {
    const extname = extnode["@_name"];
    const number = extnode["@_number"] ?? "0";
    const platform = extnode["@_platform"] ?? "";
    const supported = extnode["@_supported"] ?? "vulkan";
    if (supported !== "disabled" && !supported.split(",").includes("vulkan")) {
      //    continue;
    }
    const types: string[] = [];
    const commands: string[] = [];

    const requires = arraize(extnode.require ?? []); // eh

    for (const require of requires) {
      arraize(require.type ?? []).map((a) => types.push(a["@_name"]));
      arraize(require.command ?? []).map((a) => commands.push(a["@_name"]));
      arraize(require.enum ?? []).map((a) => {
        const name = a["@_name"];
        const api = a["@_api"] ?? "vulkan";
        if (api !== "vulkan") {
          return;
        }
        if (supported === "disabled") {
          return;
        }
        const deprecated = a["@_deprecated"] ?? "";
        if (deprecated.length > 0) {
          return;
        }
        const alias = a["@_alias"];
        const extend = a["@_extends"];
        if (alias && extend) {
          return;
        }
        const valuex = a["@_value"];
        const extnumber = parseInt(a["@_extnumber"] ?? number);
        const offset = a["@_offset"];
        const bitpos = a["@_bitpos"];
        if (bitpos && extend) {
          const bitbase = bitmasks.find((x) => x.name === extend);
          if (!bitbase) {
            throw new Error(`Cannot find bitmask ${extend}}`);
          }
          const baseEntry = bitbase.bits.find((x) => x.name === name);
          if (!baseEntry) {
            bitbase.bits.push({
              name: name as string,
              bitpos: parseInt(bitpos),
              value: null,
            });
          }
          return;
        }
        const dir = a["@_dir"];
        if (extend) {
          const enumbase = enums.find((x) => x.name === extend);
          if (!enumbase) {
            throw new Error(`Cannot find enum ${extend}`);
          }
          const dircoef = dir && dir === "-" ? -1.0 : 1.0;
          let value = dircoef * 1000000000;
          if (valuex) {
            value = parseInt(valuex);
          } else if (offset) {
            value += dircoef * (parseInt(offset) + 1000 * (extnumber - 1)); // ehhhhh
          } else {
            throw new Error(`Cannot resolve enum ${extend}}`);
          }
          const baseEntry = enumbase.entries.find((x) => x.key === name);
          if (!baseEntry) {
            // todo warn if value is different
            enumbase.entries.push({
              key: name,
              value: value.toString(),
            });
          }
        }
      });
    }

    if (isVerbose) {
      console.log(`Found extension ${extname}`);
    }
    extensions.push({ name: extname, platform, types, commands });
  }
  for (const extnode of extensionNodes) {
    const extname = extnode["@_name"];
    const supported = extnode["@_supported"] ?? "vulkan";
    if (supported !== "disabled" && !supported.split(",").includes("vulkan")) {
      //    continue;
    }

    const requires = arraize(extnode.require ?? []); // eh

    for (const require of requires) {
      arraize(require.enum ?? []).map((a) => {
        if (!enabledExtensions.includes(extname)) {
          return;
        }
        if (supported === "disabled") {
          return;
        }
        const name = a["@_name"];
        const api = a["@_api"] ?? "vulkan";
        if (api !== "vulkan") {
          return;
        }
        const deprecated = a["@_deprecated"] ?? "";
        if (deprecated.length > 0) {
          return;
        }
        const alias = a["@_alias"];
        const extend = a["@_extends"];
        if (alias && extend) {
          const enumbase = enums.find((x) => x.name === extend);
          if (!enumbase) {
            const bitbase = bitmasks.find((x) => x.name === extend);
            if (!bitbase) {
              throw new Error(
                `Cannot find enum ${extend}.${alias} to alias ${extend}.${name}`
              );
            }
            const baseEntry = bitbase.bits.find((x) => x.name === alias);
            if (!baseEntry) {
              // todo
              // throw new Error(
              //   `Cannot find enum value ${extend}.${alias} to alias ${extend}.${name} `
              // );
            } else {
              // bitbase.bits.push({
              //   name: name as string,
              //   bitpos: baseEntry.bitpos,
              //   value: null,
              // });
            }
            return;
          }
          const baseEntry = enumbase.entries.find((x) => x.key === alias);
          if (!baseEntry) {
            // todo
            // throw new Error(
            //   `Cannot find enum value ${extend}.${alias} to alias ${extend}.${name} `
            // );
          } else {
            // enumbase.entries.push({
            //   key: name,
            //   value: baseEntry.value,
            // });
          }
          return;
        }
      });
    }
  }
  return extensions;
}
