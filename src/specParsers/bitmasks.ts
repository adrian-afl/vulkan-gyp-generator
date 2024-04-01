import { z } from "zod";
import { arraize } from "./utils";
import { isVerbose } from "../cli";

export const zodVulkanBitmask = z.object({
  name: z.string(),
  bitWidth: z.number(),
  bits: z.array(
    z.object({
      bitpos: z.number(),
      name: z.string(),
      value: z.string().nullable(),
    })
  ),
});
export type VulkanBitmask = z.infer<typeof zodVulkanBitmask>;
export function parseBitmasks(xml: any): z.infer<typeof zodVulkanBitmask>[] {
  return xml.registry.enums
    .filter((e: any) => e["@_type"] === "bitmask")
    .map((xmlenum: any) => {
      const name = xmlenum["@_name"];
      const bitWidth = xmlenum["@_bitwidth"]
        ? parseInt(xmlenum["@_bitwidth"])
        : 32;
      const bits = xmlenum.enum
        ? arraize(xmlenum.enum).map((e: any) => {
            const value = e["@_value"] ?? e["@_alias"] ?? null;
            return {
              bitpos: parseInt(e["@_bitpos"]),
              name: e["@_name"],
              value,
            };
          })
        : [];
      if (isVerbose) {
        console.log(`Found bitmask ${name}`);
      }
      return { name, bits, bitWidth };
    });
}
