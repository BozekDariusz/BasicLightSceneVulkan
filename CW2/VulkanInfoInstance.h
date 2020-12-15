#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



#include "mesh.h"
#include "vertex.h"


#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <optional>
#include <set>
#include <string>
#include <chrono>
#include <stdexcept>




#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};


VkResult CreateDebugUtilsMessengerEXT(VkInstance, const VkDebugUtilsMessengerCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugUtilsMessengerEXT*);

void DestroyDebugUtilsMessengerEXT(VkInstance, VkDebugUtilsMessengerEXT, const VkAllocationCallbacks*);



struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};










class VulkanInfoInstance {

public:
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;


    GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkCommandPool commandPool;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    std::vector<VkFence> imagesInFlight;

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    size_t currentFrame = 0;

    bool framebufferResized = false;

public:




    void run();


    void initWindow();
    static void framebufferResizeCallback(GLFWwindow*, int, int);

    void initVulkan();

    void mainLoop();

    void cleanupSwapChain();

    void cleanup();

    void recreateSwapChain();
    void createInstance();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT&);

    void setupDebugMessenger();

    void createSurface();

    void pickPhysicalDevice();


    void createLogicalDevice();

    void createSwapChain();

    void createImageViews();

    void createRenderPass();
    void createDescriptorSetLayout();


    void createGraphicsPipeline();
    void createFramebuffers();

    void createVertexBuffer();
    void createCommandPool();


    void createIndexBuffer();
    void createUniformBuffers();
    void createBuffer(VkDeviceSize , VkBufferUsageFlags , VkMemoryPropertyFlags , VkBuffer& , VkDeviceMemory& );

    void createDepthResources();

    VkFormat findSupportedFormat(const std::vector<VkFormat>& , VkImageTiling , VkFormatFeatureFlags );

    VkFormat findDepthFormat();

    bool hasStencilComponent(VkFormat );

    void createTextureImage(std::string);
    void createTextureImageView();

    void createTextureSampler();


    VkImageView createImageView(VkImage , VkFormat , VkImageAspectFlags );

    void createImage(uint32_t, uint32_t, VkFormat, VkImageTiling, VkImageUsageFlags, VkMemoryPropertyFlags, VkImage&, VkDeviceMemory&);


    void transitionImageLayout(VkImage , VkFormat , VkImageLayout , VkImageLayout );

    void copyBufferToImage(VkBuffer , VkImage , uint32_t , uint32_t );


    void loadModel(std::string );

    void createDescriptorPool();
    void createDescriptorSets();
    VkCommandBuffer beginSingleTimeCommands();

    void endSingleTimeCommands(VkCommandBuffer );
    void copyBuffer(VkBuffer , VkBuffer , VkDeviceSize );

    uint32_t findMemoryType(uint32_t , VkMemoryPropertyFlags );

    void createCommandBuffers();
    void createSyncObjects();
    void updateUniformBuffer(uint32_t );


    void drawFrame();
    VkShaderModule createShaderModule(const std::vector<char>& );

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& );

    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& );
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& );

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice );


    bool isDeviceSuitable(VkPhysicalDevice );

    bool checkDeviceExtensionSupport(VkPhysicalDevice);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice);
    std::vector<const char*> getRequiredExtensions();

    bool checkValidationLayerSupport();

    static std::vector<char> readFile(const std::string& );

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*, void*);
};