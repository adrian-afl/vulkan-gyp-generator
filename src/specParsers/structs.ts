import { z } from "zod";
import { arraize } from "./utils";
import { isVerbose } from "../cli";

const zodVulkanStruct = z.object({
  name: z.string(),
  structextends: z.array(z.string()),
  members: z.array(
    z.object({
      name: z.string(),
      type: z.string(),
      values: z.string(),
      isPointer: z.boolean(),
      isArray: z.boolean(),
      isDoublePointer: z.boolean(),
      modifiers: z.array(z.string()),
      optional: z.boolean(),
      len: z.string(),
    })
  ),
});
export type VulkanStruct = z.infer<typeof zodVulkanStruct>;

export const countChar = function (str: string, ch: string): number {
  return str.split("").reduce((n, x) => n + (x === ch ? 1 : 0), 0);
};

export function parseStructs(xml: any): z.infer<typeof zodVulkanStruct>[] {
  return xml.registry.types.type
    .filter((e: any) => e["@_category"] === "struct")
    .map((xmlenum: any) => {
      const name = xmlenum["@_name"];
      const structextends = xmlenum["@_structextends"]
        ? xmlenum["@_structextends"].split(",")
        : [];
      const members = xmlenum.member
        ? arraize(xmlenum.member)
            .map((p: any) => {
              const name = p.name;
              const isPointer = (p["#text"] ?? "").includes("*");
              const isArray = (p["#text"] ?? "").includes("[");
              const isDoublePointer = countChar(p["#text"] ?? "", "*") >= 2;
              const modifiers = (p["#text"] ?? "")
                .replaceAll("*", "")
                .trim()
                .replaceAll(/[ ]+/g, " ")
                .split(" ");
              const type = p.type.trim();
              const optional = p["@_optional"]
                ? p["@_optional"] === "true"
                : false;
              const deprecated = !!p["@_deprecated"];
              const api = p["@_api"] ?? "vulkan";
              const values = p["@_values"] ?? "";
              const len = p["@_len"] ?? "";
              return {
                name,
                type,
                values,
                isPointer,
                isArray,
                modifiers,
                optional,
                deprecated,
                api,
                isDoublePointer,
                len,
              };
            })
            .filter((x) => !x.deprecated && x.api === "vulkan")
        : [];
      if (isVerbose) {
        console.log(`Found struct ${name}`);
      }
      return { name, members, structextends };
    });
}
