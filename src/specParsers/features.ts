import { arraize } from "./utils";
import { bitmasks, enums, isVerbose } from "../cli";
export function parseFeatures(xml: any): void {
  const featureNodes = xml.registry.feature;
  for (const featnode of featureNodes) {
    const name = featnode["@_name"] ?? "no name";
    const number = featnode["@_number"] ?? "0";
    const apis = (featnode["@_api"] ?? "vulkan").split(",");
    if (!apis.includes("vulkan")) {
      continue;
    }
    if (isVerbose) {
      console.log(`Found feature ${name} ${number}`);
    }
    const requires = arraize(featnode.require ?? []); // eh
    for (const require of requires) {
      arraize(require.enum ?? []).map((a) => {
        const name = a["@_name"];
        const alias = a["@_alias"];
        const extend = a["@_extends"];
        if (alias && extend) {
          return;
        }
        const extnumber = parseInt(a["@_extnumber"] ?? number);
        const offset = a["@_offset"];
        const bitpos = a["@_bitpos"];
        const valuex = a["@_value"];
        if (bitpos && extend) {
          const bitbase = bitmasks.find((x) => x.name === extend);
          if (!bitbase) {
            throw new Error(`Cannot find bitmask ${extend}`);
          }
          bitbase.bits.push({
            name: name as string,
            bitpos: parseInt(bitpos),
            value: null,
          });
          return;
        }
        const dir = a["@_dir"];
        if (extend && offset) {
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
            throw new Error(`Cannot resolve enum ${extend}`);
          }
          enumbase.entries.push({
            key: name,
            value: value.toString(),
          });
        }
      });
    }
  }
  for (const featnode of featureNodes) {
    const apis = (featnode["@_api"] ?? "vulkan").split(",");
    if (!apis.includes("vulkan")) {
      continue;
    }
    const requires = arraize(featnode.require ?? []); // eh
    for (const require of requires) {
      arraize(require.enum ?? []).map((a) => {
        const name = a["@_name"];
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
              throw new Error(
                `Cannot find enum value ${extend}.${alias} to alias ${extend}.${name} `
              );
            }
            bitbase.bits.push({
              name: name as string,
              bitpos: baseEntry.bitpos,
              value: null,
            });
            return;
          }
          const baseEntry = enumbase.entries.find((x) => x.key === alias);
          if (!baseEntry) {
            throw new Error(
              `Cannot find enum value ${extend}.${alias} to alias ${extend}.${name} `
            );
          }
          enumbase.entries.push({
            key: name,
            value: baseEntry.value,
          });
          return;
        }
      });
    }
  }
}
