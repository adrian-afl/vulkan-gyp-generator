import * as vk from "../../generated/release-vulkan-node";
import { initArray } from "../../generated/release-vulkan-node";

export class Device {
  public readonly device: vk.VkDevice;
  public readonly queueFamilyIndex: number = -1;
  public readonly physicalDevice: vk.VkPhysicalDevice;

  private physicalDevices!: vk.VkPhysicalDevice[];
  private chosenDeviceId = -1;
  private physicalDevicesMemoryProps!: vk.VkPhysicalDeviceMemoryPropertiesDeserialized[];

  public constructor(
    private instance: vk.VkInstance,
    deviceExtensions: string[]
  ) {
    const physicalDeviceCount = new vk.uint32_t(0);
    vk.vkEnumeratePhysicalDevices({
      instance: this.instance,
      pPhysicalDeviceCount: physicalDeviceCount,
    });

    if (physicalDeviceCount.toNumber() <= 0) {
      throw new Error("no physical devices found");
    }
    const physicalDevicesProps = vk.getEmptyVkPhysicalDevicePropertiesArray(
      physicalDeviceCount.toNumber()
    );

    const physicalDevicesFeats = vk.getEmptyVkPhysicalDeviceFeaturesArray(
      physicalDeviceCount.toNumber()
    );

    const tmpphysicalDevicesMemoryProps =
      vk.getEmptyVkPhysicalDeviceMemoryPropertiesArray(
        physicalDeviceCount.toNumber()
      );

    this.physicalDevices = initArray(
      physicalDeviceCount.toNumber(),
      () => new vk.VkPhysicalDevice()
    );
    vk.vkEnumeratePhysicalDevices({
      instance: this.instance,
      pPhysicalDevices: this.physicalDevices,
      pPhysicalDeviceCount: physicalDeviceCount,
    });

    for (let i = 0; i < physicalDeviceCount.toNumber(); i++) {
      vk.vkGetPhysicalDeviceProperties({
        instance: this.instance,
        physicalDevice: this.physicalDevices[i],
        pProperties: physicalDevicesProps[i],
      });
      vk.vkGetPhysicalDeviceFeatures({
        instance: this.instance,
        physicalDevice: this.physicalDevices[i],
        pFeatures: physicalDevicesFeats[i],
      });
      vk.vkGetPhysicalDeviceMemoryProperties({
        instance: this.instance,
        physicalDevice: this.physicalDevices[i],
        pMemoryProperties: tmpphysicalDevicesMemoryProps[i],
      });
    }

    this.physicalDevicesMemoryProps = tmpphysicalDevicesMemoryProps.map((a) =>
      a.deserializeSingle<vk.VkPhysicalDeviceMemoryPropertiesDeserialized>()
    );
    for (let i = 0; i < this.physicalDevices.length; i++) {
      const props = this.getQueueFamilyProperties(this.physicalDevices[i]);
      for (let g = 0; g < props.length; g++) {
        const qfamily = props[g] as { queueCount: number; queueFlags: number };
        if (
          qfamily.queueCount > 0 &&
          qfamily.queueFlags & vk.VkQueueFlagBits.VK_QUEUE_GRAPHICS_BIT
        ) {
          this.chosenDeviceId = i;
          this.queueFamilyIndex = g;
          break;
        }
      }
    }

    const requiredFeatures = new vk.VkPhysicalDeviceFeatures({
      alphaToOne: false,
      depthBiasClamp: false,
      depthBounds: false,
      drawIndirectFirstInstance: false,
      dualSrcBlend: false,
      fillModeNonSolid: false,
      fullDrawIndexUint32: false,
      imageCubeArray: false,
      inheritedQueries: false,
      largePoints: false,
      logicOp: false,
      multiDrawIndirect: false,
      multiViewport: false,
      occlusionQueryPrecise: false,
      pipelineStatisticsQuery: false,
      robustBufferAccess: false,
      sampleRateShading: false,
      shaderClipDistance: false,
      shaderCullDistance: false,
      shaderFloat64: false,
      shaderImageGatherExtended: false,
      shaderInt16: false,
      shaderInt64: false,
      shaderResourceMinLod: false,
      shaderResourceResidency: false,
      shaderSampledImageArrayDynamicIndexing: false,
      shaderStorageBufferArrayDynamicIndexing: false,
      shaderStorageImageArrayDynamicIndexing: false,
      shaderStorageImageMultisample: false,
      shaderStorageImageReadWithoutFormat: false,
      shaderStorageImageWriteWithoutFormat: false,
      shaderTessellationAndGeometryPointSize: false,
      shaderUniformBufferArrayDynamicIndexing: false,
      sparseBinding: false,
      sparseResidency16Samples: false,
      sparseResidency2Samples: false,
      sparseResidency4Samples: false,
      sparseResidency8Samples: false,
      sparseResidencyAliased: false,
      sparseResidencyBuffer: false,
      sparseResidencyImage2D: false,
      sparseResidencyImage3D: false,
      textureCompressionASTC_LDR: false,
      textureCompressionBC: false,
      textureCompressionETC2: false,
      variableMultisampleRate: false,
      wideLines: false,
      tessellationShader: false,
      geometryShader: false,

      depthClamp: true,
      samplerAnisotropy: true,
      shaderStorageImageExtendedFormats: true,
      independentBlend: true,
      fragmentStoresAndAtomics: true,
      vertexPipelineStoresAndAtomics: true,
    });

    const priorities = [new vk.float(1.0), new vk.float(0.0)];
    const deviceQueueCreateInfo = new vk.VkDeviceQueueCreateInfo({
      flags: 0,
      queueFamilyIndex: this.queueFamilyIndex,
      queueCount: 1,
      pQueuePriorities: priorities,
    });

    const deviceCreateInfo = new vk.VkDeviceCreateInfo({
      pQueueCreateInfos: [deviceQueueCreateInfo],
      queueCreateInfoCount: 1,
      pEnabledFeatures: requiredFeatures,
      enabledExtensionCount: deviceExtensions.length,
      ppEnabledExtensionNames: deviceExtensions,
    });

    this.physicalDevice = this.physicalDevices[this.chosenDeviceId];

    this.device = new vk.VkDevice();

    // process.exit();

    vk.vkCreateDevice({
      instance: this.instance,
      physicalDevice: this.physicalDevice,
      pCreateInfo: deviceCreateInfo,
      pDevice: this.device,
    });
  }

