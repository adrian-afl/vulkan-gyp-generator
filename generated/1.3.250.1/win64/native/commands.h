Napi::Value vts_native_vkCreateInstance(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p1 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pInstance"));
  auto XF = (PFN_vkCreateInstance) vkGetInstanceProcAddr(NULL, "vkCreateInstance");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateInstance) vkGetInstanceProcAddr(inst, "vkCreateInstance");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateInstance) vkGetDeviceProcAddr(dev, "vkCreateInstance");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateInstance");
    throw "cannot find function vkCreateInstance";
  }

  int32_t out = XF(
    reinterpret_cast<const VkInstanceCreateInfo *>(p0),
    reinterpret_cast<const VkAllocationCallbacks *>(p1),
    reinterpret_cast< VkInstance *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyInstance(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = input.Has("instance") ? resolveNapiValueAddress(input.Get("instance")) : nullptr;
  void * p1 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyInstance) vkGetInstanceProcAddr(NULL, "vkDestroyInstance");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyInstance) vkGetInstanceProcAddr(inst, "vkDestroyInstance");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyInstance) vkGetDeviceProcAddr(dev, "vkDestroyInstance");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyInstance");
    throw "cannot find function vkDestroyInstance";
  }

  XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkEnumeratePhysicalDevices(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("instance"));
  void * p1 = resolveNapiValueAddress(input.Get("pPhysicalDeviceCount"));
  void * p2 = input.Has("pPhysicalDevices") ? resolveNapiValueAddress(input.Get("pPhysicalDevices")) : nullptr;
  auto XF = (PFN_vkEnumeratePhysicalDevices) vkGetInstanceProcAddr(NULL, "vkEnumeratePhysicalDevices");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumeratePhysicalDevices) vkGetInstanceProcAddr(inst, "vkEnumeratePhysicalDevices");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumeratePhysicalDevices) vkGetDeviceProcAddr(dev, "vkEnumeratePhysicalDevices");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumeratePhysicalDevices");
    throw "cannot find function vkEnumeratePhysicalDevices";
  }

  int32_t out = XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkPhysicalDevice *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceProcAddr(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pName"));
  auto XF = (PFN_vkGetDeviceProcAddr) vkGetInstanceProcAddr(NULL, "vkGetDeviceProcAddr");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceProcAddr) vkGetInstanceProcAddr(inst, "vkGetDeviceProcAddr");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceProcAddr) vkGetDeviceProcAddr(dev, "vkGetDeviceProcAddr");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceProcAddr");
    throw "cannot find function vkGetDeviceProcAddr";
  }

  PFN_vkVoidFunction out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const char *>(p1)
  );

  return Napi::Number::New(env, reinterpret_cast<uint64_t>(out));
};
Napi::Value vts_native_vkGetInstanceProcAddr(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = input.Has("instance") ? resolveNapiValueAddress(input.Get("instance")) : nullptr;
  void * p1 = resolveNapiValueAddress(input.Get("pName"));
  auto XF = (PFN_vkGetInstanceProcAddr) vkGetInstanceProcAddr(NULL, "vkGetInstanceProcAddr");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetInstanceProcAddr) vkGetInstanceProcAddr(inst, "vkGetInstanceProcAddr");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetInstanceProcAddr) vkGetDeviceProcAddr(dev, "vkGetInstanceProcAddr");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetInstanceProcAddr");
    throw "cannot find function vkGetInstanceProcAddr";
  }

  PFN_vkVoidFunction out = XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast<const char *>(p1)
  );

  return Napi::Number::New(env, reinterpret_cast<uint64_t>(out));
};
Napi::Value vts_native_vkGetPhysicalDeviceProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceProperties");
    throw "cannot find function vkGetPhysicalDeviceProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceProperties *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceQueueFamilyProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pQueueFamilyPropertyCount"));
  void * p2 = input.Has("pQueueFamilyProperties") ? resolveNapiValueAddress(input.Get("pQueueFamilyProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceQueueFamilyProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceQueueFamilyProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceQueueFamilyProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceQueueFamilyProperties");
    throw "cannot find function vkGetPhysicalDeviceQueueFamilyProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkQueueFamilyProperties *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceMemoryProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pMemoryProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceMemoryProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceMemoryProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMemoryProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceMemoryProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMemoryProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceMemoryProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceMemoryProperties");
    throw "cannot find function vkGetPhysicalDeviceMemoryProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceMemoryProperties *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceFeatures(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pFeatures"));
  auto XF = (PFN_vkGetPhysicalDeviceFeatures) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceFeatures");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFeatures) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceFeatures");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFeatures) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceFeatures");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceFeatures");
    throw "cannot find function vkGetPhysicalDeviceFeatures";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceFeatures *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceFormatProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("format"));
  void * p2 = resolveNapiValueAddress(input.Get("pFormatProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceFormatProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceFormatProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFormatProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFormatProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceFormatProperties");
    throw "cannot find function vkGetPhysicalDeviceFormatProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (VkFormat)(((int32_t*)p1)[0]),
    reinterpret_cast< VkFormatProperties *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceImageFormatProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("format"));
  void * p2 = resolveNapiValueAddress(input.Get("type"));
  void * p3 = resolveNapiValueAddress(input.Get("tiling"));
  void * p4 = resolveNapiValueAddress(input.Get("usage"));
  void * p5 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  void * p6 = resolveNapiValueAddress(input.Get("pImageFormatProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceImageFormatProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceImageFormatProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceImageFormatProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceImageFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceImageFormatProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceImageFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceImageFormatProperties");
    throw "cannot find function vkGetPhysicalDeviceImageFormatProperties";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (VkFormat)(((int32_t*)p1)[0]),
    (VkImageType)(((int32_t*)p2)[0]),
    (VkImageTiling)(((int32_t*)p3)[0]),
    (VkImageUsageFlags)(((uint32_t*)p4)[0]),
    (VkImageCreateFlags)(((uint32_t*)p5)[0]),
    reinterpret_cast< VkImageFormatProperties *>(p6)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateDevice(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pDevice"));
  auto XF = (PFN_vkCreateDevice) vkGetInstanceProcAddr(NULL, "vkCreateDevice");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDevice) vkGetInstanceProcAddr(inst, "vkCreateDevice");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDevice) vkGetDeviceProcAddr(dev, "vkCreateDevice");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDevice");
    throw "cannot find function vkCreateDevice";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkDevice *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyDevice(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = input.Has("device") ? resolveNapiValueAddress(input.Get("device")) : nullptr;
  void * p1 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyDevice) vkGetInstanceProcAddr(NULL, "vkDestroyDevice");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyDevice) vkGetInstanceProcAddr(inst, "vkDestroyDevice");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyDevice) vkGetDeviceProcAddr(dev, "vkDestroyDevice");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyDevice");
    throw "cannot find function vkDestroyDevice";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkEnumerateInstanceVersion(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("pApiVersion"));
  auto XF = (PFN_vkEnumerateInstanceVersion) vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceVersion");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumerateInstanceVersion) vkGetInstanceProcAddr(inst, "vkEnumerateInstanceVersion");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumerateInstanceVersion) vkGetDeviceProcAddr(dev, "vkEnumerateInstanceVersion");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumerateInstanceVersion");
    throw "cannot find function vkEnumerateInstanceVersion";
  }

  int32_t out = XF(
    reinterpret_cast< uint32_t *>(p0)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkEnumerateInstanceLayerProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p1 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkEnumerateInstanceLayerProperties) vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceLayerProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumerateInstanceLayerProperties) vkGetInstanceProcAddr(inst, "vkEnumerateInstanceLayerProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumerateInstanceLayerProperties) vkGetDeviceProcAddr(dev, "vkEnumerateInstanceLayerProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumerateInstanceLayerProperties");
    throw "cannot find function vkEnumerateInstanceLayerProperties";
  }

  int32_t out = XF(
    reinterpret_cast< uint32_t *>(p0),
    reinterpret_cast< VkLayerProperties *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkEnumerateInstanceExtensionProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = input.Has("pLayerName") ? resolveNapiValueAddress(input.Get("pLayerName")) : nullptr;
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkEnumerateInstanceExtensionProperties) vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceExtensionProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumerateInstanceExtensionProperties) vkGetInstanceProcAddr(inst, "vkEnumerateInstanceExtensionProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumerateInstanceExtensionProperties) vkGetDeviceProcAddr(dev, "vkEnumerateInstanceExtensionProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumerateInstanceExtensionProperties");
    throw "cannot find function vkEnumerateInstanceExtensionProperties";
  }

  int32_t out = XF(
    reinterpret_cast<const char *>(p0),
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkExtensionProperties *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkEnumerateDeviceLayerProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkEnumerateDeviceLayerProperties) vkGetInstanceProcAddr(NULL, "vkEnumerateDeviceLayerProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumerateDeviceLayerProperties) vkGetInstanceProcAddr(inst, "vkEnumerateDeviceLayerProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumerateDeviceLayerProperties) vkGetDeviceProcAddr(dev, "vkEnumerateDeviceLayerProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumerateDeviceLayerProperties");
    throw "cannot find function vkEnumerateDeviceLayerProperties";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkLayerProperties *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkEnumerateDeviceExtensionProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = input.Has("pLayerName") ? resolveNapiValueAddress(input.Get("pLayerName")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p3 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkEnumerateDeviceExtensionProperties) vkGetInstanceProcAddr(NULL, "vkEnumerateDeviceExtensionProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumerateDeviceExtensionProperties) vkGetInstanceProcAddr(inst, "vkEnumerateDeviceExtensionProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumerateDeviceExtensionProperties) vkGetDeviceProcAddr(dev, "vkEnumerateDeviceExtensionProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumerateDeviceExtensionProperties");
    throw "cannot find function vkEnumerateDeviceExtensionProperties";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const char *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkExtensionProperties *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceQueue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("queueFamilyIndex"));
  void * p2 = resolveNapiValueAddress(input.Get("queueIndex"));
  void * p3 = resolveNapiValueAddress(input.Get("pQueue"));
  auto XF = (PFN_vkGetDeviceQueue) vkGetInstanceProcAddr(NULL, "vkGetDeviceQueue");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceQueue) vkGetInstanceProcAddr(inst, "vkGetDeviceQueue");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceQueue) vkGetDeviceProcAddr(dev, "vkGetDeviceQueue");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceQueue");
    throw "cannot find function vkGetDeviceQueue";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast< VkQueue *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkQueueSubmit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  void * p1 = input.Has("submitCount") ? resolveNapiValueAddress(input.Get("submitCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pSubmits"));
  void * p3 = input.Has("fence") ? resolveNapiValueAddress(input.Get("fence")) : nullptr;
  auto XF = (PFN_vkQueueSubmit) vkGetInstanceProcAddr(NULL, "vkQueueSubmit");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkQueueSubmit) vkGetInstanceProcAddr(inst, "vkQueueSubmit");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkQueueSubmit) vkGetDeviceProcAddr(dev, "vkQueueSubmit");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkQueueSubmit");
    throw "cannot find function vkQueueSubmit";
  }

  int32_t out = XF(
    reinterpret_cast< VkQueue *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkSubmitInfo *>(p2),
    reinterpret_cast< VkFence *>(p3)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkQueueWaitIdle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  auto XF = (PFN_vkQueueWaitIdle) vkGetInstanceProcAddr(NULL, "vkQueueWaitIdle");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkQueueWaitIdle) vkGetInstanceProcAddr(inst, "vkQueueWaitIdle");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkQueueWaitIdle) vkGetDeviceProcAddr(dev, "vkQueueWaitIdle");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkQueueWaitIdle");
    throw "cannot find function vkQueueWaitIdle";
  }

  int32_t out = XF(
    reinterpret_cast< VkQueue *>(p0)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDeviceWaitIdle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  auto XF = (PFN_vkDeviceWaitIdle) vkGetInstanceProcAddr(NULL, "vkDeviceWaitIdle");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDeviceWaitIdle) vkGetInstanceProcAddr(inst, "vkDeviceWaitIdle");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDeviceWaitIdle) vkGetDeviceProcAddr(dev, "vkDeviceWaitIdle");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDeviceWaitIdle");
    throw "cannot find function vkDeviceWaitIdle";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkAllocateMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pAllocateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pMemory"));
  auto XF = (PFN_vkAllocateMemory) vkGetInstanceProcAddr(NULL, "vkAllocateMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkAllocateMemory) vkGetInstanceProcAddr(inst, "vkAllocateMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkAllocateMemory) vkGetDeviceProcAddr(dev, "vkAllocateMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkAllocateMemory");
    throw "cannot find function vkAllocateMemory";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkMemoryAllocateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkDeviceMemory *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkFreeMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("memory") ? resolveNapiValueAddress(input.Get("memory")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkFreeMemory) vkGetInstanceProcAddr(NULL, "vkFreeMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkFreeMemory) vkGetInstanceProcAddr(inst, "vkFreeMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkFreeMemory) vkGetDeviceProcAddr(dev, "vkFreeMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkFreeMemory");
    throw "cannot find function vkFreeMemory";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceMemory *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkMapMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memory"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("size"));
  void * p4 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  void * p5 = resolveNapiValueAddress(input.Get("ppData"));
  auto XF = (PFN_vkMapMemory) vkGetInstanceProcAddr(NULL, "vkMapMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkMapMemory) vkGetInstanceProcAddr(inst, "vkMapMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkMapMemory) vkGetDeviceProcAddr(dev, "vkMapMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkMapMemory");
    throw "cannot find function vkMapMemory";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceMemory *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (VkDeviceSize)(((VkDeviceSize*)p3)[0]),
    (VkMemoryMapFlags)(((uint32_t*)p4)[0]),
    &p5
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkUnmapMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memory"));
  auto XF = (PFN_vkUnmapMemory) vkGetInstanceProcAddr(NULL, "vkUnmapMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkUnmapMemory) vkGetInstanceProcAddr(inst, "vkUnmapMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkUnmapMemory) vkGetDeviceProcAddr(dev, "vkUnmapMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkUnmapMemory");
    throw "cannot find function vkUnmapMemory";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceMemory *>(p1)[0]
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkFlushMappedMemoryRanges(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memoryRangeCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRanges"));
  auto XF = (PFN_vkFlushMappedMemoryRanges) vkGetInstanceProcAddr(NULL, "vkFlushMappedMemoryRanges");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkFlushMappedMemoryRanges) vkGetInstanceProcAddr(inst, "vkFlushMappedMemoryRanges");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkFlushMappedMemoryRanges) vkGetDeviceProcAddr(dev, "vkFlushMappedMemoryRanges");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkFlushMappedMemoryRanges");
    throw "cannot find function vkFlushMappedMemoryRanges";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkMappedMemoryRange *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkInvalidateMappedMemoryRanges(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memoryRangeCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRanges"));
  auto XF = (PFN_vkInvalidateMappedMemoryRanges) vkGetInstanceProcAddr(NULL, "vkInvalidateMappedMemoryRanges");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkInvalidateMappedMemoryRanges) vkGetInstanceProcAddr(inst, "vkInvalidateMappedMemoryRanges");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkInvalidateMappedMemoryRanges) vkGetDeviceProcAddr(dev, "vkInvalidateMappedMemoryRanges");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkInvalidateMappedMemoryRanges");
    throw "cannot find function vkInvalidateMappedMemoryRanges";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkMappedMemoryRange *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceMemoryCommitment(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memory"));
  void * p2 = resolveNapiValueAddress(input.Get("pCommittedMemoryInBytes"));
  auto XF = (PFN_vkGetDeviceMemoryCommitment) vkGetInstanceProcAddr(NULL, "vkGetDeviceMemoryCommitment");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceMemoryCommitment) vkGetInstanceProcAddr(inst, "vkGetDeviceMemoryCommitment");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceMemoryCommitment) vkGetDeviceProcAddr(dev, "vkGetDeviceMemoryCommitment");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceMemoryCommitment");
    throw "cannot find function vkGetDeviceMemoryCommitment";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceMemory *>(p1)[0],
    reinterpret_cast< VkDeviceSize *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetBufferMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetBufferMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetBufferMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetBufferMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetBufferMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetBufferMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetBufferMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetBufferMemoryRequirements");
    throw "cannot find function vkGetBufferMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    reinterpret_cast< VkMemoryRequirements *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkBindBufferMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("memory"));
  void * p3 = resolveNapiValueAddress(input.Get("memoryOffset"));
  auto XF = (PFN_vkBindBufferMemory) vkGetInstanceProcAddr(NULL, "vkBindBufferMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBindBufferMemory) vkGetInstanceProcAddr(inst, "vkBindBufferMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBindBufferMemory) vkGetDeviceProcAddr(dev, "vkBindBufferMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBindBufferMemory");
    throw "cannot find function vkBindBufferMemory";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    reinterpret_cast< VkDeviceMemory *>(p2)[0],
    (VkDeviceSize)(((VkDeviceSize*)p3)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetImageMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetImageMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetImageMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetImageMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetImageMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageMemoryRequirements");
    throw "cannot find function vkGetImageMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast< VkMemoryRequirements *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkBindImageMemory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("memory"));
  void * p3 = resolveNapiValueAddress(input.Get("memoryOffset"));
  auto XF = (PFN_vkBindImageMemory) vkGetInstanceProcAddr(NULL, "vkBindImageMemory");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBindImageMemory) vkGetInstanceProcAddr(inst, "vkBindImageMemory");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBindImageMemory) vkGetDeviceProcAddr(dev, "vkBindImageMemory");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBindImageMemory");
    throw "cannot find function vkBindImageMemory";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast< VkDeviceMemory *>(p2)[0],
    (VkDeviceSize)(((VkDeviceSize*)p3)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("pSparseMemoryRequirementCount"));
  void * p3 = input.Has("pSparseMemoryRequirements") ? resolveNapiValueAddress(input.Get("pSparseMemoryRequirements")) : nullptr;
  auto XF = (PFN_vkGetImageSparseMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetImageSparseMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageSparseMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetImageSparseMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageSparseMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetImageSparseMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageSparseMemoryRequirements");
    throw "cannot find function vkGetImageSparseMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSparseImageMemoryRequirements *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceSparseImageFormatProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("format"));
  void * p2 = resolveNapiValueAddress(input.Get("type"));
  void * p3 = resolveNapiValueAddress(input.Get("samples"));
  void * p4 = resolveNapiValueAddress(input.Get("usage"));
  void * p5 = resolveNapiValueAddress(input.Get("tiling"));
  void * p6 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p7 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSparseImageFormatProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSparseImageFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSparseImageFormatProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSparseImageFormatProperties");
    throw "cannot find function vkGetPhysicalDeviceSparseImageFormatProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (VkFormat)(((int32_t*)p1)[0]),
    (VkImageType)(((int32_t*)p2)[0]),
    (VkSampleCountFlagBits)(((uint32_t*)p3)[0]),
    (VkImageUsageFlags)(((uint32_t*)p4)[0]),
    (VkImageTiling)(((int32_t*)p5)[0]),
    reinterpret_cast< uint32_t *>(p6),
    reinterpret_cast< VkSparseImageFormatProperties *>(p7)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkQueueBindSparse(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  void * p1 = input.Has("bindInfoCount") ? resolveNapiValueAddress(input.Get("bindInfoCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pBindInfo"));
  void * p3 = input.Has("fence") ? resolveNapiValueAddress(input.Get("fence")) : nullptr;
  auto XF = (PFN_vkQueueBindSparse) vkGetInstanceProcAddr(NULL, "vkQueueBindSparse");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkQueueBindSparse) vkGetInstanceProcAddr(inst, "vkQueueBindSparse");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkQueueBindSparse) vkGetDeviceProcAddr(dev, "vkQueueBindSparse");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkQueueBindSparse");
    throw "cannot find function vkQueueBindSparse";
  }

  int32_t out = XF(
    reinterpret_cast< VkQueue *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkBindSparseInfo *>(p2),
    reinterpret_cast< VkFence *>(p3)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateFence(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pFence"));
  auto XF = (PFN_vkCreateFence) vkGetInstanceProcAddr(NULL, "vkCreateFence");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateFence) vkGetInstanceProcAddr(inst, "vkCreateFence");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateFence) vkGetDeviceProcAddr(dev, "vkCreateFence");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateFence");
    throw "cannot find function vkCreateFence";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkFenceCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkFence *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyFence(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("fence") ? resolveNapiValueAddress(input.Get("fence")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyFence) vkGetInstanceProcAddr(NULL, "vkDestroyFence");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyFence) vkGetInstanceProcAddr(inst, "vkDestroyFence");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyFence) vkGetDeviceProcAddr(dev, "vkDestroyFence");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyFence");
    throw "cannot find function vkDestroyFence";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkFence *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkResetFences(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("fenceCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pFences"));
  auto XF = (PFN_vkResetFences) vkGetInstanceProcAddr(NULL, "vkResetFences");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetFences) vkGetInstanceProcAddr(inst, "vkResetFences");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetFences) vkGetDeviceProcAddr(dev, "vkResetFences");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetFences");
    throw "cannot find function vkResetFences";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkFence *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetFenceStatus(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("fence"));
  auto XF = (PFN_vkGetFenceStatus) vkGetInstanceProcAddr(NULL, "vkGetFenceStatus");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetFenceStatus) vkGetInstanceProcAddr(inst, "vkGetFenceStatus");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetFenceStatus) vkGetDeviceProcAddr(dev, "vkGetFenceStatus");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetFenceStatus");
    throw "cannot find function vkGetFenceStatus";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkFence *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkWaitForFences(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("fenceCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pFences"));
  void * p3 = resolveNapiValueAddress(input.Get("waitAll"));
  void * p4 = resolveNapiValueAddress(input.Get("timeout"));
  auto XF = (PFN_vkWaitForFences) vkGetInstanceProcAddr(NULL, "vkWaitForFences");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkWaitForFences) vkGetInstanceProcAddr(inst, "vkWaitForFences");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkWaitForFences) vkGetDeviceProcAddr(dev, "vkWaitForFences");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkWaitForFences");
    throw "cannot find function vkWaitForFences";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkFence *>(p2),
    (VkBool32)(((VkBool32*)p3)[0]),
    (uint64_t)(((uint64_t*)p4)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateSemaphore(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSemaphore"));
  auto XF = (PFN_vkCreateSemaphore) vkGetInstanceProcAddr(NULL, "vkCreateSemaphore");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateSemaphore) vkGetInstanceProcAddr(inst, "vkCreateSemaphore");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateSemaphore) vkGetDeviceProcAddr(dev, "vkCreateSemaphore");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateSemaphore");
    throw "cannot find function vkCreateSemaphore";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSemaphoreCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSemaphore *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroySemaphore(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("semaphore") ? resolveNapiValueAddress(input.Get("semaphore")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroySemaphore) vkGetInstanceProcAddr(NULL, "vkDestroySemaphore");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroySemaphore) vkGetInstanceProcAddr(inst, "vkDestroySemaphore");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroySemaphore) vkGetDeviceProcAddr(dev, "vkDestroySemaphore");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroySemaphore");
    throw "cannot find function vkDestroySemaphore";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSemaphore *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pEvent"));
  auto XF = (PFN_vkCreateEvent) vkGetInstanceProcAddr(NULL, "vkCreateEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateEvent) vkGetInstanceProcAddr(inst, "vkCreateEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateEvent) vkGetDeviceProcAddr(dev, "vkCreateEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateEvent");
    throw "cannot find function vkCreateEvent";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkEventCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkEvent *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("event") ? resolveNapiValueAddress(input.Get("event")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyEvent) vkGetInstanceProcAddr(NULL, "vkDestroyEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyEvent) vkGetInstanceProcAddr(inst, "vkDestroyEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyEvent) vkGetDeviceProcAddr(dev, "vkDestroyEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyEvent");
    throw "cannot find function vkDestroyEvent";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetEventStatus(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  auto XF = (PFN_vkGetEventStatus) vkGetInstanceProcAddr(NULL, "vkGetEventStatus");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetEventStatus) vkGetInstanceProcAddr(inst, "vkGetEventStatus");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetEventStatus) vkGetDeviceProcAddr(dev, "vkGetEventStatus");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetEventStatus");
    throw "cannot find function vkGetEventStatus";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkSetEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  auto XF = (PFN_vkSetEvent) vkGetInstanceProcAddr(NULL, "vkSetEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkSetEvent) vkGetInstanceProcAddr(inst, "vkSetEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkSetEvent) vkGetDeviceProcAddr(dev, "vkSetEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkSetEvent");
    throw "cannot find function vkSetEvent";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkResetEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  auto XF = (PFN_vkResetEvent) vkGetInstanceProcAddr(NULL, "vkResetEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetEvent) vkGetInstanceProcAddr(inst, "vkResetEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetEvent) vkGetDeviceProcAddr(dev, "vkResetEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetEvent");
    throw "cannot find function vkResetEvent";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateQueryPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pQueryPool"));
  auto XF = (PFN_vkCreateQueryPool) vkGetInstanceProcAddr(NULL, "vkCreateQueryPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateQueryPool) vkGetInstanceProcAddr(inst, "vkCreateQueryPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateQueryPool) vkGetDeviceProcAddr(dev, "vkCreateQueryPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateQueryPool");
    throw "cannot find function vkCreateQueryPool";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkQueryPoolCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkQueryPool *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyQueryPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("queryPool") ? resolveNapiValueAddress(input.Get("queryPool")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyQueryPool) vkGetInstanceProcAddr(NULL, "vkDestroyQueryPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyQueryPool) vkGetInstanceProcAddr(inst, "vkDestroyQueryPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyQueryPool) vkGetDeviceProcAddr(dev, "vkDestroyQueryPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyQueryPool");
    throw "cannot find function vkDestroyQueryPool";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetQueryPoolResults(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("firstQuery"));
  void * p3 = resolveNapiValueAddress(input.Get("queryCount"));
  void * p4 = resolveNapiValueAddress(input.Get("dataSize"));
  void * p5 = resolveNapiValueAddress(input.Get("pData"));
  void * p6 = resolveNapiValueAddress(input.Get("stride"));
  void * p7 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkGetQueryPoolResults) vkGetInstanceProcAddr(NULL, "vkGetQueryPoolResults");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetQueryPoolResults) vkGetInstanceProcAddr(inst, "vkGetQueryPoolResults");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetQueryPoolResults) vkGetDeviceProcAddr(dev, "vkGetQueryPoolResults");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetQueryPoolResults");
    throw "cannot find function vkGetQueryPoolResults";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (size_t)(((size_t*)p4)[0]),
    &p5,
    (VkDeviceSize)(((VkDeviceSize*)p6)[0]),
    (VkQueryResultFlags)(((uint32_t*)p7)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkResetQueryPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("firstQuery"));
  void * p3 = resolveNapiValueAddress(input.Get("queryCount"));
  auto XF = (PFN_vkResetQueryPool) vkGetInstanceProcAddr(NULL, "vkResetQueryPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetQueryPool) vkGetInstanceProcAddr(inst, "vkResetQueryPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetQueryPool) vkGetDeviceProcAddr(dev, "vkResetQueryPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetQueryPool");
    throw "cannot find function vkResetQueryPool";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pBuffer"));
  auto XF = (PFN_vkCreateBuffer) vkGetInstanceProcAddr(NULL, "vkCreateBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateBuffer) vkGetInstanceProcAddr(inst, "vkCreateBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateBuffer) vkGetDeviceProcAddr(dev, "vkCreateBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateBuffer");
    throw "cannot find function vkCreateBuffer";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkBufferCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkBuffer *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("buffer") ? resolveNapiValueAddress(input.Get("buffer")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyBuffer) vkGetInstanceProcAddr(NULL, "vkDestroyBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyBuffer) vkGetInstanceProcAddr(inst, "vkDestroyBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyBuffer) vkGetDeviceProcAddr(dev, "vkDestroyBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyBuffer");
    throw "cannot find function vkDestroyBuffer";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateBufferView(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pView"));
  auto XF = (PFN_vkCreateBufferView) vkGetInstanceProcAddr(NULL, "vkCreateBufferView");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateBufferView) vkGetInstanceProcAddr(inst, "vkCreateBufferView");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateBufferView) vkGetDeviceProcAddr(dev, "vkCreateBufferView");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateBufferView");
    throw "cannot find function vkCreateBufferView";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkBufferViewCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkBufferView *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyBufferView(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("bufferView") ? resolveNapiValueAddress(input.Get("bufferView")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyBufferView) vkGetInstanceProcAddr(NULL, "vkDestroyBufferView");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyBufferView) vkGetInstanceProcAddr(inst, "vkDestroyBufferView");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyBufferView) vkGetDeviceProcAddr(dev, "vkDestroyBufferView");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyBufferView");
    throw "cannot find function vkDestroyBufferView";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkBufferView *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pImage"));
  auto XF = (PFN_vkCreateImage) vkGetInstanceProcAddr(NULL, "vkCreateImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateImage) vkGetInstanceProcAddr(inst, "vkCreateImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateImage) vkGetDeviceProcAddr(dev, "vkCreateImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateImage");
    throw "cannot find function vkCreateImage";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkImageCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkImage *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("image") ? resolveNapiValueAddress(input.Get("image")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyImage) vkGetInstanceProcAddr(NULL, "vkDestroyImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyImage) vkGetInstanceProcAddr(inst, "vkDestroyImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyImage) vkGetDeviceProcAddr(dev, "vkDestroyImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyImage");
    throw "cannot find function vkDestroyImage";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetImageSubresourceLayout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("pSubresource"));
  void * p3 = resolveNapiValueAddress(input.Get("pLayout"));
  auto XF = (PFN_vkGetImageSubresourceLayout) vkGetInstanceProcAddr(NULL, "vkGetImageSubresourceLayout");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageSubresourceLayout) vkGetInstanceProcAddr(inst, "vkGetImageSubresourceLayout");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageSubresourceLayout) vkGetDeviceProcAddr(dev, "vkGetImageSubresourceLayout");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageSubresourceLayout");
    throw "cannot find function vkGetImageSubresourceLayout";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast<const VkImageSubresource *>(p2),
    reinterpret_cast< VkSubresourceLayout *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateImageView(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pView"));
  auto XF = (PFN_vkCreateImageView) vkGetInstanceProcAddr(NULL, "vkCreateImageView");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateImageView) vkGetInstanceProcAddr(inst, "vkCreateImageView");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateImageView) vkGetDeviceProcAddr(dev, "vkCreateImageView");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateImageView");
    throw "cannot find function vkCreateImageView";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkImageViewCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkImageView *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyImageView(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("imageView") ? resolveNapiValueAddress(input.Get("imageView")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyImageView) vkGetInstanceProcAddr(NULL, "vkDestroyImageView");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyImageView) vkGetInstanceProcAddr(inst, "vkDestroyImageView");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyImageView) vkGetDeviceProcAddr(dev, "vkDestroyImageView");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyImageView");
    throw "cannot find function vkDestroyImageView";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImageView *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateShaderModule(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pShaderModule"));
  auto XF = (PFN_vkCreateShaderModule) vkGetInstanceProcAddr(NULL, "vkCreateShaderModule");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateShaderModule) vkGetInstanceProcAddr(inst, "vkCreateShaderModule");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateShaderModule) vkGetDeviceProcAddr(dev, "vkCreateShaderModule");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateShaderModule");
    throw "cannot find function vkCreateShaderModule";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkShaderModuleCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkShaderModule *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyShaderModule(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("shaderModule") ? resolveNapiValueAddress(input.Get("shaderModule")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyShaderModule) vkGetInstanceProcAddr(NULL, "vkDestroyShaderModule");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyShaderModule) vkGetInstanceProcAddr(inst, "vkDestroyShaderModule");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyShaderModule) vkGetDeviceProcAddr(dev, "vkDestroyShaderModule");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyShaderModule");
    throw "cannot find function vkDestroyShaderModule";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkShaderModule *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreatePipelineCache(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pPipelineCache"));
  auto XF = (PFN_vkCreatePipelineCache) vkGetInstanceProcAddr(NULL, "vkCreatePipelineCache");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreatePipelineCache) vkGetInstanceProcAddr(inst, "vkCreatePipelineCache");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreatePipelineCache) vkGetDeviceProcAddr(dev, "vkCreatePipelineCache");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreatePipelineCache");
    throw "cannot find function vkCreatePipelineCache";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkPipelineCacheCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkPipelineCache *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyPipelineCache(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pipelineCache") ? resolveNapiValueAddress(input.Get("pipelineCache")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyPipelineCache) vkGetInstanceProcAddr(NULL, "vkDestroyPipelineCache");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyPipelineCache) vkGetInstanceProcAddr(inst, "vkDestroyPipelineCache");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyPipelineCache) vkGetDeviceProcAddr(dev, "vkDestroyPipelineCache");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyPipelineCache");
    throw "cannot find function vkDestroyPipelineCache";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineCache *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPipelineCacheData(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineCache"));
  void * p2 = resolveNapiValueAddress(input.Get("pDataSize"));
  void * p3 = input.Has("pData") ? resolveNapiValueAddress(input.Get("pData")) : nullptr;
  auto XF = (PFN_vkGetPipelineCacheData) vkGetInstanceProcAddr(NULL, "vkGetPipelineCacheData");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPipelineCacheData) vkGetInstanceProcAddr(inst, "vkGetPipelineCacheData");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPipelineCacheData) vkGetDeviceProcAddr(dev, "vkGetPipelineCacheData");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPipelineCacheData");
    throw "cannot find function vkGetPipelineCacheData";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineCache *>(p1)[0],
    reinterpret_cast< size_t *>(p2),
    &p3
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkMergePipelineCaches(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("dstCache"));
  void * p2 = resolveNapiValueAddress(input.Get("srcCacheCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pSrcCaches"));
  auto XF = (PFN_vkMergePipelineCaches) vkGetInstanceProcAddr(NULL, "vkMergePipelineCaches");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkMergePipelineCaches) vkGetInstanceProcAddr(inst, "vkMergePipelineCaches");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkMergePipelineCaches) vkGetDeviceProcAddr(dev, "vkMergePipelineCaches");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkMergePipelineCaches");
    throw "cannot find function vkMergePipelineCaches";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineCache *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkPipelineCache *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateGraphicsPipelines(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pipelineCache") ? resolveNapiValueAddress(input.Get("pipelineCache")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("createInfoCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pCreateInfos"));
  void * p4 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p5 = resolveNapiValueAddress(input.Get("pPipelines"));
  auto XF = (PFN_vkCreateGraphicsPipelines) vkGetInstanceProcAddr(NULL, "vkCreateGraphicsPipelines");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateGraphicsPipelines) vkGetInstanceProcAddr(inst, "vkCreateGraphicsPipelines");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateGraphicsPipelines) vkGetDeviceProcAddr(dev, "vkCreateGraphicsPipelines");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateGraphicsPipelines");
    throw "cannot find function vkCreateGraphicsPipelines";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineCache *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkGraphicsPipelineCreateInfo *>(p3),
    reinterpret_cast<const VkAllocationCallbacks *>(p4),
    reinterpret_cast< VkPipeline *>(p5)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateComputePipelines(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pipelineCache") ? resolveNapiValueAddress(input.Get("pipelineCache")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("createInfoCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pCreateInfos"));
  void * p4 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p5 = resolveNapiValueAddress(input.Get("pPipelines"));
  auto XF = (PFN_vkCreateComputePipelines) vkGetInstanceProcAddr(NULL, "vkCreateComputePipelines");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateComputePipelines) vkGetInstanceProcAddr(inst, "vkCreateComputePipelines");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateComputePipelines) vkGetDeviceProcAddr(dev, "vkCreateComputePipelines");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateComputePipelines");
    throw "cannot find function vkCreateComputePipelines";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineCache *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkComputePipelineCreateInfo *>(p3),
    reinterpret_cast<const VkAllocationCallbacks *>(p4),
    reinterpret_cast< VkPipeline *>(p5)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyPipeline(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pipeline") ? resolveNapiValueAddress(input.Get("pipeline")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyPipeline) vkGetInstanceProcAddr(NULL, "vkDestroyPipeline");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyPipeline) vkGetInstanceProcAddr(inst, "vkDestroyPipeline");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyPipeline) vkGetDeviceProcAddr(dev, "vkDestroyPipeline");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyPipeline");
    throw "cannot find function vkDestroyPipeline";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipeline *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreatePipelineLayout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pPipelineLayout"));
  auto XF = (PFN_vkCreatePipelineLayout) vkGetInstanceProcAddr(NULL, "vkCreatePipelineLayout");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreatePipelineLayout) vkGetInstanceProcAddr(inst, "vkCreatePipelineLayout");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreatePipelineLayout) vkGetDeviceProcAddr(dev, "vkCreatePipelineLayout");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreatePipelineLayout");
    throw "cannot find function vkCreatePipelineLayout";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkPipelineLayoutCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkPipelineLayout *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyPipelineLayout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pipelineLayout") ? resolveNapiValueAddress(input.Get("pipelineLayout")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyPipelineLayout) vkGetInstanceProcAddr(NULL, "vkDestroyPipelineLayout");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyPipelineLayout) vkGetInstanceProcAddr(inst, "vkDestroyPipelineLayout");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyPipelineLayout) vkGetDeviceProcAddr(dev, "vkDestroyPipelineLayout");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyPipelineLayout");
    throw "cannot find function vkDestroyPipelineLayout";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipelineLayout *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateSampler(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSampler"));
  auto XF = (PFN_vkCreateSampler) vkGetInstanceProcAddr(NULL, "vkCreateSampler");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateSampler) vkGetInstanceProcAddr(inst, "vkCreateSampler");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateSampler) vkGetDeviceProcAddr(dev, "vkCreateSampler");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateSampler");
    throw "cannot find function vkCreateSampler";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSamplerCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSampler *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroySampler(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("sampler") ? resolveNapiValueAddress(input.Get("sampler")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroySampler) vkGetInstanceProcAddr(NULL, "vkDestroySampler");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroySampler) vkGetInstanceProcAddr(inst, "vkDestroySampler");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroySampler) vkGetDeviceProcAddr(dev, "vkDestroySampler");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroySampler");
    throw "cannot find function vkDestroySampler";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSampler *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateDescriptorSetLayout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSetLayout"));
  auto XF = (PFN_vkCreateDescriptorSetLayout) vkGetInstanceProcAddr(NULL, "vkCreateDescriptorSetLayout");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDescriptorSetLayout) vkGetInstanceProcAddr(inst, "vkCreateDescriptorSetLayout");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDescriptorSetLayout) vkGetDeviceProcAddr(dev, "vkCreateDescriptorSetLayout");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDescriptorSetLayout");
    throw "cannot find function vkCreateDescriptorSetLayout";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDescriptorSetLayoutCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkDescriptorSetLayout *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyDescriptorSetLayout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("descriptorSetLayout") ? resolveNapiValueAddress(input.Get("descriptorSetLayout")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyDescriptorSetLayout) vkGetInstanceProcAddr(NULL, "vkDestroyDescriptorSetLayout");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyDescriptorSetLayout) vkGetInstanceProcAddr(inst, "vkDestroyDescriptorSetLayout");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyDescriptorSetLayout) vkGetDeviceProcAddr(dev, "vkDestroyDescriptorSetLayout");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyDescriptorSetLayout");
    throw "cannot find function vkDestroyDescriptorSetLayout";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorSetLayout *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateDescriptorPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pDescriptorPool"));
  auto XF = (PFN_vkCreateDescriptorPool) vkGetInstanceProcAddr(NULL, "vkCreateDescriptorPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDescriptorPool) vkGetInstanceProcAddr(inst, "vkCreateDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDescriptorPool) vkGetDeviceProcAddr(dev, "vkCreateDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDescriptorPool");
    throw "cannot find function vkCreateDescriptorPool";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDescriptorPoolCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkDescriptorPool *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyDescriptorPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("descriptorPool") ? resolveNapiValueAddress(input.Get("descriptorPool")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyDescriptorPool) vkGetInstanceProcAddr(NULL, "vkDestroyDescriptorPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyDescriptorPool) vkGetInstanceProcAddr(inst, "vkDestroyDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyDescriptorPool) vkGetDeviceProcAddr(dev, "vkDestroyDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyDescriptorPool");
    throw "cannot find function vkDestroyDescriptorPool";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorPool *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkResetDescriptorPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("descriptorPool"));
  void * p2 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkResetDescriptorPool) vkGetInstanceProcAddr(NULL, "vkResetDescriptorPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetDescriptorPool) vkGetInstanceProcAddr(inst, "vkResetDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetDescriptorPool) vkGetDeviceProcAddr(dev, "vkResetDescriptorPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetDescriptorPool");
    throw "cannot find function vkResetDescriptorPool";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorPool *>(p1)[0],
    (VkDescriptorPoolResetFlags)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkAllocateDescriptorSets(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pAllocateInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pDescriptorSets"));
  auto XF = (PFN_vkAllocateDescriptorSets) vkGetInstanceProcAddr(NULL, "vkAllocateDescriptorSets");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkAllocateDescriptorSets) vkGetInstanceProcAddr(inst, "vkAllocateDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkAllocateDescriptorSets) vkGetDeviceProcAddr(dev, "vkAllocateDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkAllocateDescriptorSets");
    throw "cannot find function vkAllocateDescriptorSets";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDescriptorSetAllocateInfo *>(p1),
    reinterpret_cast< VkDescriptorSet *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkFreeDescriptorSets(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("descriptorPool"));
  void * p2 = resolveNapiValueAddress(input.Get("descriptorSetCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pDescriptorSets"));
  auto XF = (PFN_vkFreeDescriptorSets) vkGetInstanceProcAddr(NULL, "vkFreeDescriptorSets");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkFreeDescriptorSets) vkGetInstanceProcAddr(inst, "vkFreeDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkFreeDescriptorSets) vkGetDeviceProcAddr(dev, "vkFreeDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkFreeDescriptorSets");
    throw "cannot find function vkFreeDescriptorSets";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkDescriptorSet *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkUpdateDescriptorSets(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("descriptorWriteCount") ? resolveNapiValueAddress(input.Get("descriptorWriteCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pDescriptorWrites"));
  void * p3 = input.Has("descriptorCopyCount") ? resolveNapiValueAddress(input.Get("descriptorCopyCount")) : nullptr;
  void * p4 = resolveNapiValueAddress(input.Get("pDescriptorCopies"));
  auto XF = (PFN_vkUpdateDescriptorSets) vkGetInstanceProcAddr(NULL, "vkUpdateDescriptorSets");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkUpdateDescriptorSets) vkGetInstanceProcAddr(inst, "vkUpdateDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkUpdateDescriptorSets) vkGetDeviceProcAddr(dev, "vkUpdateDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkUpdateDescriptorSets");
    throw "cannot find function vkUpdateDescriptorSets";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkWriteDescriptorSet *>(p2),
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast<const VkCopyDescriptorSet *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateFramebuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pFramebuffer"));
  auto XF = (PFN_vkCreateFramebuffer) vkGetInstanceProcAddr(NULL, "vkCreateFramebuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateFramebuffer) vkGetInstanceProcAddr(inst, "vkCreateFramebuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateFramebuffer) vkGetDeviceProcAddr(dev, "vkCreateFramebuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateFramebuffer");
    throw "cannot find function vkCreateFramebuffer";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkFramebufferCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkFramebuffer *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyFramebuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("framebuffer") ? resolveNapiValueAddress(input.Get("framebuffer")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyFramebuffer) vkGetInstanceProcAddr(NULL, "vkDestroyFramebuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyFramebuffer) vkGetInstanceProcAddr(inst, "vkDestroyFramebuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyFramebuffer) vkGetDeviceProcAddr(dev, "vkDestroyFramebuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyFramebuffer");
    throw "cannot find function vkDestroyFramebuffer";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkFramebuffer *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateRenderPass(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pRenderPass"));
  auto XF = (PFN_vkCreateRenderPass) vkGetInstanceProcAddr(NULL, "vkCreateRenderPass");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateRenderPass) vkGetInstanceProcAddr(inst, "vkCreateRenderPass");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateRenderPass) vkGetDeviceProcAddr(dev, "vkCreateRenderPass");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateRenderPass");
    throw "cannot find function vkCreateRenderPass";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkRenderPassCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkRenderPass *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyRenderPass(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("renderPass") ? resolveNapiValueAddress(input.Get("renderPass")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyRenderPass) vkGetInstanceProcAddr(NULL, "vkDestroyRenderPass");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyRenderPass) vkGetInstanceProcAddr(inst, "vkDestroyRenderPass");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyRenderPass) vkGetDeviceProcAddr(dev, "vkDestroyRenderPass");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyRenderPass");
    throw "cannot find function vkDestroyRenderPass";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkRenderPass *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetRenderAreaGranularity(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("renderPass"));
  void * p2 = resolveNapiValueAddress(input.Get("pGranularity"));
  auto XF = (PFN_vkGetRenderAreaGranularity) vkGetInstanceProcAddr(NULL, "vkGetRenderAreaGranularity");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetRenderAreaGranularity) vkGetInstanceProcAddr(inst, "vkGetRenderAreaGranularity");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetRenderAreaGranularity) vkGetDeviceProcAddr(dev, "vkGetRenderAreaGranularity");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetRenderAreaGranularity");
    throw "cannot find function vkGetRenderAreaGranularity";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkRenderPass *>(p1)[0],
    reinterpret_cast< VkExtent2D *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateCommandPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pCommandPool"));
  auto XF = (PFN_vkCreateCommandPool) vkGetInstanceProcAddr(NULL, "vkCreateCommandPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateCommandPool) vkGetInstanceProcAddr(inst, "vkCreateCommandPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateCommandPool) vkGetDeviceProcAddr(dev, "vkCreateCommandPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateCommandPool");
    throw "cannot find function vkCreateCommandPool";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkCommandPoolCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkCommandPool *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyCommandPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("commandPool") ? resolveNapiValueAddress(input.Get("commandPool")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyCommandPool) vkGetInstanceProcAddr(NULL, "vkDestroyCommandPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyCommandPool) vkGetInstanceProcAddr(inst, "vkDestroyCommandPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyCommandPool) vkGetDeviceProcAddr(dev, "vkDestroyCommandPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyCommandPool");
    throw "cannot find function vkDestroyCommandPool";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkCommandPool *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkResetCommandPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("commandPool"));
  void * p2 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkResetCommandPool) vkGetInstanceProcAddr(NULL, "vkResetCommandPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetCommandPool) vkGetInstanceProcAddr(inst, "vkResetCommandPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetCommandPool) vkGetDeviceProcAddr(dev, "vkResetCommandPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetCommandPool");
    throw "cannot find function vkResetCommandPool";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkCommandPool *>(p1)[0],
    (VkCommandPoolResetFlags)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkAllocateCommandBuffers(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pAllocateInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pCommandBuffers"));
  auto XF = (PFN_vkAllocateCommandBuffers) vkGetInstanceProcAddr(NULL, "vkAllocateCommandBuffers");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkAllocateCommandBuffers) vkGetInstanceProcAddr(inst, "vkAllocateCommandBuffers");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkAllocateCommandBuffers) vkGetDeviceProcAddr(dev, "vkAllocateCommandBuffers");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkAllocateCommandBuffers");
    throw "cannot find function vkAllocateCommandBuffers";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkCommandBufferAllocateInfo *>(p1),
    reinterpret_cast< VkCommandBuffer *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkFreeCommandBuffers(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("commandPool"));
  void * p2 = resolveNapiValueAddress(input.Get("commandBufferCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pCommandBuffers"));
  auto XF = (PFN_vkFreeCommandBuffers) vkGetInstanceProcAddr(NULL, "vkFreeCommandBuffers");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkFreeCommandBuffers) vkGetInstanceProcAddr(inst, "vkFreeCommandBuffers");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkFreeCommandBuffers) vkGetDeviceProcAddr(dev, "vkFreeCommandBuffers");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkFreeCommandBuffers");
    throw "cannot find function vkFreeCommandBuffers";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkCommandPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkCommandBuffer *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkBeginCommandBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pBeginInfo"));
  auto XF = (PFN_vkBeginCommandBuffer) vkGetInstanceProcAddr(NULL, "vkBeginCommandBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBeginCommandBuffer) vkGetInstanceProcAddr(inst, "vkBeginCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBeginCommandBuffer) vkGetDeviceProcAddr(dev, "vkBeginCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBeginCommandBuffer");
    throw "cannot find function vkBeginCommandBuffer";
  }

  int32_t out = XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkCommandBufferBeginInfo *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkEndCommandBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  auto XF = (PFN_vkEndCommandBuffer) vkGetInstanceProcAddr(NULL, "vkEndCommandBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEndCommandBuffer) vkGetInstanceProcAddr(inst, "vkEndCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEndCommandBuffer) vkGetDeviceProcAddr(dev, "vkEndCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEndCommandBuffer");
    throw "cannot find function vkEndCommandBuffer";
  }

  int32_t out = XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkResetCommandBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkResetCommandBuffer) vkGetInstanceProcAddr(NULL, "vkResetCommandBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkResetCommandBuffer) vkGetInstanceProcAddr(inst, "vkResetCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkResetCommandBuffer) vkGetDeviceProcAddr(dev, "vkResetCommandBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkResetCommandBuffer");
    throw "cannot find function vkResetCommandBuffer";
  }

  int32_t out = XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkCommandBufferResetFlags)(((uint32_t*)p1)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdBindPipeline(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineBindPoint"));
  void * p2 = resolveNapiValueAddress(input.Get("pipeline"));
  auto XF = (PFN_vkCmdBindPipeline) vkGetInstanceProcAddr(NULL, "vkCmdBindPipeline");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindPipeline) vkGetInstanceProcAddr(inst, "vkCmdBindPipeline");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindPipeline) vkGetDeviceProcAddr(dev, "vkCmdBindPipeline");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindPipeline");
    throw "cannot find function vkCmdBindPipeline";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineBindPoint)(((int32_t*)p1)[0]),
    reinterpret_cast< VkPipeline *>(p2)[0]
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetViewport(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstViewport"));
  void * p2 = resolveNapiValueAddress(input.Get("viewportCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pViewports"));
  auto XF = (PFN_vkCmdSetViewport) vkGetInstanceProcAddr(NULL, "vkCmdSetViewport");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetViewport) vkGetInstanceProcAddr(inst, "vkCmdSetViewport");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetViewport) vkGetDeviceProcAddr(dev, "vkCmdSetViewport");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetViewport");
    throw "cannot find function vkCmdSetViewport";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkViewport *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetScissor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstScissor"));
  void * p2 = resolveNapiValueAddress(input.Get("scissorCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pScissors"));
  auto XF = (PFN_vkCmdSetScissor) vkGetInstanceProcAddr(NULL, "vkCmdSetScissor");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetScissor) vkGetInstanceProcAddr(inst, "vkCmdSetScissor");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetScissor) vkGetDeviceProcAddr(dev, "vkCmdSetScissor");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetScissor");
    throw "cannot find function vkCmdSetScissor";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkRect2D *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetLineWidth(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("lineWidth"));
  auto XF = (PFN_vkCmdSetLineWidth) vkGetInstanceProcAddr(NULL, "vkCmdSetLineWidth");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetLineWidth) vkGetInstanceProcAddr(inst, "vkCmdSetLineWidth");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetLineWidth) vkGetDeviceProcAddr(dev, "vkCmdSetLineWidth");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetLineWidth");
    throw "cannot find function vkCmdSetLineWidth";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (float)(((float*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthBias(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthBiasConstantFactor"));
  void * p2 = resolveNapiValueAddress(input.Get("depthBiasClamp"));
  void * p3 = resolveNapiValueAddress(input.Get("depthBiasSlopeFactor"));
  auto XF = (PFN_vkCmdSetDepthBias) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthBias");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthBias) vkGetInstanceProcAddr(inst, "vkCmdSetDepthBias");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthBias) vkGetDeviceProcAddr(dev, "vkCmdSetDepthBias");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthBias");
    throw "cannot find function vkCmdSetDepthBias";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (float)(((float*)p1)[0]),
    (float)(((float*)p2)[0]),
    (float)(((float*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetBlendConstants(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("blendConstants"));
  auto XF = (PFN_vkCmdSetBlendConstants) vkGetInstanceProcAddr(NULL, "vkCmdSetBlendConstants");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetBlendConstants) vkGetInstanceProcAddr(inst, "vkCmdSetBlendConstants");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetBlendConstants) vkGetDeviceProcAddr(dev, "vkCmdSetBlendConstants");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetBlendConstants");
    throw "cannot find function vkCmdSetBlendConstants";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const float *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthBounds(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("minDepthBounds"));
  void * p2 = resolveNapiValueAddress(input.Get("maxDepthBounds"));
  auto XF = (PFN_vkCmdSetDepthBounds) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthBounds");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthBounds) vkGetInstanceProcAddr(inst, "vkCmdSetDepthBounds");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthBounds) vkGetDeviceProcAddr(dev, "vkCmdSetDepthBounds");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthBounds");
    throw "cannot find function vkCmdSetDepthBounds";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (float)(((float*)p1)[0]),
    (float)(((float*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetStencilCompareMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("faceMask"));
  void * p2 = resolveNapiValueAddress(input.Get("compareMask"));
  auto XF = (PFN_vkCmdSetStencilCompareMask) vkGetInstanceProcAddr(NULL, "vkCmdSetStencilCompareMask");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetStencilCompareMask) vkGetInstanceProcAddr(inst, "vkCmdSetStencilCompareMask");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetStencilCompareMask) vkGetDeviceProcAddr(dev, "vkCmdSetStencilCompareMask");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetStencilCompareMask");
    throw "cannot find function vkCmdSetStencilCompareMask";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkStencilFaceFlags)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetStencilWriteMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("faceMask"));
  void * p2 = resolveNapiValueAddress(input.Get("writeMask"));
  auto XF = (PFN_vkCmdSetStencilWriteMask) vkGetInstanceProcAddr(NULL, "vkCmdSetStencilWriteMask");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetStencilWriteMask) vkGetInstanceProcAddr(inst, "vkCmdSetStencilWriteMask");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetStencilWriteMask) vkGetDeviceProcAddr(dev, "vkCmdSetStencilWriteMask");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetStencilWriteMask");
    throw "cannot find function vkCmdSetStencilWriteMask";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkStencilFaceFlags)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetStencilReference(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("faceMask"));
  void * p2 = resolveNapiValueAddress(input.Get("reference"));
  auto XF = (PFN_vkCmdSetStencilReference) vkGetInstanceProcAddr(NULL, "vkCmdSetStencilReference");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetStencilReference) vkGetInstanceProcAddr(inst, "vkCmdSetStencilReference");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetStencilReference) vkGetDeviceProcAddr(dev, "vkCmdSetStencilReference");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetStencilReference");
    throw "cannot find function vkCmdSetStencilReference";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkStencilFaceFlags)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBindDescriptorSets(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineBindPoint"));
  void * p2 = resolveNapiValueAddress(input.Get("layout"));
  void * p3 = resolveNapiValueAddress(input.Get("firstSet"));
  void * p4 = resolveNapiValueAddress(input.Get("descriptorSetCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pDescriptorSets"));
  void * p6 = input.Has("dynamicOffsetCount") ? resolveNapiValueAddress(input.Get("dynamicOffsetCount")) : nullptr;
  void * p7 = resolveNapiValueAddress(input.Get("pDynamicOffsets"));
  auto XF = (PFN_vkCmdBindDescriptorSets) vkGetInstanceProcAddr(NULL, "vkCmdBindDescriptorSets");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindDescriptorSets) vkGetInstanceProcAddr(inst, "vkCmdBindDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindDescriptorSets) vkGetDeviceProcAddr(dev, "vkCmdBindDescriptorSets");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindDescriptorSets");
    throw "cannot find function vkCmdBindDescriptorSets";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineBindPoint)(((int32_t*)p1)[0]),
    reinterpret_cast< VkPipelineLayout *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkDescriptorSet *>(p5),
    (uint32_t)(((uint32_t*)p6)[0]),
    reinterpret_cast<const uint32_t *>(p7)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBindIndexBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("indexType"));
  auto XF = (PFN_vkCmdBindIndexBuffer) vkGetInstanceProcAddr(NULL, "vkCmdBindIndexBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindIndexBuffer) vkGetInstanceProcAddr(inst, "vkCmdBindIndexBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindIndexBuffer) vkGetDeviceProcAddr(dev, "vkCmdBindIndexBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindIndexBuffer");
    throw "cannot find function vkCmdBindIndexBuffer";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (VkIndexType)(((int32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBindVertexBuffers(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstBinding"));
  void * p2 = resolveNapiValueAddress(input.Get("bindingCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pBuffers"));
  void * p4 = resolveNapiValueAddress(input.Get("pOffsets"));
  auto XF = (PFN_vkCmdBindVertexBuffers) vkGetInstanceProcAddr(NULL, "vkCmdBindVertexBuffers");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindVertexBuffers) vkGetInstanceProcAddr(inst, "vkCmdBindVertexBuffers");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindVertexBuffers) vkGetDeviceProcAddr(dev, "vkCmdBindVertexBuffers");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindVertexBuffers");
    throw "cannot find function vkCmdBindVertexBuffers";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBuffer *>(p3),
    reinterpret_cast<const VkDeviceSize *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDraw(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("vertexCount"));
  void * p2 = resolveNapiValueAddress(input.Get("instanceCount"));
  void * p3 = resolveNapiValueAddress(input.Get("firstVertex"));
  void * p4 = resolveNapiValueAddress(input.Get("firstInstance"));
  auto XF = (PFN_vkCmdDraw) vkGetInstanceProcAddr(NULL, "vkCmdDraw");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDraw) vkGetInstanceProcAddr(inst, "vkCmdDraw");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDraw) vkGetDeviceProcAddr(dev, "vkCmdDraw");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDraw");
    throw "cannot find function vkCmdDraw";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawIndexed(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("indexCount"));
  void * p2 = resolveNapiValueAddress(input.Get("instanceCount"));
  void * p3 = resolveNapiValueAddress(input.Get("firstIndex"));
  void * p4 = resolveNapiValueAddress(input.Get("vertexOffset"));
  void * p5 = resolveNapiValueAddress(input.Get("firstInstance"));
  auto XF = (PFN_vkCmdDrawIndexed) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndexed");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndexed) vkGetInstanceProcAddr(inst, "vkCmdDrawIndexed");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndexed) vkGetDeviceProcAddr(dev, "vkCmdDrawIndexed");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndexed");
    throw "cannot find function vkCmdDrawIndexed";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (int32_t)(((int32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawMultiEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("drawCount") ? resolveNapiValueAddress(input.Get("drawCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pVertexInfo"));
  void * p3 = resolveNapiValueAddress(input.Get("instanceCount"));
  void * p4 = resolveNapiValueAddress(input.Get("firstInstance"));
  void * p5 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawMultiEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawMultiEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawMultiEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawMultiEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawMultiEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawMultiEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawMultiEXT");
    throw "cannot find function vkCmdDrawMultiEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkMultiDrawInfoEXT *>(p2),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawMultiIndexedEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("drawCount") ? resolveNapiValueAddress(input.Get("drawCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pIndexInfo"));
  void * p3 = resolveNapiValueAddress(input.Get("instanceCount"));
  void * p4 = resolveNapiValueAddress(input.Get("firstInstance"));
  void * p5 = resolveNapiValueAddress(input.Get("stride"));
  void * p6 = input.Has("pVertexOffset") ? resolveNapiValueAddress(input.Get("pVertexOffset")) : nullptr;
  auto XF = (PFN_vkCmdDrawMultiIndexedEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawMultiIndexedEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawMultiIndexedEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawMultiIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawMultiIndexedEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawMultiIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawMultiIndexedEXT");
    throw "cannot find function vkCmdDrawMultiIndexedEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkMultiDrawIndexedInfoEXT *>(p2),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    reinterpret_cast<const int32_t *>(p6)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawIndirect(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("drawCount"));
  void * p4 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawIndirect) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndirect");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndirect) vkGetInstanceProcAddr(inst, "vkCmdDrawIndirect");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndirect) vkGetDeviceProcAddr(dev, "vkCmdDrawIndirect");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndirect");
    throw "cannot find function vkCmdDrawIndirect";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawIndexedIndirect(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("drawCount"));
  void * p4 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawIndexedIndirect) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndexedIndirect");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndexedIndirect) vkGetInstanceProcAddr(inst, "vkCmdDrawIndexedIndirect");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndexedIndirect) vkGetDeviceProcAddr(dev, "vkCmdDrawIndexedIndirect");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndexedIndirect");
    throw "cannot find function vkCmdDrawIndexedIndirect";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDispatch(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("groupCountX"));
  void * p2 = resolveNapiValueAddress(input.Get("groupCountY"));
  void * p3 = resolveNapiValueAddress(input.Get("groupCountZ"));
  auto XF = (PFN_vkCmdDispatch) vkGetInstanceProcAddr(NULL, "vkCmdDispatch");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDispatch) vkGetInstanceProcAddr(inst, "vkCmdDispatch");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDispatch) vkGetDeviceProcAddr(dev, "vkCmdDispatch");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDispatch");
    throw "cannot find function vkCmdDispatch";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDispatchIndirect(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  auto XF = (PFN_vkCmdDispatchIndirect) vkGetInstanceProcAddr(NULL, "vkCmdDispatchIndirect");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDispatchIndirect) vkGetInstanceProcAddr(inst, "vkCmdDispatchIndirect");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDispatchIndirect) vkGetDeviceProcAddr(dev, "vkCmdDispatchIndirect");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDispatchIndirect");
    throw "cannot find function vkCmdDispatchIndirect";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcBuffer"));
  void * p2 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p3 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p4 = resolveNapiValueAddress(input.Get("pRegions"));
  auto XF = (PFN_vkCmdCopyBuffer) vkGetInstanceProcAddr(NULL, "vkCmdCopyBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyBuffer) vkGetInstanceProcAddr(inst, "vkCmdCopyBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyBuffer) vkGetDeviceProcAddr(dev, "vkCmdCopyBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyBuffer");
    throw "cannot find function vkCmdCopyBuffer";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    reinterpret_cast< VkBuffer *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast<const VkBufferCopy *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcImage"));
  void * p2 = resolveNapiValueAddress(input.Get("srcImageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("dstImage"));
  void * p4 = resolveNapiValueAddress(input.Get("dstImageLayout"));
  void * p5 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p6 = resolveNapiValueAddress(input.Get("pRegions"));
  auto XF = (PFN_vkCmdCopyImage) vkGetInstanceProcAddr(NULL, "vkCmdCopyImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyImage) vkGetInstanceProcAddr(inst, "vkCmdCopyImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyImage) vkGetDeviceProcAddr(dev, "vkCmdCopyImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyImage");
    throw "cannot find function vkCmdCopyImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast< VkImage *>(p3)[0],
    (VkImageLayout)(((int32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    reinterpret_cast<const VkImageCopy *>(p6)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBlitImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcImage"));
  void * p2 = resolveNapiValueAddress(input.Get("srcImageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("dstImage"));
  void * p4 = resolveNapiValueAddress(input.Get("dstImageLayout"));
  void * p5 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p6 = resolveNapiValueAddress(input.Get("pRegions"));
  void * p7 = resolveNapiValueAddress(input.Get("filter"));
  auto XF = (PFN_vkCmdBlitImage) vkGetInstanceProcAddr(NULL, "vkCmdBlitImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBlitImage) vkGetInstanceProcAddr(inst, "vkCmdBlitImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBlitImage) vkGetDeviceProcAddr(dev, "vkCmdBlitImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBlitImage");
    throw "cannot find function vkCmdBlitImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast< VkImage *>(p3)[0],
    (VkImageLayout)(((int32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    reinterpret_cast<const VkImageBlit *>(p6),
    (VkFilter)(((int32_t*)p7)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyBufferToImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcBuffer"));
  void * p2 = resolveNapiValueAddress(input.Get("dstImage"));
  void * p3 = resolveNapiValueAddress(input.Get("dstImageLayout"));
  void * p4 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pRegions"));
  auto XF = (PFN_vkCmdCopyBufferToImage) vkGetInstanceProcAddr(NULL, "vkCmdCopyBufferToImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyBufferToImage) vkGetInstanceProcAddr(inst, "vkCmdCopyBufferToImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyBufferToImage) vkGetDeviceProcAddr(dev, "vkCmdCopyBufferToImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyBufferToImage");
    throw "cannot find function vkCmdCopyBufferToImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    reinterpret_cast< VkImage *>(p2)[0],
    (VkImageLayout)(((int32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkBufferImageCopy *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyImageToBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcImage"));
  void * p2 = resolveNapiValueAddress(input.Get("srcImageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p4 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pRegions"));
  auto XF = (PFN_vkCmdCopyImageToBuffer) vkGetInstanceProcAddr(NULL, "vkCmdCopyImageToBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyImageToBuffer) vkGetInstanceProcAddr(inst, "vkCmdCopyImageToBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyImageToBuffer) vkGetDeviceProcAddr(dev, "vkCmdCopyImageToBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyImageToBuffer");
    throw "cannot find function vkCmdCopyImageToBuffer";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast< VkBuffer *>(p3)[0],
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkBufferImageCopy *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdUpdateBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p2 = resolveNapiValueAddress(input.Get("dstOffset"));
  void * p3 = resolveNapiValueAddress(input.Get("dataSize"));
  void * p4 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkCmdUpdateBuffer) vkGetInstanceProcAddr(NULL, "vkCmdUpdateBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdUpdateBuffer) vkGetInstanceProcAddr(inst, "vkCmdUpdateBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdUpdateBuffer) vkGetDeviceProcAddr(dev, "vkCmdUpdateBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdUpdateBuffer");
    throw "cannot find function vkCmdUpdateBuffer";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (VkDeviceSize)(((VkDeviceSize*)p3)[0]),
    &p4
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdFillBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p2 = resolveNapiValueAddress(input.Get("dstOffset"));
  void * p3 = resolveNapiValueAddress(input.Get("size"));
  void * p4 = resolveNapiValueAddress(input.Get("data"));
  auto XF = (PFN_vkCmdFillBuffer) vkGetInstanceProcAddr(NULL, "vkCmdFillBuffer");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdFillBuffer) vkGetInstanceProcAddr(inst, "vkCmdFillBuffer");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdFillBuffer) vkGetDeviceProcAddr(dev, "vkCmdFillBuffer");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdFillBuffer");
    throw "cannot find function vkCmdFillBuffer";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (VkDeviceSize)(((VkDeviceSize*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdClearColorImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("imageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("pColor"));
  void * p4 = resolveNapiValueAddress(input.Get("rangeCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pRanges"));
  auto XF = (PFN_vkCmdClearColorImage) vkGetInstanceProcAddr(NULL, "vkCmdClearColorImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdClearColorImage) vkGetInstanceProcAddr(inst, "vkCmdClearColorImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdClearColorImage) vkGetDeviceProcAddr(dev, "vkCmdClearColorImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdClearColorImage");
    throw "cannot find function vkCmdClearColorImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast<const VkClearColorValue *>(p3),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkImageSubresourceRange *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdClearDepthStencilImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("imageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("pDepthStencil"));
  void * p4 = resolveNapiValueAddress(input.Get("rangeCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pRanges"));
  auto XF = (PFN_vkCmdClearDepthStencilImage) vkGetInstanceProcAddr(NULL, "vkCmdClearDepthStencilImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdClearDepthStencilImage) vkGetInstanceProcAddr(inst, "vkCmdClearDepthStencilImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdClearDepthStencilImage) vkGetDeviceProcAddr(dev, "vkCmdClearDepthStencilImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdClearDepthStencilImage");
    throw "cannot find function vkCmdClearDepthStencilImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast<const VkClearDepthStencilValue *>(p3),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkImageSubresourceRange *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdClearAttachments(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("attachmentCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pAttachments"));
  void * p3 = resolveNapiValueAddress(input.Get("rectCount"));
  void * p4 = resolveNapiValueAddress(input.Get("pRects"));
  auto XF = (PFN_vkCmdClearAttachments) vkGetInstanceProcAddr(NULL, "vkCmdClearAttachments");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdClearAttachments) vkGetInstanceProcAddr(inst, "vkCmdClearAttachments");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdClearAttachments) vkGetDeviceProcAddr(dev, "vkCmdClearAttachments");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdClearAttachments");
    throw "cannot find function vkCmdClearAttachments";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkClearAttachment *>(p2),
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast<const VkClearRect *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdResolveImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("srcImage"));
  void * p2 = resolveNapiValueAddress(input.Get("srcImageLayout"));
  void * p3 = resolveNapiValueAddress(input.Get("dstImage"));
  void * p4 = resolveNapiValueAddress(input.Get("dstImageLayout"));
  void * p5 = resolveNapiValueAddress(input.Get("regionCount"));
  void * p6 = resolveNapiValueAddress(input.Get("pRegions"));
  auto XF = (PFN_vkCmdResolveImage) vkGetInstanceProcAddr(NULL, "vkCmdResolveImage");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdResolveImage) vkGetInstanceProcAddr(inst, "vkCmdResolveImage");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdResolveImage) vkGetDeviceProcAddr(dev, "vkCmdResolveImage");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdResolveImage");
    throw "cannot find function vkCmdResolveImage";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    (VkImageLayout)(((int32_t*)p2)[0]),
    reinterpret_cast< VkImage *>(p3)[0],
    (VkImageLayout)(((int32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    reinterpret_cast<const VkImageResolve *>(p6)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  void * p2 = input.Has("stageMask") ? resolveNapiValueAddress(input.Get("stageMask")) : nullptr;
  auto XF = (PFN_vkCmdSetEvent) vkGetInstanceProcAddr(NULL, "vkCmdSetEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetEvent) vkGetInstanceProcAddr(inst, "vkCmdSetEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetEvent) vkGetDeviceProcAddr(dev, "vkCmdSetEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetEvent");
    throw "cannot find function vkCmdSetEvent";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0],
    (VkPipelineStageFlags)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdResetEvent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  void * p2 = input.Has("stageMask") ? resolveNapiValueAddress(input.Get("stageMask")) : nullptr;
  auto XF = (PFN_vkCmdResetEvent) vkGetInstanceProcAddr(NULL, "vkCmdResetEvent");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdResetEvent) vkGetInstanceProcAddr(inst, "vkCmdResetEvent");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdResetEvent) vkGetDeviceProcAddr(dev, "vkCmdResetEvent");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdResetEvent");
    throw "cannot find function vkCmdResetEvent";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0],
    (VkPipelineStageFlags)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdWaitEvents(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("eventCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pEvents"));
  void * p3 = input.Has("srcStageMask") ? resolveNapiValueAddress(input.Get("srcStageMask")) : nullptr;
  void * p4 = input.Has("dstStageMask") ? resolveNapiValueAddress(input.Get("dstStageMask")) : nullptr;
  void * p5 = input.Has("memoryBarrierCount") ? resolveNapiValueAddress(input.Get("memoryBarrierCount")) : nullptr;
  void * p6 = resolveNapiValueAddress(input.Get("pMemoryBarriers"));
  void * p7 = input.Has("bufferMemoryBarrierCount") ? resolveNapiValueAddress(input.Get("bufferMemoryBarrierCount")) : nullptr;
  void * p8 = resolveNapiValueAddress(input.Get("pBufferMemoryBarriers"));
  void * p9 = input.Has("imageMemoryBarrierCount") ? resolveNapiValueAddress(input.Get("imageMemoryBarrierCount")) : nullptr;
  void * p10 = resolveNapiValueAddress(input.Get("pImageMemoryBarriers"));
  auto XF = (PFN_vkCmdWaitEvents) vkGetInstanceProcAddr(NULL, "vkCmdWaitEvents");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdWaitEvents) vkGetInstanceProcAddr(inst, "vkCmdWaitEvents");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdWaitEvents) vkGetDeviceProcAddr(dev, "vkCmdWaitEvents");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdWaitEvents");
    throw "cannot find function vkCmdWaitEvents";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkEvent *>(p2),
    (VkPipelineStageFlags)(((uint32_t*)p3)[0]),
    (VkPipelineStageFlags)(((uint32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    reinterpret_cast<const VkMemoryBarrier *>(p6),
    (uint32_t)(((uint32_t*)p7)[0]),
    reinterpret_cast<const VkBufferMemoryBarrier *>(p8),
    (uint32_t)(((uint32_t*)p9)[0]),
    reinterpret_cast<const VkImageMemoryBarrier *>(p10)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdPipelineBarrier(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("srcStageMask") ? resolveNapiValueAddress(input.Get("srcStageMask")) : nullptr;
  void * p2 = input.Has("dstStageMask") ? resolveNapiValueAddress(input.Get("dstStageMask")) : nullptr;
  void * p3 = input.Has("dependencyFlags") ? resolveNapiValueAddress(input.Get("dependencyFlags")) : nullptr;
  void * p4 = input.Has("memoryBarrierCount") ? resolveNapiValueAddress(input.Get("memoryBarrierCount")) : nullptr;
  void * p5 = resolveNapiValueAddress(input.Get("pMemoryBarriers"));
  void * p6 = input.Has("bufferMemoryBarrierCount") ? resolveNapiValueAddress(input.Get("bufferMemoryBarrierCount")) : nullptr;
  void * p7 = resolveNapiValueAddress(input.Get("pBufferMemoryBarriers"));
  void * p8 = input.Has("imageMemoryBarrierCount") ? resolveNapiValueAddress(input.Get("imageMemoryBarrierCount")) : nullptr;
  void * p9 = resolveNapiValueAddress(input.Get("pImageMemoryBarriers"));
  auto XF = (PFN_vkCmdPipelineBarrier) vkGetInstanceProcAddr(NULL, "vkCmdPipelineBarrier");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdPipelineBarrier) vkGetInstanceProcAddr(inst, "vkCmdPipelineBarrier");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdPipelineBarrier) vkGetDeviceProcAddr(dev, "vkCmdPipelineBarrier");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdPipelineBarrier");
    throw "cannot find function vkCmdPipelineBarrier";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineStageFlags)(((uint32_t*)p1)[0]),
    (VkPipelineStageFlags)(((uint32_t*)p2)[0]),
    (VkDependencyFlags)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkMemoryBarrier *>(p5),
    (uint32_t)(((uint32_t*)p6)[0]),
    reinterpret_cast<const VkBufferMemoryBarrier *>(p7),
    (uint32_t)(((uint32_t*)p8)[0]),
    reinterpret_cast<const VkImageMemoryBarrier *>(p9)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBeginQuery(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("query"));
  void * p3 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkCmdBeginQuery) vkGetInstanceProcAddr(NULL, "vkCmdBeginQuery");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginQuery) vkGetInstanceProcAddr(inst, "vkCmdBeginQuery");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginQuery) vkGetDeviceProcAddr(dev, "vkCmdBeginQuery");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginQuery");
    throw "cannot find function vkCmdBeginQuery";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (VkQueryControlFlags)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndQuery(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("query"));
  auto XF = (PFN_vkCmdEndQuery) vkGetInstanceProcAddr(NULL, "vkCmdEndQuery");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndQuery) vkGetInstanceProcAddr(inst, "vkCmdEndQuery");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndQuery) vkGetDeviceProcAddr(dev, "vkCmdEndQuery");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndQuery");
    throw "cannot find function vkCmdEndQuery";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdResetQueryPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("firstQuery"));
  void * p3 = resolveNapiValueAddress(input.Get("queryCount"));
  auto XF = (PFN_vkCmdResetQueryPool) vkGetInstanceProcAddr(NULL, "vkCmdResetQueryPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdResetQueryPool) vkGetInstanceProcAddr(inst, "vkCmdResetQueryPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdResetQueryPool) vkGetDeviceProcAddr(dev, "vkCmdResetQueryPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdResetQueryPool");
    throw "cannot find function vkCmdResetQueryPool";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdWriteTimestamp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineStage"));
  void * p2 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p3 = resolveNapiValueAddress(input.Get("query"));
  auto XF = (PFN_vkCmdWriteTimestamp) vkGetInstanceProcAddr(NULL, "vkCmdWriteTimestamp");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdWriteTimestamp) vkGetInstanceProcAddr(inst, "vkCmdWriteTimestamp");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdWriteTimestamp) vkGetDeviceProcAddr(dev, "vkCmdWriteTimestamp");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdWriteTimestamp");
    throw "cannot find function vkCmdWriteTimestamp";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineStageFlagBits)(((uint32_t*)p1)[0]),
    reinterpret_cast< VkQueryPool *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyQueryPoolResults(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("firstQuery"));
  void * p3 = resolveNapiValueAddress(input.Get("queryCount"));
  void * p4 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p5 = resolveNapiValueAddress(input.Get("dstOffset"));
  void * p6 = resolveNapiValueAddress(input.Get("stride"));
  void * p7 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkCmdCopyQueryPoolResults) vkGetInstanceProcAddr(NULL, "vkCmdCopyQueryPoolResults");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyQueryPoolResults) vkGetInstanceProcAddr(inst, "vkCmdCopyQueryPoolResults");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyQueryPoolResults) vkGetDeviceProcAddr(dev, "vkCmdCopyQueryPoolResults");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyQueryPoolResults");
    throw "cannot find function vkCmdCopyQueryPoolResults";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast< VkBuffer *>(p4)[0],
    (VkDeviceSize)(((VkDeviceSize*)p5)[0]),
    (VkDeviceSize)(((VkDeviceSize*)p6)[0]),
    (VkQueryResultFlags)(((uint32_t*)p7)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdPushConstants(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("layout"));
  void * p2 = resolveNapiValueAddress(input.Get("stageFlags"));
  void * p3 = resolveNapiValueAddress(input.Get("offset"));
  void * p4 = resolveNapiValueAddress(input.Get("size"));
  void * p5 = resolveNapiValueAddress(input.Get("pValues"));
  auto XF = (PFN_vkCmdPushConstants) vkGetInstanceProcAddr(NULL, "vkCmdPushConstants");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdPushConstants) vkGetInstanceProcAddr(inst, "vkCmdPushConstants");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdPushConstants) vkGetDeviceProcAddr(dev, "vkCmdPushConstants");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdPushConstants");
    throw "cannot find function vkCmdPushConstants";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkPipelineLayout *>(p1)[0],
    (VkShaderStageFlags)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    &p5
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBeginRenderPass(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pRenderPassBegin"));
  void * p2 = resolveNapiValueAddress(input.Get("contents"));
  auto XF = (PFN_vkCmdBeginRenderPass) vkGetInstanceProcAddr(NULL, "vkCmdBeginRenderPass");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginRenderPass) vkGetInstanceProcAddr(inst, "vkCmdBeginRenderPass");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginRenderPass) vkGetDeviceProcAddr(dev, "vkCmdBeginRenderPass");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginRenderPass");
    throw "cannot find function vkCmdBeginRenderPass";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkRenderPassBeginInfo *>(p1),
    (VkSubpassContents)(((int32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdNextSubpass(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("contents"));
  auto XF = (PFN_vkCmdNextSubpass) vkGetInstanceProcAddr(NULL, "vkCmdNextSubpass");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdNextSubpass) vkGetInstanceProcAddr(inst, "vkCmdNextSubpass");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdNextSubpass) vkGetDeviceProcAddr(dev, "vkCmdNextSubpass");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdNextSubpass");
    throw "cannot find function vkCmdNextSubpass";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkSubpassContents)(((int32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndRenderPass(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  auto XF = (PFN_vkCmdEndRenderPass) vkGetInstanceProcAddr(NULL, "vkCmdEndRenderPass");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndRenderPass) vkGetInstanceProcAddr(inst, "vkCmdEndRenderPass");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndRenderPass) vkGetDeviceProcAddr(dev, "vkCmdEndRenderPass");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndRenderPass");
    throw "cannot find function vkCmdEndRenderPass";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0]
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdExecuteCommands(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("commandBufferCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pCommandBuffers"));
  auto XF = (PFN_vkCmdExecuteCommands) vkGetInstanceProcAddr(NULL, "vkCmdExecuteCommands");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdExecuteCommands) vkGetInstanceProcAddr(inst, "vkCmdExecuteCommands");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdExecuteCommands) vkGetDeviceProcAddr(dev, "vkCmdExecuteCommands");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdExecuteCommands");
    throw "cannot find function vkCmdExecuteCommands";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkCommandBuffer *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceDisplayPropertiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceDisplayPropertiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceDisplayPropertiesKHR");
    throw "cannot find function vkGetPhysicalDeviceDisplayPropertiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkDisplayPropertiesKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    throw "cannot find function vkGetPhysicalDeviceDisplayPlanePropertiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkDisplayPlanePropertiesKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDisplayPlaneSupportedDisplaysKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("planeIndex"));
  void * p2 = resolveNapiValueAddress(input.Get("pDisplayCount"));
  void * p3 = input.Has("pDisplays") ? resolveNapiValueAddress(input.Get("pDisplays")) : nullptr;
  auto XF = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) vkGetInstanceProcAddr(NULL, "vkGetDisplayPlaneSupportedDisplaysKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) vkGetInstanceProcAddr(inst, "vkGetDisplayPlaneSupportedDisplaysKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) vkGetDeviceProcAddr(dev, "vkGetDisplayPlaneSupportedDisplaysKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDisplayPlaneSupportedDisplaysKHR");
    throw "cannot find function vkGetDisplayPlaneSupportedDisplaysKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkDisplayKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDisplayModePropertiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("display"));
  void * p2 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p3 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetDisplayModePropertiesKHR) vkGetInstanceProcAddr(NULL, "vkGetDisplayModePropertiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDisplayModePropertiesKHR) vkGetInstanceProcAddr(inst, "vkGetDisplayModePropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDisplayModePropertiesKHR) vkGetDeviceProcAddr(dev, "vkGetDisplayModePropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDisplayModePropertiesKHR");
    throw "cannot find function vkGetDisplayModePropertiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkDisplayKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkDisplayModePropertiesKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateDisplayModeKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("display"));
  void * p2 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p3 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p4 = resolveNapiValueAddress(input.Get("pMode"));
  auto XF = (PFN_vkCreateDisplayModeKHR) vkGetInstanceProcAddr(NULL, "vkCreateDisplayModeKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDisplayModeKHR) vkGetInstanceProcAddr(inst, "vkCreateDisplayModeKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDisplayModeKHR) vkGetDeviceProcAddr(dev, "vkCreateDisplayModeKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDisplayModeKHR");
    throw "cannot find function vkCreateDisplayModeKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkDisplayKHR *>(p1)[0],
    reinterpret_cast<const VkDisplayModeCreateInfoKHR *>(p2),
    reinterpret_cast<const VkAllocationCallbacks *>(p3),
    reinterpret_cast< VkDisplayModeKHR *>(p4)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDisplayPlaneCapabilitiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("mode"));
  void * p2 = resolveNapiValueAddress(input.Get("planeIndex"));
  void * p3 = resolveNapiValueAddress(input.Get("pCapabilities"));
  auto XF = (PFN_vkGetDisplayPlaneCapabilitiesKHR) vkGetInstanceProcAddr(NULL, "vkGetDisplayPlaneCapabilitiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneCapabilitiesKHR) vkGetInstanceProcAddr(inst, "vkGetDisplayPlaneCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneCapabilitiesKHR) vkGetDeviceProcAddr(dev, "vkGetDisplayPlaneCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDisplayPlaneCapabilitiesKHR");
    throw "cannot find function vkGetDisplayPlaneCapabilitiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkDisplayModeKHR *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast< VkDisplayPlaneCapabilitiesKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateDisplayPlaneSurfaceKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("instance"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSurface"));
  auto XF = (PFN_vkCreateDisplayPlaneSurfaceKHR) vkGetInstanceProcAddr(NULL, "vkCreateDisplayPlaneSurfaceKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDisplayPlaneSurfaceKHR) vkGetInstanceProcAddr(inst, "vkCreateDisplayPlaneSurfaceKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDisplayPlaneSurfaceKHR) vkGetDeviceProcAddr(dev, "vkCreateDisplayPlaneSurfaceKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDisplayPlaneSurfaceKHR");
    throw "cannot find function vkCreateDisplayPlaneSurfaceKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSurfaceKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateSharedSwapchainsKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchainCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pCreateInfos"));
  void * p3 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p4 = resolveNapiValueAddress(input.Get("pSwapchains"));
  auto XF = (PFN_vkCreateSharedSwapchainsKHR) vkGetInstanceProcAddr(NULL, "vkCreateSharedSwapchainsKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateSharedSwapchainsKHR) vkGetInstanceProcAddr(inst, "vkCreateSharedSwapchainsKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateSharedSwapchainsKHR) vkGetDeviceProcAddr(dev, "vkCreateSharedSwapchainsKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateSharedSwapchainsKHR");
    throw "cannot find function vkCreateSharedSwapchainsKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkSwapchainCreateInfoKHR *>(p2),
    reinterpret_cast<const VkAllocationCallbacks *>(p3),
    reinterpret_cast< VkSwapchainKHR *>(p4)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroySurfaceKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("instance"));
  void * p1 = input.Has("surface") ? resolveNapiValueAddress(input.Get("surface")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroySurfaceKHR) vkGetInstanceProcAddr(NULL, "vkDestroySurfaceKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroySurfaceKHR) vkGetInstanceProcAddr(inst, "vkDestroySurfaceKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroySurfaceKHR) vkGetDeviceProcAddr(dev, "vkDestroySurfaceKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroySurfaceKHR");
    throw "cannot find function vkDestroySurfaceKHR";
  }

  XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfaceSupportKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("queueFamilyIndex"));
  void * p2 = resolveNapiValueAddress(input.Get("surface"));
  void * p3 = resolveNapiValueAddress(input.Get("pSupported"));
  auto XF = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfaceSupportKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfaceSupportKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfaceSupportKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfaceSupportKHR");
    throw "cannot find function vkGetPhysicalDeviceSurfaceSupportKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast< VkSurfaceKHR *>(p2)[0],
    reinterpret_cast< VkBool32 *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("surface"));
  void * p2 = resolveNapiValueAddress(input.Get("pSurfaceCapabilities"));
  auto XF = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    throw "cannot find function vkGetPhysicalDeviceSurfaceCapabilitiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast< VkSurfaceCapabilitiesKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfaceFormatsKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = input.Has("surface") ? resolveNapiValueAddress(input.Get("surface")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pSurfaceFormatCount"));
  void * p3 = input.Has("pSurfaceFormats") ? resolveNapiValueAddress(input.Get("pSurfaceFormats")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfaceFormatsKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfaceFormatsKHR");
    throw "cannot find function vkGetPhysicalDeviceSurfaceFormatsKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSurfaceFormatKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = input.Has("surface") ? resolveNapiValueAddress(input.Get("surface")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pPresentModeCount"));
  void * p3 = input.Has("pPresentModes") ? resolveNapiValueAddress(input.Get("pPresentModes")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfacePresentModesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfacePresentModesKHR");
    throw "cannot find function vkGetPhysicalDeviceSurfacePresentModesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkPresentModeKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateSwapchainKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSwapchain"));
  auto XF = (PFN_vkCreateSwapchainKHR) vkGetInstanceProcAddr(NULL, "vkCreateSwapchainKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateSwapchainKHR) vkGetInstanceProcAddr(inst, "vkCreateSwapchainKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateSwapchainKHR) vkGetDeviceProcAddr(dev, "vkCreateSwapchainKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateSwapchainKHR");
    throw "cannot find function vkCreateSwapchainKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSwapchainCreateInfoKHR *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSwapchainKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroySwapchainKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("swapchain") ? resolveNapiValueAddress(input.Get("swapchain")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroySwapchainKHR) vkGetInstanceProcAddr(NULL, "vkDestroySwapchainKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroySwapchainKHR) vkGetInstanceProcAddr(inst, "vkDestroySwapchainKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroySwapchainKHR) vkGetDeviceProcAddr(dev, "vkDestroySwapchainKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroySwapchainKHR");
    throw "cannot find function vkDestroySwapchainKHR";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSwapchainKHR *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetSwapchainImagesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchain"));
  void * p2 = resolveNapiValueAddress(input.Get("pSwapchainImageCount"));
  void * p3 = input.Has("pSwapchainImages") ? resolveNapiValueAddress(input.Get("pSwapchainImages")) : nullptr;
  auto XF = (PFN_vkGetSwapchainImagesKHR) vkGetInstanceProcAddr(NULL, "vkGetSwapchainImagesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetSwapchainImagesKHR) vkGetInstanceProcAddr(inst, "vkGetSwapchainImagesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetSwapchainImagesKHR) vkGetDeviceProcAddr(dev, "vkGetSwapchainImagesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetSwapchainImagesKHR");
    throw "cannot find function vkGetSwapchainImagesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSwapchainKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkImage *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkAcquireNextImageKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchain"));
  void * p2 = resolveNapiValueAddress(input.Get("timeout"));
  void * p3 = input.Has("semaphore") ? resolveNapiValueAddress(input.Get("semaphore")) : nullptr;
  void * p4 = input.Has("fence") ? resolveNapiValueAddress(input.Get("fence")) : nullptr;
  void * p5 = resolveNapiValueAddress(input.Get("pImageIndex"));
  auto XF = (PFN_vkAcquireNextImageKHR) vkGetInstanceProcAddr(NULL, "vkAcquireNextImageKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkAcquireNextImageKHR) vkGetInstanceProcAddr(inst, "vkAcquireNextImageKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkAcquireNextImageKHR) vkGetDeviceProcAddr(dev, "vkAcquireNextImageKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkAcquireNextImageKHR");
    throw "cannot find function vkAcquireNextImageKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSwapchainKHR *>(p1)[0],
    (uint64_t)(((uint64_t*)p2)[0]),
    reinterpret_cast< VkSemaphore *>(p3)[0],
    reinterpret_cast< VkFence *>(p4)[0],
    reinterpret_cast< uint32_t *>(p5)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkQueuePresentKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  void * p1 = resolveNapiValueAddress(input.Get("pPresentInfo"));
  auto XF = (PFN_vkQueuePresentKHR) vkGetInstanceProcAddr(NULL, "vkQueuePresentKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkQueuePresentKHR) vkGetInstanceProcAddr(inst, "vkQueuePresentKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkQueuePresentKHR) vkGetDeviceProcAddr(dev, "vkQueuePresentKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkQueuePresentKHR");
    throw "cannot find function vkQueuePresentKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkQueue *>(p0)[0],
    reinterpret_cast<const VkPresentInfoKHR *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceFeatures2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pFeatures"));
  auto XF = (PFN_vkGetPhysicalDeviceFeatures2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceFeatures2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFeatures2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceFeatures2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFeatures2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceFeatures2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceFeatures2");
    throw "cannot find function vkGetPhysicalDeviceFeatures2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceFeatures2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceProperties2");
    throw "cannot find function vkGetPhysicalDeviceProperties2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceProperties2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceFormatProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("format"));
  void * p2 = resolveNapiValueAddress(input.Get("pFormatProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceFormatProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceFormatProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFormatProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFormatProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceFormatProperties2");
    throw "cannot find function vkGetPhysicalDeviceFormatProperties2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (VkFormat)(((int32_t*)p1)[0]),
    reinterpret_cast< VkFormatProperties2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceImageFormatProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pImageFormatInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pImageFormatProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceImageFormatProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceImageFormatProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceImageFormatProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceImageFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceImageFormatProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceImageFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceImageFormatProperties2");
    throw "cannot find function vkGetPhysicalDeviceImageFormatProperties2";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2 *>(p1),
    reinterpret_cast< VkImageFormatProperties2 *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceQueueFamilyProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pQueueFamilyPropertyCount"));
  void * p2 = input.Has("pQueueFamilyProperties") ? resolveNapiValueAddress(input.Get("pQueueFamilyProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceQueueFamilyProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceQueueFamilyProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceQueueFamilyProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceQueueFamilyProperties2");
    throw "cannot find function vkGetPhysicalDeviceQueueFamilyProperties2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkQueueFamilyProperties2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceMemoryProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pMemoryProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceMemoryProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceMemoryProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMemoryProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceMemoryProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMemoryProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceMemoryProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceMemoryProperties2");
    throw "cannot find function vkGetPhysicalDeviceMemoryProperties2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkPhysicalDeviceMemoryProperties2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceSparseImageFormatProperties2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pFormatInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p3 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSparseImageFormatProperties2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSparseImageFormatProperties2");
    throw "cannot find function vkGetPhysicalDeviceSparseImageFormatProperties2";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2 *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSparseImageFormatProperties2 *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdPushDescriptorSetKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineBindPoint"));
  void * p2 = resolveNapiValueAddress(input.Get("layout"));
  void * p3 = resolveNapiValueAddress(input.Get("set"));
  void * p4 = resolveNapiValueAddress(input.Get("descriptorWriteCount"));
  void * p5 = resolveNapiValueAddress(input.Get("pDescriptorWrites"));
  auto XF = (PFN_vkCmdPushDescriptorSetKHR) vkGetInstanceProcAddr(NULL, "vkCmdPushDescriptorSetKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdPushDescriptorSetKHR) vkGetInstanceProcAddr(inst, "vkCmdPushDescriptorSetKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdPushDescriptorSetKHR) vkGetDeviceProcAddr(dev, "vkCmdPushDescriptorSetKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdPushDescriptorSetKHR");
    throw "cannot find function vkCmdPushDescriptorSetKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineBindPoint)(((int32_t*)p1)[0]),
    reinterpret_cast< VkPipelineLayout *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    reinterpret_cast<const VkWriteDescriptorSet *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkTrimCommandPool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("commandPool"));
  void * p2 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  auto XF = (PFN_vkTrimCommandPool) vkGetInstanceProcAddr(NULL, "vkTrimCommandPool");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkTrimCommandPool) vkGetInstanceProcAddr(inst, "vkTrimCommandPool");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkTrimCommandPool) vkGetDeviceProcAddr(dev, "vkTrimCommandPool");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkTrimCommandPool");
    throw "cannot find function vkTrimCommandPool";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkCommandPool *>(p1)[0],
    (VkCommandPoolTrimFlags)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceExternalBufferProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pExternalBufferInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pExternalBufferProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceExternalBufferProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceExternalBufferProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalBufferProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceExternalBufferProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalBufferProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceExternalBufferProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceExternalBufferProperties");
    throw "cannot find function vkGetPhysicalDeviceExternalBufferProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo *>(p1),
    reinterpret_cast< VkExternalBufferProperties *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceExternalSemaphoreProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pExternalSemaphoreInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pExternalSemaphoreProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceExternalSemaphoreProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceExternalSemaphoreProperties");
    throw "cannot find function vkGetPhysicalDeviceExternalSemaphoreProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo *>(p1),
    reinterpret_cast< VkExternalSemaphoreProperties *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceExternalFenceProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pExternalFenceInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pExternalFenceProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceExternalFenceProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceExternalFenceProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalFenceProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceExternalFenceProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceExternalFenceProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceExternalFenceProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceExternalFenceProperties");
    throw "cannot find function vkGetPhysicalDeviceExternalFenceProperties";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo *>(p1),
    reinterpret_cast< VkExternalFenceProperties *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkEnumeratePhysicalDeviceGroups(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("instance"));
  void * p1 = resolveNapiValueAddress(input.Get("pPhysicalDeviceGroupCount"));
  void * p2 = input.Has("pPhysicalDeviceGroupProperties") ? resolveNapiValueAddress(input.Get("pPhysicalDeviceGroupProperties")) : nullptr;
  auto XF = (PFN_vkEnumeratePhysicalDeviceGroups) vkGetInstanceProcAddr(NULL, "vkEnumeratePhysicalDeviceGroups");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkEnumeratePhysicalDeviceGroups) vkGetInstanceProcAddr(inst, "vkEnumeratePhysicalDeviceGroups");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkEnumeratePhysicalDeviceGroups) vkGetDeviceProcAddr(dev, "vkEnumeratePhysicalDeviceGroups");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkEnumeratePhysicalDeviceGroups");
    throw "cannot find function vkEnumeratePhysicalDeviceGroups";
  }

  int32_t out = XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkPhysicalDeviceGroupProperties *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceGroupPeerMemoryFeatures(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("heapIndex"));
  void * p2 = resolveNapiValueAddress(input.Get("localDeviceIndex"));
  void * p3 = resolveNapiValueAddress(input.Get("remoteDeviceIndex"));
  void * p4 = resolveNapiValueAddress(input.Get("pPeerMemoryFeatures"));
  auto XF = (PFN_vkGetDeviceGroupPeerMemoryFeatures) vkGetInstanceProcAddr(NULL, "vkGetDeviceGroupPeerMemoryFeatures");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceGroupPeerMemoryFeatures) vkGetInstanceProcAddr(inst, "vkGetDeviceGroupPeerMemoryFeatures");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceGroupPeerMemoryFeatures) vkGetDeviceProcAddr(dev, "vkGetDeviceGroupPeerMemoryFeatures");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceGroupPeerMemoryFeatures");
    throw "cannot find function vkGetDeviceGroupPeerMemoryFeatures";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast< VkPeerMemoryFeatureFlags *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkBindBufferMemory2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("bindInfoCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pBindInfos"));
  auto XF = (PFN_vkBindBufferMemory2) vkGetInstanceProcAddr(NULL, "vkBindBufferMemory2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBindBufferMemory2) vkGetInstanceProcAddr(inst, "vkBindBufferMemory2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBindBufferMemory2) vkGetDeviceProcAddr(dev, "vkBindBufferMemory2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBindBufferMemory2");
    throw "cannot find function vkBindBufferMemory2";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkBindBufferMemoryInfo *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkBindImageMemory2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("bindInfoCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pBindInfos"));
  auto XF = (PFN_vkBindImageMemory2) vkGetInstanceProcAddr(NULL, "vkBindImageMemory2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBindImageMemory2) vkGetInstanceProcAddr(inst, "vkBindImageMemory2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBindImageMemory2) vkGetDeviceProcAddr(dev, "vkBindImageMemory2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBindImageMemory2");
    throw "cannot find function vkBindImageMemory2";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkBindImageMemoryInfo *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetDeviceMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("deviceMask"));
  auto XF = (PFN_vkCmdSetDeviceMask) vkGetInstanceProcAddr(NULL, "vkCmdSetDeviceMask");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDeviceMask) vkGetInstanceProcAddr(inst, "vkCmdSetDeviceMask");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDeviceMask) vkGetDeviceProcAddr(dev, "vkCmdSetDeviceMask");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDeviceMask");
    throw "cannot find function vkCmdSetDeviceMask";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeviceGroupPresentCapabilitiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pDeviceGroupPresentCapabilities"));
  auto XF = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) vkGetInstanceProcAddr(NULL, "vkGetDeviceGroupPresentCapabilitiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) vkGetInstanceProcAddr(inst, "vkGetDeviceGroupPresentCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) vkGetDeviceProcAddr(dev, "vkGetDeviceGroupPresentCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceGroupPresentCapabilitiesKHR");
    throw "cannot find function vkGetDeviceGroupPresentCapabilitiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceGroupPresentCapabilitiesKHR *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceGroupSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("surface"));
  void * p2 = resolveNapiValueAddress(input.Get("pModes"));
  auto XF = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) vkGetInstanceProcAddr(NULL, "vkGetDeviceGroupSurfacePresentModesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) vkGetInstanceProcAddr(inst, "vkGetDeviceGroupSurfacePresentModesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) vkGetDeviceProcAddr(dev, "vkGetDeviceGroupSurfacePresentModesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceGroupSurfacePresentModesKHR");
    throw "cannot find function vkGetDeviceGroupSurfacePresentModesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast< VkDeviceGroupPresentModeFlagsKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkAcquireNextImage2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pAcquireInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pImageIndex"));
  auto XF = (PFN_vkAcquireNextImage2KHR) vkGetInstanceProcAddr(NULL, "vkAcquireNextImage2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkAcquireNextImage2KHR) vkGetInstanceProcAddr(inst, "vkAcquireNextImage2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkAcquireNextImage2KHR) vkGetDeviceProcAddr(dev, "vkAcquireNextImage2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkAcquireNextImage2KHR");
    throw "cannot find function vkAcquireNextImage2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkAcquireNextImageInfoKHR *>(p1),
    reinterpret_cast< uint32_t *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdDispatchBase(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("baseGroupX"));
  void * p2 = resolveNapiValueAddress(input.Get("baseGroupY"));
  void * p3 = resolveNapiValueAddress(input.Get("baseGroupZ"));
  void * p4 = resolveNapiValueAddress(input.Get("groupCountX"));
  void * p5 = resolveNapiValueAddress(input.Get("groupCountY"));
  void * p6 = resolveNapiValueAddress(input.Get("groupCountZ"));
  auto XF = (PFN_vkCmdDispatchBase) vkGetInstanceProcAddr(NULL, "vkCmdDispatchBase");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDispatchBase) vkGetInstanceProcAddr(inst, "vkCmdDispatchBase");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDispatchBase) vkGetDeviceProcAddr(dev, "vkCmdDispatchBase");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDispatchBase");
    throw "cannot find function vkCmdDispatchBase";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDevicePresentRectanglesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("surface"));
  void * p2 = resolveNapiValueAddress(input.Get("pRectCount"));
  void * p3 = input.Has("pRects") ? resolveNapiValueAddress(input.Get("pRects")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDevicePresentRectanglesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDevicePresentRectanglesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDevicePresentRectanglesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDevicePresentRectanglesKHR");
    throw "cannot find function vkGetPhysicalDevicePresentRectanglesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkSurfaceKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkRect2D *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pDescriptorUpdateTemplate"));
  auto XF = (PFN_vkCreateDescriptorUpdateTemplate) vkGetInstanceProcAddr(NULL, "vkCreateDescriptorUpdateTemplate");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDescriptorUpdateTemplate) vkGetInstanceProcAddr(inst, "vkCreateDescriptorUpdateTemplate");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDescriptorUpdateTemplate) vkGetDeviceProcAddr(dev, "vkCreateDescriptorUpdateTemplate");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDescriptorUpdateTemplate");
    throw "cannot find function vkCreateDescriptorUpdateTemplate";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkDescriptorUpdateTemplate *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("descriptorUpdateTemplate") ? resolveNapiValueAddress(input.Get("descriptorUpdateTemplate")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyDescriptorUpdateTemplate) vkGetInstanceProcAddr(NULL, "vkDestroyDescriptorUpdateTemplate");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyDescriptorUpdateTemplate) vkGetInstanceProcAddr(inst, "vkDestroyDescriptorUpdateTemplate");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyDescriptorUpdateTemplate) vkGetDeviceProcAddr(dev, "vkDestroyDescriptorUpdateTemplate");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyDescriptorUpdateTemplate");
    throw "cannot find function vkDestroyDescriptorUpdateTemplate";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorUpdateTemplate *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkUpdateDescriptorSetWithTemplate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("descriptorSet"));
  void * p2 = resolveNapiValueAddress(input.Get("descriptorUpdateTemplate"));
  void * p3 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkUpdateDescriptorSetWithTemplate) vkGetInstanceProcAddr(NULL, "vkUpdateDescriptorSetWithTemplate");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkUpdateDescriptorSetWithTemplate) vkGetInstanceProcAddr(inst, "vkUpdateDescriptorSetWithTemplate");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkUpdateDescriptorSetWithTemplate) vkGetDeviceProcAddr(dev, "vkUpdateDescriptorSetWithTemplate");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkUpdateDescriptorSetWithTemplate");
    throw "cannot find function vkUpdateDescriptorSetWithTemplate";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDescriptorSet *>(p1)[0],
    reinterpret_cast< VkDescriptorUpdateTemplate *>(p2)[0],
    &p3
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdPushDescriptorSetWithTemplateKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("descriptorUpdateTemplate"));
  void * p2 = resolveNapiValueAddress(input.Get("layout"));
  void * p3 = resolveNapiValueAddress(input.Get("set"));
  void * p4 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) vkGetInstanceProcAddr(NULL, "vkCmdPushDescriptorSetWithTemplateKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) vkGetInstanceProcAddr(inst, "vkCmdPushDescriptorSetWithTemplateKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) vkGetDeviceProcAddr(dev, "vkCmdPushDescriptorSetWithTemplateKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdPushDescriptorSetWithTemplateKHR");
    throw "cannot find function vkCmdPushDescriptorSetWithTemplateKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkDescriptorUpdateTemplate *>(p1)[0],
    reinterpret_cast< VkPipelineLayout *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0]),
    &p4
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkSetHdrMetadataEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchainCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pSwapchains"));
  void * p3 = resolveNapiValueAddress(input.Get("pMetadata"));
  auto XF = (PFN_vkSetHdrMetadataEXT) vkGetInstanceProcAddr(NULL, "vkSetHdrMetadataEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkSetHdrMetadataEXT) vkGetInstanceProcAddr(inst, "vkSetHdrMetadataEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkSetHdrMetadataEXT) vkGetDeviceProcAddr(dev, "vkSetHdrMetadataEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkSetHdrMetadataEXT");
    throw "cannot find function vkSetHdrMetadataEXT";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkSwapchainKHR *>(p2),
    reinterpret_cast<const VkHdrMetadataEXT *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetSwapchainStatusKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchain"));
  auto XF = (PFN_vkGetSwapchainStatusKHR) vkGetInstanceProcAddr(NULL, "vkGetSwapchainStatusKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetSwapchainStatusKHR) vkGetInstanceProcAddr(inst, "vkGetSwapchainStatusKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetSwapchainStatusKHR) vkGetDeviceProcAddr(dev, "vkGetSwapchainStatusKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetSwapchainStatusKHR");
    throw "cannot find function vkGetSwapchainStatusKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSwapchainKHR *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetSampleLocationsEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pSampleLocationsInfo"));
  auto XF = (PFN_vkCmdSetSampleLocationsEXT) vkGetInstanceProcAddr(NULL, "vkCmdSetSampleLocationsEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetSampleLocationsEXT) vkGetInstanceProcAddr(inst, "vkCmdSetSampleLocationsEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetSampleLocationsEXT) vkGetDeviceProcAddr(dev, "vkCmdSetSampleLocationsEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetSampleLocationsEXT");
    throw "cannot find function vkCmdSetSampleLocationsEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkSampleLocationsInfoEXT *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceMultisamplePropertiesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("samples"));
  void * p2 = resolveNapiValueAddress(input.Get("pMultisampleProperties"));
  auto XF = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceMultisamplePropertiesEXT");
    throw "cannot find function vkGetPhysicalDeviceMultisamplePropertiesEXT";
  }

  XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    (VkSampleCountFlagBits)(((uint32_t*)p1)[0]),
    reinterpret_cast< VkMultisamplePropertiesEXT *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pSurfaceInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSurfaceCapabilities"));
  auto XF = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    throw "cannot find function vkGetPhysicalDeviceSurfaceCapabilities2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR *>(p1),
    reinterpret_cast< VkSurfaceCapabilities2KHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceSurfaceFormats2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pSurfaceInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSurfaceFormatCount"));
  void * p3 = input.Has("pSurfaceFormats") ? resolveNapiValueAddress(input.Get("pSurfaceFormats")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceSurfaceFormats2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceSurfaceFormats2KHR");
    throw "cannot find function vkGetPhysicalDeviceSurfaceFormats2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSurfaceFormat2KHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceDisplayProperties2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceDisplayProperties2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceDisplayProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceDisplayProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceDisplayProperties2KHR");
    throw "cannot find function vkGetPhysicalDeviceDisplayProperties2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkDisplayProperties2KHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p2 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    throw "cannot find function vkGetPhysicalDeviceDisplayPlaneProperties2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkDisplayPlaneProperties2KHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDisplayModeProperties2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("display"));
  void * p2 = resolveNapiValueAddress(input.Get("pPropertyCount"));
  void * p3 = input.Has("pProperties") ? resolveNapiValueAddress(input.Get("pProperties")) : nullptr;
  auto XF = (PFN_vkGetDisplayModeProperties2KHR) vkGetInstanceProcAddr(NULL, "vkGetDisplayModeProperties2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDisplayModeProperties2KHR) vkGetInstanceProcAddr(inst, "vkGetDisplayModeProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDisplayModeProperties2KHR) vkGetDeviceProcAddr(dev, "vkGetDisplayModeProperties2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDisplayModeProperties2KHR");
    throw "cannot find function vkGetDisplayModeProperties2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< VkDisplayKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkDisplayModeProperties2KHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDisplayPlaneCapabilities2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pDisplayPlaneInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pCapabilities"));
  auto XF = (PFN_vkGetDisplayPlaneCapabilities2KHR) vkGetInstanceProcAddr(NULL, "vkGetDisplayPlaneCapabilities2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneCapabilities2KHR) vkGetInstanceProcAddr(inst, "vkGetDisplayPlaneCapabilities2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDisplayPlaneCapabilities2KHR) vkGetDeviceProcAddr(dev, "vkGetDisplayPlaneCapabilities2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDisplayPlaneCapabilities2KHR");
    throw "cannot find function vkGetDisplayPlaneCapabilities2KHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkDisplayPlaneInfo2KHR *>(p1),
    reinterpret_cast< VkDisplayPlaneCapabilities2KHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetBufferMemoryRequirements2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetBufferMemoryRequirements2) vkGetInstanceProcAddr(NULL, "vkGetBufferMemoryRequirements2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetBufferMemoryRequirements2) vkGetInstanceProcAddr(inst, "vkGetBufferMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetBufferMemoryRequirements2) vkGetDeviceProcAddr(dev, "vkGetBufferMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetBufferMemoryRequirements2");
    throw "cannot find function vkGetBufferMemoryRequirements2";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkBufferMemoryRequirementsInfo2 *>(p1),
    reinterpret_cast< VkMemoryRequirements2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetImageMemoryRequirements2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetImageMemoryRequirements2) vkGetInstanceProcAddr(NULL, "vkGetImageMemoryRequirements2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageMemoryRequirements2) vkGetInstanceProcAddr(inst, "vkGetImageMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageMemoryRequirements2) vkGetDeviceProcAddr(dev, "vkGetImageMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageMemoryRequirements2");
    throw "cannot find function vkGetImageMemoryRequirements2";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkImageMemoryRequirementsInfo2 *>(p1),
    reinterpret_cast< VkMemoryRequirements2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetImageSparseMemoryRequirements2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSparseMemoryRequirementCount"));
  void * p3 = input.Has("pSparseMemoryRequirements") ? resolveNapiValueAddress(input.Get("pSparseMemoryRequirements")) : nullptr;
  auto XF = (PFN_vkGetImageSparseMemoryRequirements2) vkGetInstanceProcAddr(NULL, "vkGetImageSparseMemoryRequirements2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageSparseMemoryRequirements2) vkGetInstanceProcAddr(inst, "vkGetImageSparseMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageSparseMemoryRequirements2) vkGetDeviceProcAddr(dev, "vkGetImageSparseMemoryRequirements2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageSparseMemoryRequirements2");
    throw "cannot find function vkGetImageSparseMemoryRequirements2";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2 *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSparseImageMemoryRequirements2 *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeviceBufferMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetDeviceBufferMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetDeviceBufferMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceBufferMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetDeviceBufferMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceBufferMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetDeviceBufferMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceBufferMemoryRequirements");
    throw "cannot find function vkGetDeviceBufferMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceBufferMemoryRequirements *>(p1),
    reinterpret_cast< VkMemoryRequirements2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeviceImageMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirements"));
  auto XF = (PFN_vkGetDeviceImageMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetDeviceImageMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceImageMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetDeviceImageMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceImageMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetDeviceImageMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceImageMemoryRequirements");
    throw "cannot find function vkGetDeviceImageMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceImageMemoryRequirements *>(p1),
    reinterpret_cast< VkMemoryRequirements2 *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeviceImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSparseMemoryRequirementCount"));
  void * p3 = input.Has("pSparseMemoryRequirements") ? resolveNapiValueAddress(input.Get("pSparseMemoryRequirements")) : nullptr;
  auto XF = (PFN_vkGetDeviceImageSparseMemoryRequirements) vkGetInstanceProcAddr(NULL, "vkGetDeviceImageSparseMemoryRequirements");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceImageSparseMemoryRequirements) vkGetInstanceProcAddr(inst, "vkGetDeviceImageSparseMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceImageSparseMemoryRequirements) vkGetDeviceProcAddr(dev, "vkGetDeviceImageSparseMemoryRequirements");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceImageSparseMemoryRequirements");
    throw "cannot find function vkGetDeviceImageSparseMemoryRequirements";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceImageMemoryRequirements *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkSparseImageMemoryRequirements2 *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateSamplerYcbcrConversion(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pYcbcrConversion"));
  auto XF = (PFN_vkCreateSamplerYcbcrConversion) vkGetInstanceProcAddr(NULL, "vkCreateSamplerYcbcrConversion");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateSamplerYcbcrConversion) vkGetInstanceProcAddr(inst, "vkCreateSamplerYcbcrConversion");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateSamplerYcbcrConversion) vkGetDeviceProcAddr(dev, "vkCreateSamplerYcbcrConversion");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateSamplerYcbcrConversion");
    throw "cannot find function vkCreateSamplerYcbcrConversion";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSamplerYcbcrConversion *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroySamplerYcbcrConversion(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("ycbcrConversion") ? resolveNapiValueAddress(input.Get("ycbcrConversion")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroySamplerYcbcrConversion) vkGetInstanceProcAddr(NULL, "vkDestroySamplerYcbcrConversion");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroySamplerYcbcrConversion) vkGetInstanceProcAddr(inst, "vkDestroySamplerYcbcrConversion");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroySamplerYcbcrConversion) vkGetDeviceProcAddr(dev, "vkDestroySamplerYcbcrConversion");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroySamplerYcbcrConversion");
    throw "cannot find function vkDestroySamplerYcbcrConversion";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSamplerYcbcrConversion *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeviceQueue2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pQueueInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pQueue"));
  auto XF = (PFN_vkGetDeviceQueue2) vkGetInstanceProcAddr(NULL, "vkGetDeviceQueue2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceQueue2) vkGetInstanceProcAddr(inst, "vkGetDeviceQueue2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceQueue2) vkGetDeviceProcAddr(dev, "vkGetDeviceQueue2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceQueue2");
    throw "cannot find function vkGetDeviceQueue2";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceQueueInfo2 *>(p1),
    reinterpret_cast< VkQueue *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateValidationCacheEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pValidationCache"));
  auto XF = (PFN_vkCreateValidationCacheEXT) vkGetInstanceProcAddr(NULL, "vkCreateValidationCacheEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateValidationCacheEXT) vkGetInstanceProcAddr(inst, "vkCreateValidationCacheEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateValidationCacheEXT) vkGetDeviceProcAddr(dev, "vkCreateValidationCacheEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateValidationCacheEXT");
    throw "cannot find function vkCreateValidationCacheEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkValidationCacheCreateInfoEXT *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkValidationCacheEXT *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyValidationCacheEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("validationCache") ? resolveNapiValueAddress(input.Get("validationCache")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyValidationCacheEXT) vkGetInstanceProcAddr(NULL, "vkDestroyValidationCacheEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyValidationCacheEXT) vkGetInstanceProcAddr(inst, "vkDestroyValidationCacheEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyValidationCacheEXT) vkGetDeviceProcAddr(dev, "vkDestroyValidationCacheEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyValidationCacheEXT");
    throw "cannot find function vkDestroyValidationCacheEXT";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkValidationCacheEXT *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetValidationCacheDataEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("validationCache"));
  void * p2 = resolveNapiValueAddress(input.Get("pDataSize"));
  void * p3 = input.Has("pData") ? resolveNapiValueAddress(input.Get("pData")) : nullptr;
  auto XF = (PFN_vkGetValidationCacheDataEXT) vkGetInstanceProcAddr(NULL, "vkGetValidationCacheDataEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetValidationCacheDataEXT) vkGetInstanceProcAddr(inst, "vkGetValidationCacheDataEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetValidationCacheDataEXT) vkGetDeviceProcAddr(dev, "vkGetValidationCacheDataEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetValidationCacheDataEXT");
    throw "cannot find function vkGetValidationCacheDataEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkValidationCacheEXT *>(p1)[0],
    reinterpret_cast< size_t *>(p2),
    &p3
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkMergeValidationCachesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("dstCache"));
  void * p2 = resolveNapiValueAddress(input.Get("srcCacheCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pSrcCaches"));
  auto XF = (PFN_vkMergeValidationCachesEXT) vkGetInstanceProcAddr(NULL, "vkMergeValidationCachesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkMergeValidationCachesEXT) vkGetInstanceProcAddr(inst, "vkMergeValidationCachesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkMergeValidationCachesEXT) vkGetDeviceProcAddr(dev, "vkMergeValidationCachesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkMergeValidationCachesEXT");
    throw "cannot find function vkMergeValidationCachesEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkValidationCacheEXT *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkValidationCacheEXT *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDescriptorSetLayoutSupport(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSupport"));
  auto XF = (PFN_vkGetDescriptorSetLayoutSupport) vkGetInstanceProcAddr(NULL, "vkGetDescriptorSetLayoutSupport");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDescriptorSetLayoutSupport) vkGetInstanceProcAddr(inst, "vkGetDescriptorSetLayoutSupport");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDescriptorSetLayoutSupport) vkGetDeviceProcAddr(dev, "vkGetDescriptorSetLayoutSupport");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDescriptorSetLayoutSupport");
    throw "cannot find function vkGetDescriptorSetLayoutSupport";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDescriptorSetLayoutCreateInfo *>(p1),
    reinterpret_cast< VkDescriptorSetLayoutSupport *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetMemoryHostPointerPropertiesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("handleType"));
  void * p2 = resolveNapiValueAddress(input.Get("pHostPointer"));
  void * p3 = resolveNapiValueAddress(input.Get("pMemoryHostPointerProperties"));
  auto XF = (PFN_vkGetMemoryHostPointerPropertiesEXT) vkGetInstanceProcAddr(NULL, "vkGetMemoryHostPointerPropertiesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetMemoryHostPointerPropertiesEXT) vkGetInstanceProcAddr(inst, "vkGetMemoryHostPointerPropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetMemoryHostPointerPropertiesEXT) vkGetDeviceProcAddr(dev, "vkGetMemoryHostPointerPropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetMemoryHostPointerPropertiesEXT");
    throw "cannot find function vkGetMemoryHostPointerPropertiesEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (VkExternalMemoryHandleTypeFlagBits)(((uint32_t*)p1)[0]),
    &p2,
    reinterpret_cast< VkMemoryHostPointerPropertiesEXT *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateRenderPass2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pRenderPass"));
  auto XF = (PFN_vkCreateRenderPass2) vkGetInstanceProcAddr(NULL, "vkCreateRenderPass2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateRenderPass2) vkGetInstanceProcAddr(inst, "vkCreateRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateRenderPass2) vkGetDeviceProcAddr(dev, "vkCreateRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateRenderPass2");
    throw "cannot find function vkCreateRenderPass2";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkRenderPassCreateInfo2 *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkRenderPass *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdBeginRenderPass2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pRenderPassBegin"));
  void * p2 = resolveNapiValueAddress(input.Get("pSubpassBeginInfo"));
  auto XF = (PFN_vkCmdBeginRenderPass2) vkGetInstanceProcAddr(NULL, "vkCmdBeginRenderPass2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginRenderPass2) vkGetInstanceProcAddr(inst, "vkCmdBeginRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginRenderPass2) vkGetDeviceProcAddr(dev, "vkCmdBeginRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginRenderPass2");
    throw "cannot find function vkCmdBeginRenderPass2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkRenderPassBeginInfo *>(p1),
    reinterpret_cast<const VkSubpassBeginInfo *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdNextSubpass2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pSubpassBeginInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pSubpassEndInfo"));
  auto XF = (PFN_vkCmdNextSubpass2) vkGetInstanceProcAddr(NULL, "vkCmdNextSubpass2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdNextSubpass2) vkGetInstanceProcAddr(inst, "vkCmdNextSubpass2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdNextSubpass2) vkGetDeviceProcAddr(dev, "vkCmdNextSubpass2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdNextSubpass2");
    throw "cannot find function vkCmdNextSubpass2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkSubpassBeginInfo *>(p1),
    reinterpret_cast<const VkSubpassEndInfo *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndRenderPass2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pSubpassEndInfo"));
  auto XF = (PFN_vkCmdEndRenderPass2) vkGetInstanceProcAddr(NULL, "vkCmdEndRenderPass2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndRenderPass2) vkGetInstanceProcAddr(inst, "vkCmdEndRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndRenderPass2) vkGetDeviceProcAddr(dev, "vkCmdEndRenderPass2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndRenderPass2");
    throw "cannot find function vkCmdEndRenderPass2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkSubpassEndInfo *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetSemaphoreCounterValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("semaphore"));
  void * p2 = resolveNapiValueAddress(input.Get("pValue"));
  auto XF = (PFN_vkGetSemaphoreCounterValue) vkGetInstanceProcAddr(NULL, "vkGetSemaphoreCounterValue");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetSemaphoreCounterValue) vkGetInstanceProcAddr(inst, "vkGetSemaphoreCounterValue");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetSemaphoreCounterValue) vkGetDeviceProcAddr(dev, "vkGetSemaphoreCounterValue");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetSemaphoreCounterValue");
    throw "cannot find function vkGetSemaphoreCounterValue";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSemaphore *>(p1)[0],
    reinterpret_cast< uint64_t *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkWaitSemaphores(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pWaitInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("timeout"));
  auto XF = (PFN_vkWaitSemaphores) vkGetInstanceProcAddr(NULL, "vkWaitSemaphores");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkWaitSemaphores) vkGetInstanceProcAddr(inst, "vkWaitSemaphores");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkWaitSemaphores) vkGetDeviceProcAddr(dev, "vkWaitSemaphores");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkWaitSemaphores");
    throw "cannot find function vkWaitSemaphores";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSemaphoreWaitInfo *>(p1),
    (uint64_t)(((uint64_t*)p2)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkSignalSemaphore(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pSignalInfo"));
  auto XF = (PFN_vkSignalSemaphore) vkGetInstanceProcAddr(NULL, "vkSignalSemaphore");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkSignalSemaphore) vkGetInstanceProcAddr(inst, "vkSignalSemaphore");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkSignalSemaphore) vkGetDeviceProcAddr(dev, "vkSignalSemaphore");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkSignalSemaphore");
    throw "cannot find function vkSignalSemaphore";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkSemaphoreSignalInfo *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdDrawIndirectCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("countBuffer"));
  void * p4 = resolveNapiValueAddress(input.Get("countBufferOffset"));
  void * p5 = resolveNapiValueAddress(input.Get("maxDrawCount"));
  void * p6 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawIndirectCount) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndirectCount");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndirectCount) vkGetInstanceProcAddr(inst, "vkCmdDrawIndirectCount");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndirectCount) vkGetDeviceProcAddr(dev, "vkCmdDrawIndirectCount");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndirectCount");
    throw "cannot find function vkCmdDrawIndirectCount";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    reinterpret_cast< VkBuffer *>(p3)[0],
    (VkDeviceSize)(((VkDeviceSize*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawIndexedIndirectCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("countBuffer"));
  void * p4 = resolveNapiValueAddress(input.Get("countBufferOffset"));
  void * p5 = resolveNapiValueAddress(input.Get("maxDrawCount"));
  void * p6 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawIndexedIndirectCount) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndexedIndirectCount");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndexedIndirectCount) vkGetInstanceProcAddr(inst, "vkCmdDrawIndexedIndirectCount");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndexedIndirectCount) vkGetDeviceProcAddr(dev, "vkCmdDrawIndexedIndirectCount");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndexedIndirectCount");
    throw "cannot find function vkCmdDrawIndexedIndirectCount";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    reinterpret_cast< VkBuffer *>(p3)[0],
    (VkDeviceSize)(((VkDeviceSize*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBindTransformFeedbackBuffersEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstBinding"));
  void * p2 = resolveNapiValueAddress(input.Get("bindingCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pBuffers"));
  void * p4 = resolveNapiValueAddress(input.Get("pOffsets"));
  void * p5 = input.Has("pSizes") ? resolveNapiValueAddress(input.Get("pSizes")) : nullptr;
  auto XF = (PFN_vkCmdBindTransformFeedbackBuffersEXT) vkGetInstanceProcAddr(NULL, "vkCmdBindTransformFeedbackBuffersEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindTransformFeedbackBuffersEXT) vkGetInstanceProcAddr(inst, "vkCmdBindTransformFeedbackBuffersEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindTransformFeedbackBuffersEXT) vkGetDeviceProcAddr(dev, "vkCmdBindTransformFeedbackBuffersEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindTransformFeedbackBuffersEXT");
    throw "cannot find function vkCmdBindTransformFeedbackBuffersEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBuffer *>(p3),
    reinterpret_cast<const VkDeviceSize *>(p4),
    reinterpret_cast<const VkDeviceSize *>(p5)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBeginTransformFeedbackEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstCounterBuffer"));
  void * p2 = input.Has("counterBufferCount") ? resolveNapiValueAddress(input.Get("counterBufferCount")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pCounterBuffers"));
  void * p4 = input.Has("pCounterBufferOffsets") ? resolveNapiValueAddress(input.Get("pCounterBufferOffsets")) : nullptr;
  auto XF = (PFN_vkCmdBeginTransformFeedbackEXT) vkGetInstanceProcAddr(NULL, "vkCmdBeginTransformFeedbackEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginTransformFeedbackEXT) vkGetInstanceProcAddr(inst, "vkCmdBeginTransformFeedbackEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginTransformFeedbackEXT) vkGetDeviceProcAddr(dev, "vkCmdBeginTransformFeedbackEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginTransformFeedbackEXT");
    throw "cannot find function vkCmdBeginTransformFeedbackEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBuffer *>(p3),
    reinterpret_cast<const VkDeviceSize *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndTransformFeedbackEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstCounterBuffer"));
  void * p2 = input.Has("counterBufferCount") ? resolveNapiValueAddress(input.Get("counterBufferCount")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pCounterBuffers"));
  void * p4 = input.Has("pCounterBufferOffsets") ? resolveNapiValueAddress(input.Get("pCounterBufferOffsets")) : nullptr;
  auto XF = (PFN_vkCmdEndTransformFeedbackEXT) vkGetInstanceProcAddr(NULL, "vkCmdEndTransformFeedbackEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndTransformFeedbackEXT) vkGetInstanceProcAddr(inst, "vkCmdEndTransformFeedbackEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndTransformFeedbackEXT) vkGetDeviceProcAddr(dev, "vkCmdEndTransformFeedbackEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndTransformFeedbackEXT");
    throw "cannot find function vkCmdEndTransformFeedbackEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBuffer *>(p3),
    reinterpret_cast<const VkDeviceSize *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBeginQueryIndexedEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("query"));
  void * p3 = input.Has("flags") ? resolveNapiValueAddress(input.Get("flags")) : nullptr;
  void * p4 = resolveNapiValueAddress(input.Get("index"));
  auto XF = (PFN_vkCmdBeginQueryIndexedEXT) vkGetInstanceProcAddr(NULL, "vkCmdBeginQueryIndexedEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginQueryIndexedEXT) vkGetInstanceProcAddr(inst, "vkCmdBeginQueryIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginQueryIndexedEXT) vkGetDeviceProcAddr(dev, "vkCmdBeginQueryIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginQueryIndexedEXT");
    throw "cannot find function vkCmdBeginQueryIndexedEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (VkQueryControlFlags)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndQueryIndexedEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p2 = resolveNapiValueAddress(input.Get("query"));
  void * p3 = resolveNapiValueAddress(input.Get("index"));
  auto XF = (PFN_vkCmdEndQueryIndexedEXT) vkGetInstanceProcAddr(NULL, "vkCmdEndQueryIndexedEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndQueryIndexedEXT) vkGetInstanceProcAddr(inst, "vkCmdEndQueryIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndQueryIndexedEXT) vkGetDeviceProcAddr(dev, "vkCmdEndQueryIndexedEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndQueryIndexedEXT");
    throw "cannot find function vkCmdEndQueryIndexedEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkQueryPool *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawIndirectByteCountEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("instanceCount"));
  void * p2 = resolveNapiValueAddress(input.Get("firstInstance"));
  void * p3 = resolveNapiValueAddress(input.Get("counterBuffer"));
  void * p4 = resolveNapiValueAddress(input.Get("counterBufferOffset"));
  void * p5 = resolveNapiValueAddress(input.Get("counterOffset"));
  void * p6 = resolveNapiValueAddress(input.Get("vertexStride"));
  auto XF = (PFN_vkCmdDrawIndirectByteCountEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawIndirectByteCountEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawIndirectByteCountEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawIndirectByteCountEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawIndirectByteCountEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawIndirectByteCountEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawIndirectByteCountEXT");
    throw "cannot find function vkCmdDrawIndirectByteCountEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast< VkBuffer *>(p3)[0],
    (VkDeviceSize)(((VkDeviceSize*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawMeshTasksEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("groupCountX"));
  void * p2 = resolveNapiValueAddress(input.Get("groupCountY"));
  void * p3 = resolveNapiValueAddress(input.Get("groupCountZ"));
  auto XF = (PFN_vkCmdDrawMeshTasksEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawMeshTasksEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawMeshTasksEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawMeshTasksEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawMeshTasksEXT");
    throw "cannot find function vkCmdDrawMeshTasksEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawMeshTasksIndirectEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("drawCount"));
  void * p4 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawMeshTasksIndirectEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawMeshTasksIndirectEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksIndirectEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawMeshTasksIndirectEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksIndirectEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawMeshTasksIndirectEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawMeshTasksIndirectEXT");
    throw "cannot find function vkCmdDrawMeshTasksIndirectEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdDrawMeshTasksIndirectCountEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("buffer"));
  void * p2 = resolveNapiValueAddress(input.Get("offset"));
  void * p3 = resolveNapiValueAddress(input.Get("countBuffer"));
  void * p4 = resolveNapiValueAddress(input.Get("countBufferOffset"));
  void * p5 = resolveNapiValueAddress(input.Get("maxDrawCount"));
  void * p6 = resolveNapiValueAddress(input.Get("stride"));
  auto XF = (PFN_vkCmdDrawMeshTasksIndirectCountEXT) vkGetInstanceProcAddr(NULL, "vkCmdDrawMeshTasksIndirectCountEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksIndirectCountEXT) vkGetInstanceProcAddr(inst, "vkCmdDrawMeshTasksIndirectCountEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdDrawMeshTasksIndirectCountEXT) vkGetDeviceProcAddr(dev, "vkCmdDrawMeshTasksIndirectCountEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdDrawMeshTasksIndirectCountEXT");
    throw "cannot find function vkCmdDrawMeshTasksIndirectCountEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkBuffer *>(p1)[0],
    (VkDeviceSize)(((VkDeviceSize*)p2)[0]),
    reinterpret_cast< VkBuffer *>(p3)[0],
    (VkDeviceSize)(((VkDeviceSize*)p4)[0]),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdTraceRaysKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pRaygenShaderBindingTable"));
  void * p2 = resolveNapiValueAddress(input.Get("pMissShaderBindingTable"));
  void * p3 = resolveNapiValueAddress(input.Get("pHitShaderBindingTable"));
  void * p4 = resolveNapiValueAddress(input.Get("pCallableShaderBindingTable"));
  void * p5 = resolveNapiValueAddress(input.Get("width"));
  void * p6 = resolveNapiValueAddress(input.Get("height"));
  void * p7 = resolveNapiValueAddress(input.Get("depth"));
  auto XF = (PFN_vkCmdTraceRaysKHR) vkGetInstanceProcAddr(NULL, "vkCmdTraceRaysKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdTraceRaysKHR) vkGetInstanceProcAddr(inst, "vkCmdTraceRaysKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdTraceRaysKHR) vkGetDeviceProcAddr(dev, "vkCmdTraceRaysKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdTraceRaysKHR");
    throw "cannot find function vkCmdTraceRaysKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p1),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p2),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p3),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p4),
    (uint32_t)(((uint32_t*)p5)[0]),
    (uint32_t)(((uint32_t*)p6)[0]),
    (uint32_t)(((uint32_t*)p7)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetRayTracingShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pipeline"));
  void * p2 = resolveNapiValueAddress(input.Get("firstGroup"));
  void * p3 = resolveNapiValueAddress(input.Get("groupCount"));
  void * p4 = resolveNapiValueAddress(input.Get("dataSize"));
  void * p5 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkGetRayTracingShaderGroupHandlesKHR) vkGetInstanceProcAddr(NULL, "vkGetRayTracingShaderGroupHandlesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetRayTracingShaderGroupHandlesKHR) vkGetInstanceProcAddr(inst, "vkGetRayTracingShaderGroupHandlesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetRayTracingShaderGroupHandlesKHR) vkGetDeviceProcAddr(dev, "vkGetRayTracingShaderGroupHandlesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetRayTracingShaderGroupHandlesKHR");
    throw "cannot find function vkGetRayTracingShaderGroupHandlesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipeline *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (size_t)(((size_t*)p4)[0]),
    &p5
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pipeline"));
  void * p2 = resolveNapiValueAddress(input.Get("firstGroup"));
  void * p3 = resolveNapiValueAddress(input.Get("groupCount"));
  void * p4 = resolveNapiValueAddress(input.Get("dataSize"));
  void * p5 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR) vkGetInstanceProcAddr(NULL, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR) vkGetInstanceProcAddr(inst, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR) vkGetDeviceProcAddr(dev, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    throw "cannot find function vkGetRayTracingCaptureReplayShaderGroupHandlesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipeline *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (uint32_t)(((uint32_t*)p3)[0]),
    (size_t)(((size_t*)p4)[0]),
    &p5
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateRayTracingPipelinesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("deferredOperation") ? resolveNapiValueAddress(input.Get("deferredOperation")) : nullptr;
  void * p2 = input.Has("pipelineCache") ? resolveNapiValueAddress(input.Get("pipelineCache")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("createInfoCount"));
  void * p4 = resolveNapiValueAddress(input.Get("pCreateInfos"));
  void * p5 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p6 = resolveNapiValueAddress(input.Get("pPipelines"));
  auto XF = (PFN_vkCreateRayTracingPipelinesKHR) vkGetInstanceProcAddr(NULL, "vkCreateRayTracingPipelinesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateRayTracingPipelinesKHR) vkGetInstanceProcAddr(inst, "vkCreateRayTracingPipelinesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateRayTracingPipelinesKHR) vkGetDeviceProcAddr(dev, "vkCreateRayTracingPipelinesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateRayTracingPipelinesKHR");
    throw "cannot find function vkCreateRayTracingPipelinesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeferredOperationKHR *>(p1)[0],
    reinterpret_cast< VkPipelineCache *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0]),
    reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR *>(p4),
    reinterpret_cast<const VkAllocationCallbacks *>(p5),
    reinterpret_cast< VkPipeline *>(p6)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdTraceRaysIndirectKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pRaygenShaderBindingTable"));
  void * p2 = resolveNapiValueAddress(input.Get("pMissShaderBindingTable"));
  void * p3 = resolveNapiValueAddress(input.Get("pHitShaderBindingTable"));
  void * p4 = resolveNapiValueAddress(input.Get("pCallableShaderBindingTable"));
  void * p5 = resolveNapiValueAddress(input.Get("indirectDeviceAddress"));
  auto XF = (PFN_vkCmdTraceRaysIndirectKHR) vkGetInstanceProcAddr(NULL, "vkCmdTraceRaysIndirectKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdTraceRaysIndirectKHR) vkGetInstanceProcAddr(inst, "vkCmdTraceRaysIndirectKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdTraceRaysIndirectKHR) vkGetDeviceProcAddr(dev, "vkCmdTraceRaysIndirectKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdTraceRaysIndirectKHR");
    throw "cannot find function vkCmdTraceRaysIndirectKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p1),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p2),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p3),
    reinterpret_cast<const VkStridedDeviceAddressRegionKHR *>(p4),
    (VkDeviceAddress)(((VkDeviceAddress*)p5)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdTraceRaysIndirect2KHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("indirectDeviceAddress"));
  auto XF = (PFN_vkCmdTraceRaysIndirect2KHR) vkGetInstanceProcAddr(NULL, "vkCmdTraceRaysIndirect2KHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdTraceRaysIndirect2KHR) vkGetInstanceProcAddr(inst, "vkCmdTraceRaysIndirect2KHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdTraceRaysIndirect2KHR) vkGetDeviceProcAddr(dev, "vkCmdTraceRaysIndirect2KHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdTraceRaysIndirect2KHR");
    throw "cannot find function vkCmdTraceRaysIndirect2KHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkDeviceAddress)(((VkDeviceAddress*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetRayTracingShaderGroupStackSizeKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pipeline"));
  void * p2 = resolveNapiValueAddress(input.Get("group"));
  void * p3 = resolveNapiValueAddress(input.Get("groupShader"));
  auto XF = (PFN_vkGetRayTracingShaderGroupStackSizeKHR) vkGetInstanceProcAddr(NULL, "vkGetRayTracingShaderGroupStackSizeKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetRayTracingShaderGroupStackSizeKHR) vkGetInstanceProcAddr(inst, "vkGetRayTracingShaderGroupStackSizeKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetRayTracingShaderGroupStackSizeKHR) vkGetDeviceProcAddr(dev, "vkGetRayTracingShaderGroupStackSizeKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetRayTracingShaderGroupStackSizeKHR");
    throw "cannot find function vkGetRayTracingShaderGroupStackSizeKHR";
  }

  uint64_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPipeline *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    (VkShaderGroupShaderKHR)(((int32_t*)p3)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetRayTracingPipelineStackSizeKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pipelineStackSize"));
  auto XF = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR) vkGetInstanceProcAddr(NULL, "vkCmdSetRayTracingPipelineStackSizeKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR) vkGetInstanceProcAddr(inst, "vkCmdSetRayTracingPipelineStackSizeKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR) vkGetDeviceProcAddr(dev, "vkCmdSetRayTracingPipelineStackSizeKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetRayTracingPipelineStackSizeKHR");
    throw "cannot find function vkCmdSetRayTracingPipelineStackSizeKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetImageDrmFormatModifierPropertiesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("image"));
  void * p2 = resolveNapiValueAddress(input.Get("pProperties"));
  auto XF = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) vkGetInstanceProcAddr(NULL, "vkGetImageDrmFormatModifierPropertiesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) vkGetInstanceProcAddr(inst, "vkGetImageDrmFormatModifierPropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) vkGetDeviceProcAddr(dev, "vkGetImageDrmFormatModifierPropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetImageDrmFormatModifierPropertiesEXT");
    throw "cannot find function vkGetImageDrmFormatModifierPropertiesEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkImage *>(p1)[0],
    reinterpret_cast< VkImageDrmFormatModifierPropertiesEXT *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetBufferOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  auto XF = (PFN_vkGetBufferOpaqueCaptureAddress) vkGetInstanceProcAddr(NULL, "vkGetBufferOpaqueCaptureAddress");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetBufferOpaqueCaptureAddress) vkGetInstanceProcAddr(inst, "vkGetBufferOpaqueCaptureAddress");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetBufferOpaqueCaptureAddress) vkGetDeviceProcAddr(dev, "vkGetBufferOpaqueCaptureAddress");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetBufferOpaqueCaptureAddress");
    throw "cannot find function vkGetBufferOpaqueCaptureAddress";
  }

  uint64_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkBufferDeviceAddressInfo *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetBufferDeviceAddress(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  auto XF = (PFN_vkGetBufferDeviceAddress) vkGetInstanceProcAddr(NULL, "vkGetBufferDeviceAddress");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetBufferDeviceAddress) vkGetInstanceProcAddr(inst, "vkGetBufferDeviceAddress");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetBufferDeviceAddress) vkGetDeviceProcAddr(dev, "vkGetBufferDeviceAddress");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetBufferDeviceAddress");
    throw "cannot find function vkGetBufferDeviceAddress";
  }

  uint64_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkBufferDeviceAddressInfo *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateHeadlessSurfaceEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("instance"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pSurface"));
  auto XF = (PFN_vkCreateHeadlessSurfaceEXT) vkGetInstanceProcAddr(NULL, "vkCreateHeadlessSurfaceEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateHeadlessSurfaceEXT) vkGetInstanceProcAddr(inst, "vkCreateHeadlessSurfaceEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateHeadlessSurfaceEXT) vkGetDeviceProcAddr(dev, "vkCreateHeadlessSurfaceEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateHeadlessSurfaceEXT");
    throw "cannot find function vkCreateHeadlessSurfaceEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkInstance *>(p0)[0],
    reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkSurfaceKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeviceMemoryOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pInfo"));
  auto XF = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) vkGetInstanceProcAddr(NULL, "vkGetDeviceMemoryOpaqueCaptureAddress");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) vkGetInstanceProcAddr(inst, "vkGetDeviceMemoryOpaqueCaptureAddress");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) vkGetDeviceProcAddr(dev, "vkGetDeviceMemoryOpaqueCaptureAddress");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeviceMemoryOpaqueCaptureAddress");
    throw "cannot find function vkGetDeviceMemoryOpaqueCaptureAddress";
  }

  uint64_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo *>(p1)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetLineStippleEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("lineStippleFactor"));
  void * p2 = resolveNapiValueAddress(input.Get("lineStipplePattern"));
  auto XF = (PFN_vkCmdSetLineStippleEXT) vkGetInstanceProcAddr(NULL, "vkCmdSetLineStippleEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetLineStippleEXT) vkGetInstanceProcAddr(inst, "vkCmdSetLineStippleEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetLineStippleEXT) vkGetDeviceProcAddr(dev, "vkCmdSetLineStippleEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetLineStippleEXT");
    throw "cannot find function vkCmdSetLineStippleEXT";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint16_t)(((uint16_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceToolProperties(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pToolCount"));
  void * p2 = input.Has("pToolProperties") ? resolveNapiValueAddress(input.Get("pToolProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceToolProperties) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceToolProperties");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceToolProperties) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceToolProperties");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceToolProperties) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceToolProperties");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceToolProperties");
    throw "cannot find function vkGetPhysicalDeviceToolProperties";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkPhysicalDeviceToolProperties *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateDeferredOperationKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pDeferredOperation"));
  auto XF = (PFN_vkCreateDeferredOperationKHR) vkGetInstanceProcAddr(NULL, "vkCreateDeferredOperationKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateDeferredOperationKHR) vkGetInstanceProcAddr(inst, "vkCreateDeferredOperationKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateDeferredOperationKHR) vkGetDeviceProcAddr(dev, "vkCreateDeferredOperationKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateDeferredOperationKHR");
    throw "cannot find function vkCreateDeferredOperationKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p1),
    reinterpret_cast< VkDeferredOperationKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyDeferredOperationKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("operation") ? resolveNapiValueAddress(input.Get("operation")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyDeferredOperationKHR) vkGetInstanceProcAddr(NULL, "vkDestroyDeferredOperationKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyDeferredOperationKHR) vkGetInstanceProcAddr(inst, "vkDestroyDeferredOperationKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyDeferredOperationKHR) vkGetDeviceProcAddr(dev, "vkDestroyDeferredOperationKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyDeferredOperationKHR");
    throw "cannot find function vkDestroyDeferredOperationKHR";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeferredOperationKHR *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetDeferredOperationMaxConcurrencyKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("operation"));
  auto XF = (PFN_vkGetDeferredOperationMaxConcurrencyKHR) vkGetInstanceProcAddr(NULL, "vkGetDeferredOperationMaxConcurrencyKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeferredOperationMaxConcurrencyKHR) vkGetInstanceProcAddr(inst, "vkGetDeferredOperationMaxConcurrencyKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeferredOperationMaxConcurrencyKHR) vkGetDeviceProcAddr(dev, "vkGetDeferredOperationMaxConcurrencyKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeferredOperationMaxConcurrencyKHR");
    throw "cannot find function vkGetDeferredOperationMaxConcurrencyKHR";
  }

  uint32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeferredOperationKHR *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetDeferredOperationResultKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("operation"));
  auto XF = (PFN_vkGetDeferredOperationResultKHR) vkGetInstanceProcAddr(NULL, "vkGetDeferredOperationResultKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetDeferredOperationResultKHR) vkGetInstanceProcAddr(inst, "vkGetDeferredOperationResultKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetDeferredOperationResultKHR) vkGetDeviceProcAddr(dev, "vkGetDeferredOperationResultKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetDeferredOperationResultKHR");
    throw "cannot find function vkGetDeferredOperationResultKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeferredOperationKHR *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDeferredOperationJoinKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("operation"));
  auto XF = (PFN_vkDeferredOperationJoinKHR) vkGetInstanceProcAddr(NULL, "vkDeferredOperationJoinKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDeferredOperationJoinKHR) vkGetInstanceProcAddr(inst, "vkDeferredOperationJoinKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDeferredOperationJoinKHR) vkGetDeviceProcAddr(dev, "vkDeferredOperationJoinKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDeferredOperationJoinKHR");
    throw "cannot find function vkDeferredOperationJoinKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeferredOperationKHR *>(p1)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetCullMode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("cullMode") ? resolveNapiValueAddress(input.Get("cullMode")) : nullptr;
  auto XF = (PFN_vkCmdSetCullMode) vkGetInstanceProcAddr(NULL, "vkCmdSetCullMode");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetCullMode) vkGetInstanceProcAddr(inst, "vkCmdSetCullMode");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetCullMode) vkGetDeviceProcAddr(dev, "vkCmdSetCullMode");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetCullMode");
    throw "cannot find function vkCmdSetCullMode";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkCullModeFlags)(((uint32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetFrontFace(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("frontFace"));
  auto XF = (PFN_vkCmdSetFrontFace) vkGetInstanceProcAddr(NULL, "vkCmdSetFrontFace");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetFrontFace) vkGetInstanceProcAddr(inst, "vkCmdSetFrontFace");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetFrontFace) vkGetDeviceProcAddr(dev, "vkCmdSetFrontFace");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetFrontFace");
    throw "cannot find function vkCmdSetFrontFace";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkFrontFace)(((int32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetPrimitiveTopology(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("primitiveTopology"));
  auto XF = (PFN_vkCmdSetPrimitiveTopology) vkGetInstanceProcAddr(NULL, "vkCmdSetPrimitiveTopology");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetPrimitiveTopology) vkGetInstanceProcAddr(inst, "vkCmdSetPrimitiveTopology");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetPrimitiveTopology) vkGetDeviceProcAddr(dev, "vkCmdSetPrimitiveTopology");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetPrimitiveTopology");
    throw "cannot find function vkCmdSetPrimitiveTopology";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPrimitiveTopology)(((int32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetViewportWithCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("viewportCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pViewports"));
  auto XF = (PFN_vkCmdSetViewportWithCount) vkGetInstanceProcAddr(NULL, "vkCmdSetViewportWithCount");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetViewportWithCount) vkGetInstanceProcAddr(inst, "vkCmdSetViewportWithCount");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetViewportWithCount) vkGetDeviceProcAddr(dev, "vkCmdSetViewportWithCount");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetViewportWithCount");
    throw "cannot find function vkCmdSetViewportWithCount";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkViewport *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetScissorWithCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("scissorCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pScissors"));
  auto XF = (PFN_vkCmdSetScissorWithCount) vkGetInstanceProcAddr(NULL, "vkCmdSetScissorWithCount");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetScissorWithCount) vkGetInstanceProcAddr(inst, "vkCmdSetScissorWithCount");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetScissorWithCount) vkGetDeviceProcAddr(dev, "vkCmdSetScissorWithCount");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetScissorWithCount");
    throw "cannot find function vkCmdSetScissorWithCount";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkRect2D *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBindVertexBuffers2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("firstBinding"));
  void * p2 = resolveNapiValueAddress(input.Get("bindingCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pBuffers"));
  void * p4 = resolveNapiValueAddress(input.Get("pOffsets"));
  void * p5 = input.Has("pSizes") ? resolveNapiValueAddress(input.Get("pSizes")) : nullptr;
  void * p6 = input.Has("pStrides") ? resolveNapiValueAddress(input.Get("pStrides")) : nullptr;
  auto XF = (PFN_vkCmdBindVertexBuffers2) vkGetInstanceProcAddr(NULL, "vkCmdBindVertexBuffers2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBindVertexBuffers2) vkGetInstanceProcAddr(inst, "vkCmdBindVertexBuffers2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBindVertexBuffers2) vkGetDeviceProcAddr(dev, "vkCmdBindVertexBuffers2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBindVertexBuffers2");
    throw "cannot find function vkCmdBindVertexBuffers2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBuffer *>(p3),
    reinterpret_cast<const VkDeviceSize *>(p4),
    reinterpret_cast<const VkDeviceSize *>(p5),
    reinterpret_cast<const VkDeviceSize *>(p6)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthTestEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthTestEnable"));
  auto XF = (PFN_vkCmdSetDepthTestEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthTestEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthTestEnable) vkGetInstanceProcAddr(inst, "vkCmdSetDepthTestEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthTestEnable) vkGetDeviceProcAddr(dev, "vkCmdSetDepthTestEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthTestEnable");
    throw "cannot find function vkCmdSetDepthTestEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthWriteEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthWriteEnable"));
  auto XF = (PFN_vkCmdSetDepthWriteEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthWriteEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthWriteEnable) vkGetInstanceProcAddr(inst, "vkCmdSetDepthWriteEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthWriteEnable) vkGetDeviceProcAddr(dev, "vkCmdSetDepthWriteEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthWriteEnable");
    throw "cannot find function vkCmdSetDepthWriteEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthCompareOp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthCompareOp"));
  auto XF = (PFN_vkCmdSetDepthCompareOp) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthCompareOp");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthCompareOp) vkGetInstanceProcAddr(inst, "vkCmdSetDepthCompareOp");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthCompareOp) vkGetDeviceProcAddr(dev, "vkCmdSetDepthCompareOp");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthCompareOp");
    throw "cannot find function vkCmdSetDepthCompareOp";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkCompareOp)(((int32_t*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthBoundsTestEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthBoundsTestEnable"));
  auto XF = (PFN_vkCmdSetDepthBoundsTestEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthBoundsTestEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthBoundsTestEnable) vkGetInstanceProcAddr(inst, "vkCmdSetDepthBoundsTestEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthBoundsTestEnable) vkGetDeviceProcAddr(dev, "vkCmdSetDepthBoundsTestEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthBoundsTestEnable");
    throw "cannot find function vkCmdSetDepthBoundsTestEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetStencilTestEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("stencilTestEnable"));
  auto XF = (PFN_vkCmdSetStencilTestEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetStencilTestEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetStencilTestEnable) vkGetInstanceProcAddr(inst, "vkCmdSetStencilTestEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetStencilTestEnable) vkGetDeviceProcAddr(dev, "vkCmdSetStencilTestEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetStencilTestEnable");
    throw "cannot find function vkCmdSetStencilTestEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetStencilOp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("faceMask"));
  void * p2 = resolveNapiValueAddress(input.Get("failOp"));
  void * p3 = resolveNapiValueAddress(input.Get("passOp"));
  void * p4 = resolveNapiValueAddress(input.Get("depthFailOp"));
  void * p5 = resolveNapiValueAddress(input.Get("compareOp"));
  auto XF = (PFN_vkCmdSetStencilOp) vkGetInstanceProcAddr(NULL, "vkCmdSetStencilOp");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetStencilOp) vkGetInstanceProcAddr(inst, "vkCmdSetStencilOp");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetStencilOp) vkGetDeviceProcAddr(dev, "vkCmdSetStencilOp");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetStencilOp");
    throw "cannot find function vkCmdSetStencilOp";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkStencilFaceFlags)(((uint32_t*)p1)[0]),
    (VkStencilOp)(((int32_t*)p2)[0]),
    (VkStencilOp)(((int32_t*)p3)[0]),
    (VkStencilOp)(((int32_t*)p4)[0]),
    (VkCompareOp)(((int32_t*)p5)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetRasterizerDiscardEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("rasterizerDiscardEnable"));
  auto XF = (PFN_vkCmdSetRasterizerDiscardEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetRasterizerDiscardEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetRasterizerDiscardEnable) vkGetInstanceProcAddr(inst, "vkCmdSetRasterizerDiscardEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetRasterizerDiscardEnable) vkGetDeviceProcAddr(dev, "vkCmdSetRasterizerDiscardEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetRasterizerDiscardEnable");
    throw "cannot find function vkCmdSetRasterizerDiscardEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetDepthBiasEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("depthBiasEnable"));
  auto XF = (PFN_vkCmdSetDepthBiasEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetDepthBiasEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetDepthBiasEnable) vkGetInstanceProcAddr(inst, "vkCmdSetDepthBiasEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetDepthBiasEnable) vkGetDeviceProcAddr(dev, "vkCmdSetDepthBiasEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetDepthBiasEnable");
    throw "cannot find function vkCmdSetDepthBiasEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetPrimitiveRestartEnable(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("primitiveRestartEnable"));
  auto XF = (PFN_vkCmdSetPrimitiveRestartEnable) vkGetInstanceProcAddr(NULL, "vkCmdSetPrimitiveRestartEnable");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetPrimitiveRestartEnable) vkGetInstanceProcAddr(inst, "vkCmdSetPrimitiveRestartEnable");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetPrimitiveRestartEnable) vkGetDeviceProcAddr(dev, "vkCmdSetPrimitiveRestartEnable");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetPrimitiveRestartEnable");
    throw "cannot find function vkCmdSetPrimitiveRestartEnable";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkBool32)(((VkBool32*)p1)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreatePrivateDataSlot(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pPrivateDataSlot"));
  auto XF = (PFN_vkCreatePrivateDataSlot) vkGetInstanceProcAddr(NULL, "vkCreatePrivateDataSlot");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreatePrivateDataSlot) vkGetInstanceProcAddr(inst, "vkCreatePrivateDataSlot");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreatePrivateDataSlot) vkGetDeviceProcAddr(dev, "vkCreatePrivateDataSlot");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreatePrivateDataSlot");
    throw "cannot find function vkCreatePrivateDataSlot";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkPrivateDataSlotCreateInfo *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkPrivateDataSlot *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyPrivateDataSlot(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("privateDataSlot") ? resolveNapiValueAddress(input.Get("privateDataSlot")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyPrivateDataSlot) vkGetInstanceProcAddr(NULL, "vkDestroyPrivateDataSlot");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyPrivateDataSlot) vkGetInstanceProcAddr(inst, "vkDestroyPrivateDataSlot");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyPrivateDataSlot) vkGetDeviceProcAddr(dev, "vkDestroyPrivateDataSlot");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyPrivateDataSlot");
    throw "cannot find function vkDestroyPrivateDataSlot";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkPrivateDataSlot *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkSetPrivateData(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("objectType"));
  void * p2 = resolveNapiValueAddress(input.Get("objectHandle"));
  void * p3 = resolveNapiValueAddress(input.Get("privateDataSlot"));
  void * p4 = resolveNapiValueAddress(input.Get("data"));
  auto XF = (PFN_vkSetPrivateData) vkGetInstanceProcAddr(NULL, "vkSetPrivateData");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkSetPrivateData) vkGetInstanceProcAddr(inst, "vkSetPrivateData");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkSetPrivateData) vkGetDeviceProcAddr(dev, "vkSetPrivateData");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkSetPrivateData");
    throw "cannot find function vkSetPrivateData";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (VkObjectType)(((int32_t*)p1)[0]),
    (uint64_t)(((uint64_t*)p2)[0]),
    reinterpret_cast< VkPrivateDataSlot *>(p3)[0],
    (uint64_t)(((uint64_t*)p4)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPrivateData(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("objectType"));
  void * p2 = resolveNapiValueAddress(input.Get("objectHandle"));
  void * p3 = resolveNapiValueAddress(input.Get("privateDataSlot"));
  void * p4 = resolveNapiValueAddress(input.Get("pData"));
  auto XF = (PFN_vkGetPrivateData) vkGetInstanceProcAddr(NULL, "vkGetPrivateData");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPrivateData) vkGetInstanceProcAddr(inst, "vkGetPrivateData");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPrivateData) vkGetDeviceProcAddr(dev, "vkGetPrivateData");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPrivateData");
    throw "cannot find function vkGetPrivateData";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    (VkObjectType)(((int32_t*)p1)[0]),
    (uint64_t)(((uint64_t*)p2)[0]),
    reinterpret_cast< VkPrivateDataSlot *>(p3)[0],
    reinterpret_cast< uint64_t *>(p4)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyBuffer2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pCopyBufferInfo"));
  auto XF = (PFN_vkCmdCopyBuffer2) vkGetInstanceProcAddr(NULL, "vkCmdCopyBuffer2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyBuffer2) vkGetInstanceProcAddr(inst, "vkCmdCopyBuffer2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyBuffer2) vkGetDeviceProcAddr(dev, "vkCmdCopyBuffer2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyBuffer2");
    throw "cannot find function vkCmdCopyBuffer2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkCopyBufferInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyImage2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pCopyImageInfo"));
  auto XF = (PFN_vkCmdCopyImage2) vkGetInstanceProcAddr(NULL, "vkCmdCopyImage2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyImage2) vkGetInstanceProcAddr(inst, "vkCmdCopyImage2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyImage2) vkGetDeviceProcAddr(dev, "vkCmdCopyImage2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyImage2");
    throw "cannot find function vkCmdCopyImage2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkCopyImageInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdBlitImage2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pBlitImageInfo"));
  auto XF = (PFN_vkCmdBlitImage2) vkGetInstanceProcAddr(NULL, "vkCmdBlitImage2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBlitImage2) vkGetInstanceProcAddr(inst, "vkCmdBlitImage2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBlitImage2) vkGetDeviceProcAddr(dev, "vkCmdBlitImage2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBlitImage2");
    throw "cannot find function vkCmdBlitImage2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkBlitImageInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyBufferToImage2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pCopyBufferToImageInfo"));
  auto XF = (PFN_vkCmdCopyBufferToImage2) vkGetInstanceProcAddr(NULL, "vkCmdCopyBufferToImage2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyBufferToImage2) vkGetInstanceProcAddr(inst, "vkCmdCopyBufferToImage2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyBufferToImage2) vkGetDeviceProcAddr(dev, "vkCmdCopyBufferToImage2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyBufferToImage2");
    throw "cannot find function vkCmdCopyBufferToImage2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkCopyBufferToImageInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdCopyImageToBuffer2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pCopyImageToBufferInfo"));
  auto XF = (PFN_vkCmdCopyImageToBuffer2) vkGetInstanceProcAddr(NULL, "vkCmdCopyImageToBuffer2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdCopyImageToBuffer2) vkGetInstanceProcAddr(inst, "vkCmdCopyImageToBuffer2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdCopyImageToBuffer2) vkGetDeviceProcAddr(dev, "vkCmdCopyImageToBuffer2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdCopyImageToBuffer2");
    throw "cannot find function vkCmdCopyImageToBuffer2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkCopyImageToBufferInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdResolveImage2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pResolveImageInfo"));
  auto XF = (PFN_vkCmdResolveImage2) vkGetInstanceProcAddr(NULL, "vkCmdResolveImage2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdResolveImage2) vkGetInstanceProcAddr(inst, "vkCmdResolveImage2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdResolveImage2) vkGetDeviceProcAddr(dev, "vkCmdResolveImage2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdResolveImage2");
    throw "cannot find function vkCmdResolveImage2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkResolveImageInfo2 *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdSetFragmentShadingRateKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pFragmentSize"));
  void * p2 = resolveNapiValueAddress(input.Get("combinerOps"));
  auto XF = (PFN_vkCmdSetFragmentShadingRateKHR) vkGetInstanceProcAddr(NULL, "vkCmdSetFragmentShadingRateKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetFragmentShadingRateKHR) vkGetInstanceProcAddr(inst, "vkCmdSetFragmentShadingRateKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetFragmentShadingRateKHR) vkGetDeviceProcAddr(dev, "vkCmdSetFragmentShadingRateKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetFragmentShadingRateKHR");
    throw "cannot find function vkCmdSetFragmentShadingRateKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkExtent2D *>(p1),
    reinterpret_cast<const VkFragmentShadingRateCombinerOpKHR *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceFragmentShadingRatesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pFragmentShadingRateCount"));
  void * p2 = input.Has("pFragmentShadingRates") ? resolveNapiValueAddress(input.Get("pFragmentShadingRates")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceFragmentShadingRatesKHR");
    throw "cannot find function vkGetPhysicalDeviceFragmentShadingRatesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkPhysicalDeviceFragmentShadingRateKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdSetEvent2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  void * p2 = resolveNapiValueAddress(input.Get("pDependencyInfo"));
  auto XF = (PFN_vkCmdSetEvent2) vkGetInstanceProcAddr(NULL, "vkCmdSetEvent2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdSetEvent2) vkGetInstanceProcAddr(inst, "vkCmdSetEvent2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdSetEvent2) vkGetDeviceProcAddr(dev, "vkCmdSetEvent2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdSetEvent2");
    throw "cannot find function vkCmdSetEvent2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0],
    reinterpret_cast<const VkDependencyInfo *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdResetEvent2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("event"));
  void * p2 = input.Has("stageMask") ? resolveNapiValueAddress(input.Get("stageMask")) : nullptr;
  auto XF = (PFN_vkCmdResetEvent2) vkGetInstanceProcAddr(NULL, "vkCmdResetEvent2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdResetEvent2) vkGetInstanceProcAddr(inst, "vkCmdResetEvent2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdResetEvent2) vkGetDeviceProcAddr(dev, "vkCmdResetEvent2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdResetEvent2");
    throw "cannot find function vkCmdResetEvent2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast< VkEvent *>(p1)[0],
    (VkPipelineStageFlags2)(((uint32_t*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdWaitEvents2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("eventCount"));
  void * p2 = resolveNapiValueAddress(input.Get("pEvents"));
  void * p3 = resolveNapiValueAddress(input.Get("pDependencyInfos"));
  auto XF = (PFN_vkCmdWaitEvents2) vkGetInstanceProcAddr(NULL, "vkCmdWaitEvents2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdWaitEvents2) vkGetInstanceProcAddr(inst, "vkCmdWaitEvents2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdWaitEvents2) vkGetDeviceProcAddr(dev, "vkCmdWaitEvents2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdWaitEvents2");
    throw "cannot find function vkCmdWaitEvents2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkEvent *>(p2),
    reinterpret_cast<const VkDependencyInfo *>(p3)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdPipelineBarrier2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pDependencyInfo"));
  auto XF = (PFN_vkCmdPipelineBarrier2) vkGetInstanceProcAddr(NULL, "vkCmdPipelineBarrier2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdPipelineBarrier2) vkGetInstanceProcAddr(inst, "vkCmdPipelineBarrier2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdPipelineBarrier2) vkGetDeviceProcAddr(dev, "vkCmdPipelineBarrier2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdPipelineBarrier2");
    throw "cannot find function vkCmdPipelineBarrier2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkDependencyInfo *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkQueueSubmit2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  void * p1 = input.Has("submitCount") ? resolveNapiValueAddress(input.Get("submitCount")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("pSubmits"));
  void * p3 = input.Has("fence") ? resolveNapiValueAddress(input.Get("fence")) : nullptr;
  auto XF = (PFN_vkQueueSubmit2) vkGetInstanceProcAddr(NULL, "vkQueueSubmit2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkQueueSubmit2) vkGetInstanceProcAddr(inst, "vkQueueSubmit2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkQueueSubmit2) vkGetDeviceProcAddr(dev, "vkQueueSubmit2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkQueueSubmit2");
    throw "cannot find function vkQueueSubmit2";
  }

  int32_t out = XF(
    reinterpret_cast< VkQueue *>(p0)[0],
    (uint32_t)(((uint32_t*)p1)[0]),
    reinterpret_cast<const VkSubmitInfo2 *>(p2),
    reinterpret_cast< VkFence *>(p3)[0]
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdWriteTimestamp2(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("stage") ? resolveNapiValueAddress(input.Get("stage")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("queryPool"));
  void * p3 = resolveNapiValueAddress(input.Get("query"));
  auto XF = (PFN_vkCmdWriteTimestamp2) vkGetInstanceProcAddr(NULL, "vkCmdWriteTimestamp2");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdWriteTimestamp2) vkGetInstanceProcAddr(inst, "vkCmdWriteTimestamp2");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdWriteTimestamp2) vkGetDeviceProcAddr(dev, "vkCmdWriteTimestamp2");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdWriteTimestamp2");
    throw "cannot find function vkCmdWriteTimestamp2";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineStageFlags2)(((uint32_t*)p1)[0]),
    reinterpret_cast< VkQueryPool *>(p2)[0],
    (uint32_t)(((uint32_t*)p3)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdWriteBufferMarker2AMD(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = input.Has("stage") ? resolveNapiValueAddress(input.Get("stage")) : nullptr;
  void * p2 = resolveNapiValueAddress(input.Get("dstBuffer"));
  void * p3 = resolveNapiValueAddress(input.Get("dstOffset"));
  void * p4 = resolveNapiValueAddress(input.Get("marker"));
  auto XF = (PFN_vkCmdWriteBufferMarker2AMD) vkGetInstanceProcAddr(NULL, "vkCmdWriteBufferMarker2AMD");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdWriteBufferMarker2AMD) vkGetInstanceProcAddr(inst, "vkCmdWriteBufferMarker2AMD");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdWriteBufferMarker2AMD) vkGetDeviceProcAddr(dev, "vkCmdWriteBufferMarker2AMD");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdWriteBufferMarker2AMD");
    throw "cannot find function vkCmdWriteBufferMarker2AMD";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    (VkPipelineStageFlags2)(((uint32_t*)p1)[0]),
    reinterpret_cast< VkBuffer *>(p2)[0],
    (VkDeviceSize)(((VkDeviceSize*)p3)[0]),
    (uint32_t)(((uint32_t*)p4)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetQueueCheckpointData2NV(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("queue"));
  void * p1 = resolveNapiValueAddress(input.Get("pCheckpointDataCount"));
  void * p2 = input.Has("pCheckpointData") ? resolveNapiValueAddress(input.Get("pCheckpointData")) : nullptr;
  auto XF = (PFN_vkGetQueueCheckpointData2NV) vkGetInstanceProcAddr(NULL, "vkGetQueueCheckpointData2NV");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetQueueCheckpointData2NV) vkGetInstanceProcAddr(inst, "vkGetQueueCheckpointData2NV");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetQueueCheckpointData2NV) vkGetDeviceProcAddr(dev, "vkGetQueueCheckpointData2NV");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetQueueCheckpointData2NV");
    throw "cannot find function vkGetQueueCheckpointData2NV";
  }

  XF(
    reinterpret_cast< VkQueue *>(p0)[0],
    reinterpret_cast< uint32_t *>(p1),
    reinterpret_cast< VkCheckpointData2NV *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPhysicalDeviceVideoCapabilitiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pVideoProfile"));
  void * p2 = resolveNapiValueAddress(input.Get("pCapabilities"));
  auto XF = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceVideoCapabilitiesKHR");
    throw "cannot find function vkGetPhysicalDeviceVideoCapabilitiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkVideoProfileInfoKHR *>(p1),
    reinterpret_cast< VkVideoCapabilitiesKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkGetPhysicalDeviceVideoFormatPropertiesKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("physicalDevice"));
  void * p1 = resolveNapiValueAddress(input.Get("pVideoFormatInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pVideoFormatPropertyCount"));
  void * p3 = input.Has("pVideoFormatProperties") ? resolveNapiValueAddress(input.Get("pVideoFormatProperties")) : nullptr;
  auto XF = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR) vkGetInstanceProcAddr(NULL, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR) vkGetInstanceProcAddr(inst, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR) vkGetDeviceProcAddr(dev, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    throw "cannot find function vkGetPhysicalDeviceVideoFormatPropertiesKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkPhysicalDevice *>(p0)[0],
    reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR *>(p1),
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkVideoFormatPropertiesKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCreateVideoSessionKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pVideoSession"));
  auto XF = (PFN_vkCreateVideoSessionKHR) vkGetInstanceProcAddr(NULL, "vkCreateVideoSessionKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateVideoSessionKHR) vkGetInstanceProcAddr(inst, "vkCreateVideoSessionKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateVideoSessionKHR) vkGetDeviceProcAddr(dev, "vkCreateVideoSessionKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateVideoSessionKHR");
    throw "cannot find function vkCreateVideoSessionKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkVideoSessionCreateInfoKHR *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkVideoSessionKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyVideoSessionKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("videoSession") ? resolveNapiValueAddress(input.Get("videoSession")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyVideoSessionKHR) vkGetInstanceProcAddr(NULL, "vkDestroyVideoSessionKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyVideoSessionKHR) vkGetInstanceProcAddr(inst, "vkDestroyVideoSessionKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyVideoSessionKHR) vkGetDeviceProcAddr(dev, "vkDestroyVideoSessionKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyVideoSessionKHR");
    throw "cannot find function vkDestroyVideoSessionKHR";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkVideoSessionKHR *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCreateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  void * p3 = resolveNapiValueAddress(input.Get("pVideoSessionParameters"));
  auto XF = (PFN_vkCreateVideoSessionParametersKHR) vkGetInstanceProcAddr(NULL, "vkCreateVideoSessionParametersKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCreateVideoSessionParametersKHR) vkGetInstanceProcAddr(inst, "vkCreateVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCreateVideoSessionParametersKHR) vkGetDeviceProcAddr(dev, "vkCreateVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCreateVideoSessionParametersKHR");
    throw "cannot find function vkCreateVideoSessionParametersKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR *>(p1),
    reinterpret_cast<const VkAllocationCallbacks *>(p2),
    reinterpret_cast< VkVideoSessionParametersKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkUpdateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("videoSessionParameters"));
  void * p2 = resolveNapiValueAddress(input.Get("pUpdateInfo"));
  auto XF = (PFN_vkUpdateVideoSessionParametersKHR) vkGetInstanceProcAddr(NULL, "vkUpdateVideoSessionParametersKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkUpdateVideoSessionParametersKHR) vkGetInstanceProcAddr(inst, "vkUpdateVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkUpdateVideoSessionParametersKHR) vkGetDeviceProcAddr(dev, "vkUpdateVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkUpdateVideoSessionParametersKHR");
    throw "cannot find function vkUpdateVideoSessionParametersKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkVideoSessionParametersKHR *>(p1)[0],
    reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkDestroyVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = input.Has("videoSessionParameters") ? resolveNapiValueAddress(input.Get("videoSessionParameters")) : nullptr;
  void * p2 = input.Has("pAllocator") ? resolveNapiValueAddress(input.Get("pAllocator")) : nullptr;
  auto XF = (PFN_vkDestroyVideoSessionParametersKHR) vkGetInstanceProcAddr(NULL, "vkDestroyVideoSessionParametersKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkDestroyVideoSessionParametersKHR) vkGetInstanceProcAddr(inst, "vkDestroyVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkDestroyVideoSessionParametersKHR) vkGetDeviceProcAddr(dev, "vkDestroyVideoSessionParametersKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkDestroyVideoSessionParametersKHR");
    throw "cannot find function vkDestroyVideoSessionParametersKHR";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkVideoSessionParametersKHR *>(p1)[0],
    reinterpret_cast<const VkAllocationCallbacks *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetVideoSessionMemoryRequirementsKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("videoSession"));
  void * p2 = resolveNapiValueAddress(input.Get("pMemoryRequirementsCount"));
  void * p3 = input.Has("pMemoryRequirements") ? resolveNapiValueAddress(input.Get("pMemoryRequirements")) : nullptr;
  auto XF = (PFN_vkGetVideoSessionMemoryRequirementsKHR) vkGetInstanceProcAddr(NULL, "vkGetVideoSessionMemoryRequirementsKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetVideoSessionMemoryRequirementsKHR) vkGetInstanceProcAddr(inst, "vkGetVideoSessionMemoryRequirementsKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetVideoSessionMemoryRequirementsKHR) vkGetDeviceProcAddr(dev, "vkGetVideoSessionMemoryRequirementsKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetVideoSessionMemoryRequirementsKHR");
    throw "cannot find function vkGetVideoSessionMemoryRequirementsKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkVideoSessionKHR *>(p1)[0],
    reinterpret_cast< uint32_t *>(p2),
    reinterpret_cast< VkVideoSessionMemoryRequirementsKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkBindVideoSessionMemoryKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("videoSession"));
  void * p2 = resolveNapiValueAddress(input.Get("bindSessionMemoryInfoCount"));
  void * p3 = resolveNapiValueAddress(input.Get("pBindSessionMemoryInfos"));
  auto XF = (PFN_vkBindVideoSessionMemoryKHR) vkGetInstanceProcAddr(NULL, "vkBindVideoSessionMemoryKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkBindVideoSessionMemoryKHR) vkGetInstanceProcAddr(inst, "vkBindVideoSessionMemoryKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkBindVideoSessionMemoryKHR) vkGetDeviceProcAddr(dev, "vkBindVideoSessionMemoryKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkBindVideoSessionMemoryKHR");
    throw "cannot find function vkBindVideoSessionMemoryKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkVideoSessionKHR *>(p1)[0],
    (uint32_t)(((uint32_t*)p2)[0]),
    reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR *>(p3)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdBeginVideoCodingKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pBeginInfo"));
  auto XF = (PFN_vkCmdBeginVideoCodingKHR) vkGetInstanceProcAddr(NULL, "vkCmdBeginVideoCodingKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginVideoCodingKHR) vkGetInstanceProcAddr(inst, "vkCmdBeginVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginVideoCodingKHR) vkGetDeviceProcAddr(dev, "vkCmdBeginVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginVideoCodingKHR");
    throw "cannot find function vkCmdBeginVideoCodingKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkVideoBeginCodingInfoKHR *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdControlVideoCodingKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pCodingControlInfo"));
  auto XF = (PFN_vkCmdControlVideoCodingKHR) vkGetInstanceProcAddr(NULL, "vkCmdControlVideoCodingKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdControlVideoCodingKHR) vkGetInstanceProcAddr(inst, "vkCmdControlVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdControlVideoCodingKHR) vkGetDeviceProcAddr(dev, "vkCmdControlVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdControlVideoCodingKHR");
    throw "cannot find function vkCmdControlVideoCodingKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkVideoCodingControlInfoKHR *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndVideoCodingKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pEndCodingInfo"));
  auto XF = (PFN_vkCmdEndVideoCodingKHR) vkGetInstanceProcAddr(NULL, "vkCmdEndVideoCodingKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndVideoCodingKHR) vkGetInstanceProcAddr(inst, "vkCmdEndVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndVideoCodingKHR) vkGetDeviceProcAddr(dev, "vkCmdEndVideoCodingKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndVideoCodingKHR");
    throw "cannot find function vkCmdEndVideoCodingKHR";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkVideoEndCodingInfoKHR *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkSetDeviceMemoryPriorityEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("memory"));
  void * p2 = resolveNapiValueAddress(input.Get("priority"));
  auto XF = (PFN_vkSetDeviceMemoryPriorityEXT) vkGetInstanceProcAddr(NULL, "vkSetDeviceMemoryPriorityEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkSetDeviceMemoryPriorityEXT) vkGetInstanceProcAddr(inst, "vkSetDeviceMemoryPriorityEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkSetDeviceMemoryPriorityEXT) vkGetDeviceProcAddr(dev, "vkSetDeviceMemoryPriorityEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkSetDeviceMemoryPriorityEXT");
    throw "cannot find function vkSetDeviceMemoryPriorityEXT";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkDeviceMemory *>(p1)[0],
    (float)(((float*)p2)[0])
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkWaitForPresentKHR(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("swapchain"));
  void * p2 = resolveNapiValueAddress(input.Get("presentId"));
  void * p3 = resolveNapiValueAddress(input.Get("timeout"));
  auto XF = (PFN_vkWaitForPresentKHR) vkGetInstanceProcAddr(NULL, "vkWaitForPresentKHR");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkWaitForPresentKHR) vkGetInstanceProcAddr(inst, "vkWaitForPresentKHR");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkWaitForPresentKHR) vkGetDeviceProcAddr(dev, "vkWaitForPresentKHR");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkWaitForPresentKHR");
    throw "cannot find function vkWaitForPresentKHR";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkSwapchainKHR *>(p1)[0],
    (uint64_t)(((uint64_t*)p2)[0]),
    (uint64_t)(((uint64_t*)p3)[0])
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkCmdBeginRendering(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  void * p1 = resolveNapiValueAddress(input.Get("pRenderingInfo"));
  auto XF = (PFN_vkCmdBeginRendering) vkGetInstanceProcAddr(NULL, "vkCmdBeginRendering");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdBeginRendering) vkGetInstanceProcAddr(inst, "vkCmdBeginRendering");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdBeginRendering) vkGetDeviceProcAddr(dev, "vkCmdBeginRendering");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdBeginRendering");
    throw "cannot find function vkCmdBeginRendering";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0],
    reinterpret_cast<const VkRenderingInfo *>(p1)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkCmdEndRendering(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("commandBuffer"));
  auto XF = (PFN_vkCmdEndRendering) vkGetInstanceProcAddr(NULL, "vkCmdEndRendering");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkCmdEndRendering) vkGetInstanceProcAddr(inst, "vkCmdEndRendering");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkCmdEndRendering) vkGetDeviceProcAddr(dev, "vkCmdEndRendering");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkCmdEndRendering");
    throw "cannot find function vkCmdEndRendering";
  }

  XF(
    reinterpret_cast< VkCommandBuffer *>(p0)[0]
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetShaderModuleIdentifierEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("shaderModule"));
  void * p2 = resolveNapiValueAddress(input.Get("pIdentifier"));
  auto XF = (PFN_vkGetShaderModuleIdentifierEXT) vkGetInstanceProcAddr(NULL, "vkGetShaderModuleIdentifierEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetShaderModuleIdentifierEXT) vkGetInstanceProcAddr(inst, "vkGetShaderModuleIdentifierEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetShaderModuleIdentifierEXT) vkGetDeviceProcAddr(dev, "vkGetShaderModuleIdentifierEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetShaderModuleIdentifierEXT");
    throw "cannot find function vkGetShaderModuleIdentifierEXT";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast< VkShaderModule *>(p1)[0],
    reinterpret_cast< VkShaderModuleIdentifierEXT *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetShaderModuleCreateInfoIdentifierEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pCreateInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pIdentifier"));
  auto XF = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT) vkGetInstanceProcAddr(NULL, "vkGetShaderModuleCreateInfoIdentifierEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT) vkGetInstanceProcAddr(inst, "vkGetShaderModuleCreateInfoIdentifierEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT) vkGetDeviceProcAddr(dev, "vkGetShaderModuleCreateInfoIdentifierEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetShaderModuleCreateInfoIdentifierEXT");
    throw "cannot find function vkGetShaderModuleCreateInfoIdentifierEXT";
  }

  XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkShaderModuleCreateInfo *>(p1),
    reinterpret_cast< VkShaderModuleIdentifierEXT *>(p2)
  );

  return Napi::Number::New(env, 1);
};
Napi::Value vts_native_vkGetPipelinePropertiesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pPipelineInfo"));
  void * p2 = resolveNapiValueAddress(input.Get("pPipelineProperties"));
  auto XF = (PFN_vkGetPipelinePropertiesEXT) vkGetInstanceProcAddr(NULL, "vkGetPipelinePropertiesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkGetPipelinePropertiesEXT) vkGetInstanceProcAddr(inst, "vkGetPipelinePropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkGetPipelinePropertiesEXT) vkGetDeviceProcAddr(dev, "vkGetPipelinePropertiesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkGetPipelinePropertiesEXT");
    throw "cannot find function vkGetPipelinePropertiesEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkPipelineInfoEXT *>(p1),
    reinterpret_cast< VkBaseOutStructure *>(p2)
  );

  return Napi::Number::New(env, out);
};
Napi::Value vts_native_vkReleaseSwapchainImagesEXT(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object input = info[0].As<Napi::Object>();
  void * p0 = resolveNapiValueAddress(input.Get("device"));
  void * p1 = resolveNapiValueAddress(input.Get("pReleaseInfo"));
  auto XF = (PFN_vkReleaseSwapchainImagesEXT) vkGetInstanceProcAddr(NULL, "vkReleaseSwapchainImagesEXT");
  if(input.Has("instance")) {
    auto inst = reinterpret_cast< VkInstance *>(resolveNapiValueAddress(input.Get("instance")))[0];
    auto XFC = (PFN_vkReleaseSwapchainImagesEXT) vkGetInstanceProcAddr(inst, "vkReleaseSwapchainImagesEXT");
    if(XFC != nullptr) XF = XFC;
  }
  if(input.Has("device")){
    auto dev = reinterpret_cast< VkDevice *>(resolveNapiValueAddress(input.Get("device")))[0];
    auto XFC = (PFN_vkReleaseSwapchainImagesEXT) vkGetDeviceProcAddr(dev, "vkReleaseSwapchainImagesEXT");
    if(XFC != nullptr) XF = XFC;
  }

  if(XF == nullptr){
    printf("cannot find function vkReleaseSwapchainImagesEXT");
    throw "cannot find function vkReleaseSwapchainImagesEXT";
  }

  int32_t out = XF(
    reinterpret_cast< VkDevice *>(p0)[0],
    reinterpret_cast<const VkReleaseSwapchainImagesInfoEXT *>(p1)
  );

  return Napi::Number::New(env, out);
};