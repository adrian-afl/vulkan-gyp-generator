import { VulkanCommand } from "../specParsers/commands";
import { VulkanStruct } from "../specParsers/structs";
import * as fs from "fs";
import { commands, structs } from "../cli";

const generateOneNativeBinding = (cmd: VulkanCommand): string => {
  return `exports["vts_native_${cmd.name}"] = Napi::Function::New(env, vts_native_${cmd.name}, "vts_native_${cmd.name}");`;
};

const generateOneSTypeBinding = (strcty: VulkanStruct): string => {
  const stype = strcty.members.find((a) => a.name === "sType");
  if (!stype || !stype.values) {
    return "";
  }
  return `sTypes.Set("${strcty.name}", Napi::Number::New(env, ${stype.values}));\n`;
};

export function generateInitH(hPath: string): void {
  const initH = `Napi::Object Init(Napi::Env env, Napi::Object exports) {
    prepareAlignmentData();
    VulkanWindow::Initialize(env, exports);
    exports["getMemoryAlignment"] = Napi::Function::New(env, getMemoryAlignment, "getMemoryAlignment");
    exports["allocateString"] = Napi::Function::New(env, allocateString, "allocateString");
    exports["allocateStrings"] = Napi::Function::New(env, allocateStrings, "allocateStrings");

    exports["VK_MAKE_VERSION"] = Napi::Function::New(env, _VK_MAKE_VERSION, "VK_MAKE_VERSION");
    exports["VK_VERSION_MAJOR"] = Napi::Function::New(env, _VK_VERSION_MAJOR, "VK_VERSION_MAJOR");
    exports["VK_VERSION_MINOR"] = Napi::Function::New(env, _VK_VERSION_MINOR, "VK_VERSION_MINOR");
    exports["VK_VERSION_PATCH"] = Napi::Function::New(env, _VK_VERSION_PATCH, "VK_VERSION_PATCH");
    exports["VK_API_VERSION_1_0"] = Napi::Number::New(env, VK_MAKE_VERSION(1, 0, 0));
    exports["VK_API_VERSION_1_1"] = Napi::Number::New(env, VK_MAKE_VERSION(1, 1, 0));
    exports["VK_API_VERSION_1_2"] = Napi::Number::New(env, VK_MAKE_VERSION(1, 2, 0));
    exports["VK_API_VERSION_1_3"] = Napi::Number::New(env, VK_MAKE_VERSION(1, 3, 0));

    exports["vts_native_vkMapMemoryToArrayBuffer"] = Napi::Function::New(env, vts_native_vkMapMemoryToArrayBuffer, "vts_native_vkMapMemoryToArrayBuffer");
    exports["vts_native_setupDebugCallback"] = Napi::Function::New(env, vts_native_setupDebugCallback, "vts_native_setupDebugCallback");
    exports["getScratchBuffer"] = Napi::Function::New(env, vts_native_getScratchBuffer, "vts_native_getScratchBuffer");
    exports["getAddressAtScratchBufferOffset"] = Napi::Function::New(env, vts_native_getAddressAtScratchBufferOffset, "vts_native_getAddressAtScratchBufferOffset");
    exports["memsetScratchBufferSlice"] = Napi::Function::New(env, vts_native_memsetScratchBufferSlice, "vts_native_memsetScratchBufferSlice");
    exports["memsetScratchBufferMove"] = Napi::Function::New(env, vts_native_memsetScratchBufferMove, "vts_native_memsetScratchBufferMove");
    exports["memsetScratchBufferZero"] = Napi::Function::New(env, vts_native_memsetScratchBufferZero, "vts_native_memsetScratchBufferZero");
    exports["memcpyArrayBuffers"] = Napi::Function::New(env, vts_native_memcpyArrayBuffers, "vts_native_memcpyArrayBuffers");

${commands.map((c) => generateOneNativeBinding(c)).join("\n")}
    Napi::Object sTypes = Napi::Object::New(env);
${structs.map((c) => generateOneSTypeBinding(c)).join("")}
    exports["sTypes"] = sTypes;

    return exports;
}\n`;
  fs.writeFileSync(hPath, initH);
}
