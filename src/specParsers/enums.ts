import { z } from "zod";
import { arraize } from "./utils";
import { isVerbose } from "../cli";

export const zodVulkanEnum = z.object({
  name: z.string(),
  entries: z.array(z.object({ value: z.string(), key: z.string() })),
});
export type VulkanEnum = z.infer<typeof zodVulkanEnum>;

export function parseEnums(xml: any): z.infer<typeof zodVulkanEnum>[] {
  return xml.registry.enums
    .filter((e: any) => e["@_type"] === "enum")
    .map((xmlenum: any) => {
      const name = xmlenum["@_name"];
      const entries = arraize(xmlenum.enum).map((e: any) => {
        return { value: e["@_value"], key: e["@_name"] };
      });
      if (isVerbose) {
        console.log(`Found enum ${name}`);
      }
      return { name, entries };
    });
}
