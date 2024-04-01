# Vulkan-Node - Vulkan API wrapper for Node 
### + TypeScript support!

This project is a generated wrapper for Vulkan API for use in Node.js. Features full typing for TypeScript as well.

```yaml
Specification version: $SPECVERSION$
Generated with version commit: $COMMIT$
Generated at: $DATE$
```

# How to use
Here is a very simple example showing how to create an instance:

```ts
import * as vk from "vulkan-node";

const appInfo: vk.VkApplicationInfo = {
    pApplicationName: "Hello World",
    applicationVersion: vk.VK_MAKE_VERSION(1, 0, 0),
    pEngineName: "My Engine",
    engineVersion: vk.VK_MAKE_VERSION(1, 0, 0),
    apiVersion: vk.VK_API_VERSION_1_0,
};

const instanceExtensionsWithValidation: string[] = [
    //
];

const layersWithValidation: string[] = [
    //
];

const instanceCreateInfo: vk.VkInstanceCreateInfo = {
    pApplicationInfo: appInfo,
    enabledExtensionCount: instanceExtensionsWithValidation.length,
    ppEnabledExtensionNames: instanceExtensionsWithValidation,
    enabledLayerCount: layersWithValidation.length,
    ppEnabledLayerNames: layersWithValidation,
};

const instance = new vk.VkInstance(); // handle will be stored here
const res = vk.vkCreateInstance({
    pCreateInfo: instanceCreateInfo,
    pInstance: instance,
});
if (res !== vk.VkResult.VK_SUCCESS) {
    throw new Error(`Instance initialization failed with error ${res}`);
}
```
