import { VulkanCommand } from "../specParsers/commands";
import * as fs from "fs";
import {
  types,
  commands,
  findBitmask,
  findEnum,
  simplifyTypeNative,
  manualTypesMapNative,
} from "../cli";

const generateOneCallNative = (cmd: VulkanCommand): string => {
  // HERE, check for type of value
  // if number, its offset into scratch buffer which then becomes void*
  // if bigint its directly converted into uint64_t then casted into void *
  // if null or undefined, vk null handle
  // if
  const params = cmd.params.map((param, i) => {
    if (param.optional) {
      return `  void * p${i} = input.Has("${param.name}") ? resolveNapiValueAddress(input.Get("${param.name}")) : nullptr;`;
    } else {
      return `  void * p${i} = resolveNapiValueAddress(input.Get("${param.name}"));`;
    }
  });
  const callLines = cmd.params.map((param, i) => {
    const isPointerOrArray = param.isPointer || param.isArray;
    const isenum = findEnum(param.type);
    const isbitmask =
      findBitmask(param.type) ??
      findBitmask(param.type.replace("FlagBits", "Flags"));
    const isOrphanedBitmaskType =
      !isbitmask && types.bitmaskTypeNames.includes(param.type);
    const isvoidptr =
      param.type === "void" && isPointerOrArray && !param.isDoublePointer;
    const isvoiddoubleptr =
      param.type === "void" && isPointerOrArray && param.isDoublePointer;
    const isplain =
      [
        "uint32_t",
        "uint64_t",
        "int32_t",
        "int64_t",
        "uint8_t",
        "uint16_t",
        "char",
        "size_t",
        "float",
        "double",
        ...Object.keys(manualTypesMapNative),
      ].includes(param.type) && !isPointerOrArray;
    if (isenum && !isPointerOrArray) {
      return `    (${param.type})(((int32_t*)p${i})[0])`;
    } else if (isvoidptr) {
      return `    &p${i}`;
    } else if (isvoiddoubleptr) {
      return `    &p${i}`;
    } else if (isplain) {
      return `    (${param.type})(((${param.type}*)p${i})[0])`;
    } else if (isbitmask && !isPointerOrArray) {
      return `    (${param.type})(((uint${isbitmask.bitWidth}_t*)p${i})[0])`;
    } else if (isOrphanedBitmaskType && !isPointerOrArray) {
      return `    (${param.type})(((uint32_t*)p${i})[0])`;
    } else {
      if (isPointerOrArray) {
        return `    reinterpret_cast<${param.modifiers.join(" ")} ${
          param.type
        } *>(p${i})`;
      } else {
        return `    reinterpret_cast<${param.modifiers.join(" ")} ${
          param.type
        } *>(p${i})[0]`;
      }
    }
  });

  const typeSimplifiedWithoutFns = simplifyTypeNative(cmd.returnType, false);
  const typeSimplifiedWitFns = simplifyTypeNative(cmd.returnType, true);
  const returncast =
    typeSimplifiedWithoutFns === typeSimplifiedWitFns
      ? "out"
      : `reinterpret_cast<${typeSimplifiedWitFns}>(out)`;

  return `Napi::Value vts_native_${cmd.name}(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
${params.join("\n")}
  auto XF = (PFN_${cmd.name}) vkGetInstanceProcAddr(NULL, "${cmd.name}");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_${cmd.name}) vkGetInstanceProcAddr(inst, "${cmd.name}");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_${cmd.name}) vkGetDeviceProcAddr(dev, "${cmd.name}");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function ${cmd.name}");
    throw "cannot find function ${cmd.name}";
  }

  ${cmd.returnType === "void" ? "" : `${typeSimplifiedWithoutFns} out = `}XF(
${callLines.join(",\n")}
  );

${
  cmd.returnType === "void"
    ? "  return Napi::Number::New(env, 1);"
    : `  return Napi::Number::New(env, ${returncast});`
}
};`;
};

export function generateCommandsH(hPath: string): void {
  const nativecallsString = commands.map((c) => generateOneCallNative(c));
  fs.writeFileSync(hPath, nativecallsString.join("\n"));
}
