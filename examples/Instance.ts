import * as vk from "../../generated/release-vulkan-node";

export class Instance {
  public readonly instance: vk.VkInstance;

  public constructor(
    enableValidation: boolean,
    appName: string,
    engineName: string,
    instanceExtensions: string[],
    instanceLayers: string[]
  ) {
    const appInfo = new vk.VkApplicationInfo({
      pApplicationName: appName,
      applicationVersion: vk.VK_MAKE_VERSION(1, 0, 0),
      pEngineName: engineName,
      engineVersion: vk.VK_MAKE_VERSION(1, 0, 0),
      apiVersion: vk.VK_API_VERSION_1_0,
    });

    const instanceExtensionsWithValidation = [
      ...(enableValidation
        ? ["VK_EXT_debug_report", "VK_EXT_debug_utils"]
        : []),
      ...instanceExtensions,
    ];

    const layersWithValidation = [
      "VK_LAYER_KHRONOS_validation",
      ...instanceLayers,
    ];

    const instanceCreateInfo = new vk.VkInstanceCreateInfo({
      pApplicationInfo: appInfo,
      enabledExtensionCount: instanceExtensionsWithValidation.length,
      ppEnabledExtensionNames: instanceExtensionsWithValidation,
      enabledLayerCount: layersWithValidation.length,
      ppEnabledLayerNames: layersWithValidation,
    });

    this.instance = new vk.VkInstance();
    const res = vk.vkCreateInstance({
      pCreateInfo: instanceCreateInfo,
      pInstance: this.instance,
    });
    if (res !== vk.VkResult.VK_SUCCESS) {
      throw new Error(`Instance initialization failed with error ${res}`);
    }
  }

  public free(): void {
    vk.vkDestroyInstance({ instance: this.instance });
  }
}
