import { isVerbose } from "../cli";

export function parseConstants(
  xml: any
): { type: string; name: string; value: number | bigint }[] {
  const constantsNodes = xml.registry.enums.filter(
    (e: any) => e["@_name"] === "API Constants"
  )[0].enum;
  const constants: { type: string; name: string; value: number | bigint }[] =
    [];
  for (const cnode of constantsNodes) {
    const name = cnode["@_name"];
    if (cnode["@_alias"]) {
      const aliased = constants.find((c) => c.name === cnode["@_alias"]);
      if (aliased) {
        constants.push({ ...aliased, name });
      }
    } else {
      const type = cnode["@_type"] as string;
      const value = cnode["@_value"] as string;
      let num: number | bigint =
        type === "float" ? parseFloat(value.replace("F", "")) : parseInt(value);
      if (value.startsWith("(~")) {
        const primary = parseInt(value.replaceAll(/[^0-9]/g, ""));
        const bits = Array(type.includes("32") ? 32 : 64).fill(1);
        if (primary === 2) {
          bits[bits.length - 2] = 0;
        }
        num = BigInt(`0b${bits.join("")}`);
      }
      if (isVerbose) {
        console.log(`Found constant ${name}`);
      }
      constants.push({ name, type, value: num });
    }
  }
  return constants;
}
