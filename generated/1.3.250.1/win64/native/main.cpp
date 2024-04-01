#define NAPI_EXPERIMENTAL
#include <napi.h>

// #define VK_USE_64_BIT_PTR_DEFINES 1 // doesnt work anyway
#define GLFW_INCLUDE_VULKAN
// #define VK_NO_PROTOTYPES
// #include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "defines_includes.h"

#include <iostream>
#include <vector>

#include "scratchBuffer.h"
#include "debugCallback.h"
#include "alignment.h"
#include "exposedFunctions.h"
#include "commands.h"
#include "window.h"
#include "init.h"

NODE_API_MODULE(addon, Init)
