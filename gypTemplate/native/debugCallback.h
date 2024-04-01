VkDebugUtilsMessengerEXT debugMessenger;
Napi::FunctionReference* debugMessengerNapiFunction = new Napi::FunctionReference[1];
bool debugFnSet = false;

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) {

    if(debugFnSet){
      Napi::Value recv = Napi::Object::New(debugMessengerNapiFunction->Env());
      debugMessengerNapiFunction->MakeCallback(recv, { Napi::String::New(debugMessengerNapiFunction->Env(), pCallbackData->pMessage) }, nullptr);
    }
    else {
      std::cout << "validation layer: " << pCallbackData->pMessage << std::endl;
    }

    return VK_FALSE;
}

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

