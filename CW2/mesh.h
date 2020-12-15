#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <array>
#include<vector>
#include "vertex.h"
#include <string>

struct UniformBufferObject {

    glm::mat4 view;
    glm::mat4 proj;

};
struct UniformBufferModelObject {

    glm::mat4 model;

};


struct Mesh {
    //vertices and indices
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;
    std::vector<VkDescriptorSet> descriptorSets;
    //uniform buffers storage
    std::vector<VkBuffer> uniformModelBuffers;
    //memory for the uniform buffers
    std::vector<VkDeviceMemory> uniformModelBuffersMemory;
    glm::vec3 scale;
    std::string name;
    UniformBufferModelObject ubo;
    glm::vec2 direction;//FIXHERE move to Ball 
    int width;
    int height;
    Mesh() {}

    Mesh(const std::vector<Vertex> v, const std::vector<uint16_t> i) :vertices(v), indices(i) {

        scale = glm::vec3(1.0f, 1.0f, 1.0f);
        ubo.model = glm::mat4(1);
    }


};