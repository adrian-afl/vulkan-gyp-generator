void* resolveNapiValueAddress(Napi::Value value) {
  if (value.IsNull() || value.IsUndefined()) {
    return nullptr;
  }
  if (value.IsBigInt()) {
    bool loseless = true;
    return (void*)value.As<Napi::BigInt>().Uint64Value(&loseless);
  }
  if (value.IsNumber()) {
    return (void*)&scratchBuffer[value.As<Napi::Number>().Uint32Value()];
  }
  return nullptr;
}

Napi::Value _VK_MAKE_VERSION(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  uint32_t major = info[0].As<Napi::Number>().Uint32Value();
  uint32_t minor = info[1].As<Napi::Number>().Uint32Value();
  uint32_t patch = info[2].As<Napi::Number>().Uint32Value();
  return Napi::Number::New(env, VK_MAKE_VERSION(major, minor, patch));
};

Napi::Value _VK_VERSION_MAJOR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  uint32_t version = info[0].As<Napi::Number>().Uint32Value();
  return Napi::Number::New(env, (uint32_t)(version) >> 22);
};

Napi::Value _VK_VERSION_MINOR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  uint32_t version = info[0].As<Napi::Number>().Uint32Value();
  return Napi::Number::New(env, ((uint32_t)(version) >> 12) & 0x3ff);
};

Napi::Value _VK_VERSION_PATCH(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint32_t version = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, (uint32_t)(version) & 0xfff);
};

Napi::Value getMemoryAlignment(const Napi::CallbackInfo & info) {
    Napi::Env env = info.Env();
    return Napi::ArrayBuffer::New(env, alignmentData.data(), alignmentData.size() * sizeof(size_t), [](Napi::Env env, void* finalizeData) {
      delete[] static_cast<uint8_t*>(finalizeData);
    });
};
Napi::Value allocateString(const Napi::CallbackInfo & info) {
    Napi::Env env = info.Env();
    auto str = info[0].As<Napi::String>().Utf8Value();
    uint8_t* ptr = new uint8_t[str.size() + 1];
    memcpy((void*)ptr, str.c_str(), str.size() + 1);
    ptr[str.size()] = 0x0;

    return Napi::BigInt::New(env, (uint64_t)ptr);
};
Napi::Value allocateStrings(const Napi::CallbackInfo & info) {
    Napi::Env env = info.Env();
    auto arr = info[0].As<Napi::Array>();
    auto len = arr.Length();
    uint8_t** ptrptr = new uint8_t*[len];
    for(unsigned int i=0;i<len;i++){
        auto str = arr.Get(i).As<Napi::String>().Utf8Value();
        uint8_t* ptr = new uint8_t[str.size() + 1];
        memcpy((void*)ptr, str.c_str(), str.size() + 1);
        ptr[str.size()] = 0x0;
        ptrptr[i] = (uint8_t*)&ptr[0]; // ????
    }
    return Napi::BigInt::New(env, (uint64_t)ptrptr);
};

Napi::Value vts_native_setupDebugCallback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    void* p0 = resolveNapiValueAddress(info[0]);

    VkDebugUtilsMessengerCreateInfoEXT createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = debugCallback;

    debugMessengerNapiFunction[0] = Napi::Persistent(info[1].As<Napi::Function>());
    debugFnSet = true;

    if (CreateDebugUtilsMessengerEXT(reinterpret_cast<VkInstance*>(p0)[0], &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }
    return Napi::Number::New(env, 0);
};


Napi::Value vts_native_vkMapMemoryToArrayBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Object input = info[0].As<Napi::Object>();
    void * p0 = resolveNapiValueAddress(input.Get("device"));
    void * p1 = resolveNapiValueAddress(input.Get("memory"));
    void * p2 = resolveNapiValueAddress(input.Get("offset"));
    void * p3 = resolveNapiValueAddress(input.Get("size"));
    void * p4 = resolveNapiValueAddress(input.Get("flags"));

    void* pointer = nullptr;

    int32_t out = vkMapMemory(
        reinterpret_cast<VkDevice*>(p0)[0],
        reinterpret_cast<VkDeviceMemory*>(p1)[0],
        (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
        (VkDeviceSize)(((VkDeviceSize*)p3)[0]),
        (VkMemoryMapFlags)(((uint32_t*)p4)[0]),
        &pointer
    );

    return Napi::ArrayBuffer::New(env, pointer, (VkDeviceSize)(((VkDeviceSize*)p3)[0]));
};
