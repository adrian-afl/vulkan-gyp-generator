
static Napi::Value getAddressFromArrayBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::ArrayBuffer buffer = info[0].As<Napi::ArrayBuffer>();
  int64_t ptrval = reinterpret_cast<int64_t>(buffer.Data());

  uint8_t* heh = new uint8_t[8];
  memcpy((void*)heh, &ptrval, 8);

  return Napi::ArrayBuffer::New(env, heh, 8);
};

static Napi::Value getArrayBufferFromAddress(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::ArrayBuffer ptrbuffer = info[0].As<Napi::ArrayBuffer>();
  int64_t ptrval = ((int64_t*)ptrbuffer.Data())[0];
  void* ptr = (void*) ptrval;

  Napi::Number size = info[1].As<Napi::Number>();

  Napi::ArrayBuffer buffer = Napi::ArrayBuffer::New(
    env,
    reinterpret_cast<void *>(ptr),
      size.Int64Value()
  );
  return buffer;
};
