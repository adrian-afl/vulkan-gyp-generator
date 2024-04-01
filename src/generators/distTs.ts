import { VulkanCommand } from "../specParsers/commands";
import { distTsHeaders } from "./distTsHeaders";
import * as fs from "fs";
import {
  bitmasks,
  commands,
  constants,
  enums,
  handlesSize,
  simplifyTypeNative,
  simplifyTypeTS,
  simplifyTypeTSBaseTypes,
  structs,
  types,
} from "../cli";

const globalFunctions = [
  "vkEnumerateInstanceVersion",
  "vkEnumerateInstanceExtensionProperties",
  "vkEnumerateInstanceLayerProperties",
  "vkCreateInstance",
];

const generateOneCallTS = (cmd: VulkanCommand): string => {
  const hasInstance = cmd.params.find(
    (x) => x.name === "instance" && x.type === "VkInstance"
  );
  const hasDevice = cmd.params.find(
    (x) => x.name === "device" && x.type === "VkDevice"
  );
  const paramsWithInstanceIn = [...cmd.params];
  const paramsWithDeviceIn = [...cmd.params];
  if (!hasDevice && !hasInstance && !globalFunctions.includes(cmd.name)) {
    if (!hasInstance) {
      paramsWithInstanceIn.push({
        name: "instance",
        optional: false,
        len: "",
        type: "VkInstance",
        isArray: false,
        isPointer: false,
        isDoublePointer: false,
        modifiers: [],
      });
    }
    if (!hasDevice) {
      paramsWithDeviceIn.push({
        name: "device",
        optional: false,
        len: "",
        type: "VkDevice",
        isArray: false,
        isPointer: false,
        isDoublePointer: false,
        modifiers: [],
      });
    }
  }

  const paramsWithInstance = paramsWithInstanceIn.map((param) => {
    const ptype = simplifyTypeTS(param.type);
    let ptypetsbase = simplifyTypeTSBaseTypes(ptype);
    if (param.isPointer && ptypetsbase === "number") {
      ptypetsbase = "";
    }
    let mainType = simplifyTypeNative(param.type);
    if (param.isPointer && param.len.length > 0) {
      mainType += "[] | null | Membuf[]";
      ptypetsbase = "";
    } else if (param.isPointer && param.len.length === 0) {
      mainType += "| null";
      ptypetsbase = "";
    }
    if (param.isArray) {
      mainType += "[] | null";
      ptypetsbase = "";
    }
    if (param.optional && !param.isPointer) {
      mainType += " | nullptr_t";
    }
    return `  ${param.name}${
      param.optional && param.isPointer ? "?" : ""
    }: ${mainType}${
      ptypetsbase.length > 0 ? ` | ${ptypetsbase}` : ""
    } | Membuf`;
  });

  const paramsWithDevice = paramsWithDeviceIn.map((param) => {
    const ptype = simplifyTypeTS(param.type);
    let ptypetsbase = simplifyTypeTSBaseTypes(ptype);
    if (param.isPointer && ptypetsbase === "number") {
      ptypetsbase = "";
    }
    let mainType = simplifyTypeNative(param.type);
    if (param.isPointer && param.len.length > 0) {
      mainType += "[] | null | Membuf[]";
      ptypetsbase = "";
    } else if (param.isPointer && param.len.length === 0) {
      mainType += "| null";
      ptypetsbase = "";
    }
    if (param.isArray) {
      mainType += "[] | null";
      ptypetsbase = "";
    }
    if (param.optional && !param.isPointer) {
      mainType += " | nullptr_t";
    }
    return `  ${param.name}${
      param.optional && param.isPointer ? "?" : ""
    }: ${mainType}${
      ptypetsbase.length > 0 ? ` | ${ptypetsbase}` : ""
    } | Membuf`;
  });

  let returnType = "void";
  if (cmd.successCodes.length > 0 || cmd.errorCodes.length > 0) {
    returnType = [...cmd.successCodes, ...cmd.errorCodes]
      .filter(
        (x) =>
          !!enums.find(
            (z) => z.name === "VkResult" && z.entries.find((y) => y.key === x)
          )
      )
      .map((x) => `VkResult.${x}`)
      .join(" | ");
  }

  return `export interface ${cmd.name}InputWithDevice {
${paramsWithDevice.join(";\n")};
}
export interface ${cmd.name}InputWithInstance {
${paramsWithInstance.join(";\n")};
}

const ${cmd.name}ParamsTypes = ${JSON.stringify(
    Object.fromEntries(
      cmd.params.map((p) => [
        p.name,
        {
          simple: simplifyTypeNative(p.type),
          isPointer: p.isPointer,
        },
      ])
    )
  )} as const;
export const ${cmd.name} = (input: ${cmd.name}InputWithDevice | ${
    cmd.name
  }InputWithInstance): ${returnType} => {
   // const lastAllocationId = getMembufScratchBuffer().lastAllocationId;
    const transformed = Object.fromEntries(Object.entries(input).map((e) => {
        return [e[0], transformParameter(e[1], ${
          cmd.name
        }ParamsTypes[e[0] as keyof typeof ${cmd.name}ParamsTypes])];
    }));
    const result = vsnative.vts_native_${cmd.name}(transformed);
    //getMembufScratchBuffer().revertToAllocationId(lastAllocationId);
    return result;
}`;
};

