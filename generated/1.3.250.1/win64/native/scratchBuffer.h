
uint8_t* scratchBuffer = new uint8_t[1024 * 1024 * 64];

Napi::Value vts_native_getScratchBuffer(const Napi::CallbackInfo& info) {
    return Napi::ArrayBuffer::New(info.Env(), scratchBuffer, 1024 * 1024 * 64);
};

Napi::Value vts_native_getAddressAtScratchBufferOffset(const Napi::CallbackInfo& info) {
    uint32_t offset = info[0].As<Napi::Number>().Uint32Value();
    return Napi::BigInt::New(info.Env(), (uint64_t)&scratchBuffer[offset]);
};

Napi::Value vts_native_memsetScratchBufferSlice(const Napi::CallbackInfo& info) {
    uint32_t offset = info[0].As<Napi::Number>().Uint32Value();
    uint32_t srcStart = info[1].As<Napi::Number>().Uint32Value();
    uint32_t size = info[2].As<Napi::Number>().Uint32Value();
    void * input = (void*)&((uint8_t*)info[3].As<Napi::ArrayBuffer>().Data())[srcStart];
    memcpy((void*)&scratchBuffer[offset], input, size);
    return info.Env().Undefined();
};

Napi::Value vts_native_memsetScratchBufferMove(const Napi::CallbackInfo& info) {
    uint32_t from = info[0].As<Napi::Number>().Uint32Value();
    uint32_t to = info[1].As<Napi::Number>().Uint32Value();
    uint32_t size = info[2].As<Napi::Number>().Uint32Value();
    memcpy((void*)&scratchBuffer[to], (void*)&scratchBuffer[from], size);
    return info.Env().Undefined();
};

Napi::Value vts_native_memsetScratchBufferZero(const Napi::CallbackInfo& info) {
    uint32_t offset = info[0].As<Napi::Number>().Uint32Value();
    uint32_t size = info[1].As<Napi::Number>().Uint32Value();
    memset((void*)&scratchBuffer[offset], 0, size);
    return info.Env().Undefined();
};

Napi::Value vts_native_memcpyArrayBuffers(const Napi::CallbackInfo& info) {
    void * src = (void*)&((uint8_t*)info[0].As<Napi::ArrayBuffer>().Data())[info[1].As<Napi::Number>().Uint32Value()];
    void * dst = (void*)&((uint8_t*)info[2].As<Napi::ArrayBuffer>().Data())[info[3].As<Napi::Number>().Uint32Value()];
    uint32_t size = info[4].As<Napi::Number>().Uint32Value();
    memcpy(dst, src, size);
    return info.Env().Undefined();
};
