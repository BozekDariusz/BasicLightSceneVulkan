#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <array>
#include<vector>
#include "vertex.h"
#include <string>

struct UniformBufferObject
{

    glm::mat4 view;
    glm::mat4 proj;
    glm::mat4 model;

};
struct LightBufferObject {
    glm::vec3 lightPos;

};



struct Mesh {
    //vertices and indices
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::string name;
    glm::mat4 model;
    int width;
    int height;
    Mesh() {}

    Mesh(const std::vector<Vertex> v, const std::vector<uint32_t> i) :vertices(v), indices(i) {

        model = glm::mat4(1);
    }


};