  private getQueueFamilyProperties(
    pdevice: vk.VkPhysicalDevice
  ): vk.VkQueueFamilyPropertiesDeserialized[] {
    const queueFamilyPropertyCount = new vk.uint32_t();

    vk.vkGetPhysicalDeviceQueueFamilyProperties({
      instance: this.instance,
      physicalDevice: pdevice,
      pQueueFamilyPropertyCount: queueFamilyPropertyCount,
    });

    const queueFamilyProperties = vk.getEmptyVkQueueFamilyPropertiesArray(
      queueFamilyPropertyCount.toNumber()
    );

    vk.vkGetPhysicalDeviceQueueFamilyProperties({
      instance: this.instance,
      physicalDevice: pdevice,
      pQueueFamilyPropertyCount: queueFamilyPropertyCount,
      pQueueFamilyProperties: queueFamilyProperties,
    });

    return queueFamilyProperties.map((a) =>
      a.deserializeSingle<vk.VkQueueFamilyPropertiesDeserialized>()
    );
  }

  public findMemoryType(typeFilter: number, properties: number): number {
    for (
      let i = 0;
      i < this.physicalDevicesMemoryProps[this.chosenDeviceId].memoryTypeCount;
      i++
    ) {
      const pprops = this.physicalDevicesMemoryProps[this.chosenDeviceId];
      if (pprops && pprops.memoryTypes) {
        const memtype = pprops.memoryTypes[i];
        const proFlags = memtype.propertyFlags as number | undefined;
        if (
          proFlags &&
          typeFilter & (1 << i) &&
          (proFlags & properties) === properties
        ) {
          return i;
        }
      }
    }

    throw "failed to find suitable memory type!";
  }

  public free(): void {
    vk.vkDestroyDevice({ device: this.device });
  }

  public waitDeviceIdle(): void {
    vk.vkDeviceWaitIdle({ device: this.device });
  }
}