const generateStructs = (): string[] => {
  const lines: string[] = [];
  for (const struct of structs) {
    const line = `export interface ${
      struct.name
    }Deserialized {\n${struct.members
      .filter((p) => p.name !== "sType")
      .map((p: any) => {
        let ptype = simplifyTypeTS(p.type);
        let ptypetsbase = simplifyTypeTSBaseTypes(ptype);
        if (p.type === "char" && !p.isPointer && !p.isDoublePointer) {
          ptype = "string";
        } else if (p.type === "char" && p.isPointer && !p.isDoublePointer) {
          ptype = "string";
        } else if (p.type === "char" && p.isPointer && p.isDoublePointer) {
          ptype = "string[]";
        } else if (p.type === "VkBool32") {
          ptypetsbase = "boolean";
        } else if (ptype.startsWith("Vk") && !p.isPointer) {
          ptype += "Deserialized[]";
          ptypetsbase = "";
        } else if (ptype.startsWith("Vk")) {
          ptype += "Deserialized";
        }

        return `    ${p.name}${p.optional ? "?" : ""}: ${
          ptypetsbase.length > 0 ? ptypetsbase : ptype
        }`;
      })
      .join(";\n")}\n}`;
    lines.push(line);
  }
  for (const struct of structs) {
    const line = `export interface ${struct.name}Input {\n${struct.members
      .filter((p) => p.name !== "sType")
      .map((p: any) => {
        let ptype = simplifyTypeTS(p.type);
        let ptypetsbase = simplifyTypeTSBaseTypes(ptype);
        if (p.type === "char" && p.isPointer && !p.isDoublePointer) {
          ptype = "string";
        } else if (p.type === "char" && p.isPointer && p.isDoublePointer) {
          ptype = "string[]";
        } else if (p.type === "VkBool32") {
          ptypetsbase = "boolean";
        } else if (ptype.startsWith("Vk") && !p.isPointer) {
          ptype += "[]";
          ptypetsbase = "";
        } else if (p.isPointer && p.len.length > 0) {
          ptype += "[] | null";
          ptypetsbase = "";
        } else if (p.isPointer && p.len.length === 0) {
          ptype += "| null";
          ptypetsbase = "";
        } else if (p.isArray) {
          ptype += "[] | null";
          ptypetsbase = "";
        }
        return `    ${p.name}${p.optional ? "?" : ""}: ${ptype}${
          ptypetsbase.length > 0 ? ` | ${ptypetsbase}` : ""
        } | Membuf`;
      })
      .join(";\n")}\n}`;
    lines.push(line);
  }
  for (const struct of structs) {
    const line = `export class ${struct.name} extends VkSerializable<${struct.name}Input, ${struct.name}Deserialized> {
        public constructor(data: ${struct.name}Input){ super(data, "${struct.name}"); }
    }`;
    lines.push(line);
  }
  for (const struct of structs) {
    const line = `export const getEmpty${struct.name} = (): Membuf => {
  const buf = new Membuf(getStructSize("${struct.name}"));
  buf.underlyingType = "${struct.name}";
  return buf;
};`;
    lines.push(line);
  }
  for (const struct of structs) {
    const line = `export const getEmpty${struct.name}Array = (count: number): Membuf[] => {const res = initArray(count, () => {
  const buf = new Membuf(getStructSize("${struct.name}"));
  buf.underlyingType = "${struct.name}";
  return buf;
}); BaseMembuf.reallocateIntoContinuousMemory(res); return res; }`;
    lines.push(line);
  }
  return lines;
};

export function generateDistTs(tsPath: string): void {
  const outFileDistTS = `
${distTsHeaders}

${types.handleTypeNames
  .filter((x) => !!x)
  .map((handle) => {
    return `export class ${handle} extends ${
      handlesSize === "32" ? "uint32_t" : "uint64_t"
    } {}`;
  })
  .join("\n")}

${constants
  .map((con) => {
    const maxnumber = Math.pow(2, 53);
    if (con.value > maxnumber) {
      return `export const ${con.name} = ${con.value.toString()}n;`;
    } else {
      return `export const ${con.name} = ${con.value.toString()};`;
    }
  })
  .join("\n")}

// bitmasks
${bitmasks
  .map((bm) => {
    return bm.bits
      .map((b) => {
        if (b.value !== null) {
          return `export const ${b.name} = ${
            bm.bitWidth === 32 ? b.value : `BigInt(${b.value})`
          };`;
        } else {
          return `export const ${b.name} = ${
            bm.bitWidth === 32
              ? `0x1 << ${b.bitpos}`
              : `BigInt(1n << ${b.bitpos}n)`
          };`;
        }
      })
      .join("\n");
  })
  .join("\n")}

${bitmasks
  .filter((bm) => bm.bitWidth === 32)
  .map((bm) => {
    return [
      `export enum ${bm.name}{`,
      ...bm.bits.map((b) => {
        if (b.value !== null) {
          return `  ${b.name} = ${b.value},`;
        } else {
          return `  ${b.name} = 0x1 << ${b.bitpos},`;
        }
      }),
      "}",
    ].join("\n");
  })
  .join("\n")}

// enums
${enums
  .map((en) => {
    return en.entries
      .filter((b) => b.value !== undefined)
      .map((e) => {
        return `export const ${e.key} = ${e.value};`;
      })
      .join("\n");
  })
  .join("\n")}

${enums
  .map((en) => {
    return [
      `export enum ${en.name}{`,
      ...en.entries
        .filter((b) => b.value !== undefined)
        .map((e) => {
          return `  ${e.key} = ${e.value},`;
        }),
      "}",
    ].join("\n");
  })
  .join("\n")}

${generateStructs().join("\n")}
    ${commands.map((c) => generateOneCallTS(c)).join("\n")}
`;

  fs.writeFileSync(tsPath, outFileDistTS);
}
