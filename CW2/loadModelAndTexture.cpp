#pragma once

#include "vertex.h"
#include "VulkanInfoInstance.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>



void VulkanInfoInstance::loadModel(std::string MODEL_PATH) {
    /*
    /////////Not allowed
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, MODEL_PATH.c_str())) {
        throw std::runtime_error(warn + err);
    }

    std::unordered_map<Vertex, uint32_t> uniqueVertices = {};

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            Vertex vertex = {};

            vertex.pos = {
                attrib.vertices[3 * index.vertex_index + 0],
                attrib.vertices[3 * index.vertex_index + 1],
                attrib.vertices[3 * index.vertex_index + 2]
            };

            vertex.texCoord = {
                attrib.texcoords[2 * index.texcoord_index + 0],
                1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
            };

            vertex.color = { 1.0f, 1.0f, 1.0f };

            if (uniqueVertices.count(vertex) == 0) {
                uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
                vertices.push_back(vertex);
            }

            indices.push_back(uniqueVertices[vertex]);
        }




    }
   */

    std::ifstream fin;
    fin.open(MODEL_PATH);
    std::string type;
    std::string vs1, vs2, vs3;
    std::vector<Vertex> normsVertices;
    std::vector<Vertex> tempVertices;
    float v1, v2, v3;
    std::string line;
    std::string sv1, sv2, sv3, sv4;

    if (true == fin.is_open())
    {
        for (int i = 0; i < 9; i++) {
            getline(fin, line);
        }

        Vertex temp;

        for (int i = 0; fin.peek() == 'v'; i++) {//vetrices


            fin >> type;
            fin.fixed;
            fin.precision(4);
            fin >> v1 >> v2 >> v3;
            temp.pos = { v1,v2,v3 };

            tempVertices.push_back(temp);
            fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        getline(fin, line);
        getline(fin, line);
        for (int i = 0; i < 8685; i++) {//vertices normals

            fin >> type >> v1 >> v2 >> v3;
            temp.normCoord = { v1,v2,v3 };
            normsVertices.push_back(temp);
        }
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(fin, line);
        getline(fin, line);
        for (int i = 0; i < 9582; i++) {//vertices textures

            fin >> type >> v1 >> v2 >> v3;
            temp.texCoord = { v1,1.0f - v2 };
            vertices.push_back(temp);
        }
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(fin, line);
        getline(fin, line);
        getline(fin, line);
        getline(fin, line);
        getline(fin, line);
        for (int i = 0; fin.peek() == 'f'; i++) {//faces

            fin >> type >> sv1 >> sv2 >> sv3 >> sv4;


            std::string vertexPosition = sv1.substr(0, sv1.find("/", 0));

            std::string  vertexTexture = sv1.substr(vertexPosition.size() + 1, sv1.find("/", vertexPosition.size() + 1));
            std::string  vertexNormals = sv1.substr(vertexTexture.size() + 1, sv1.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;




            vertexPosition = sv2.substr(0, sv2.find("/", 0));
            vertexTexture = sv2.substr(vertexPosition.size() + 1, sv2.find("/", vertexPosition.size() + 1));
            vertexNormals = sv2.substr(vertexTexture.size() + 1, sv2.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;




            vertexPosition = sv3.substr(0, sv3.find("/", 0));
            vertexTexture = sv3.substr(vertexPosition.size() + 1, sv3.find("/", vertexPosition.size() + 1));
            vertexNormals = sv3.substr(vertexTexture.size() + 1, sv3.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;



            vertexPosition = sv1.substr(0, sv1.find("/", 0));
            vertexTexture = sv1.substr(vertexPosition.size() + 1, sv1.find("/", vertexPosition.size() + 1));
            vertexNormals = sv1.substr(vertexTexture.size() + 1, sv1.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;


            vertexPosition = sv3.substr(0, sv3.find("/", 0));
            vertexTexture = sv3.substr(vertexPosition.size() + 1, sv3.find("/", vertexPosition.size() + 1));
            vertexNormals = sv3.substr(vertexTexture.size() + 1, sv3.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;


            vertexPosition = sv4.substr(0, sv4.find("/", 0));
            vertexTexture = sv4.substr(vertexPosition.size() + 1, sv4.find("/", vertexPosition.size() + 1));
            vertexNormals = sv4.substr(vertexTexture.size() + 1, sv4.find("/", vertexTexture.size() + 1));
            indices.push_back(std::stoi(vertexTexture) - 1);
            vertices[std::stoi(vertexTexture) - 1].pos = tempVertices[std::stoi(vertexPosition) - 1].pos;
            vertices[std::stoi(vertexTexture) - 1].normCoord = normsVertices[1].normCoord;

            fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

    }

    fin.close();

}


void VulkanInfoInstance::createTextureImage(std::string TEXTURE_PATH) {
    int texWidth, texHeight, texChannels;
    stbi_uc* pixels = stbi_load(TEXTURE_PATH.c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
    VkDeviceSize imageSize = texWidth * texHeight * 4;

    if (!pixels) {
        throw std::runtime_error("failed to load texture image!");
    }

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    createBuffer(imageSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

    void* data;
    vkMapMemory(device, stagingBufferMemory, 0, imageSize, 0, &data);
    memcpy(data, pixels, static_cast<size_t>(imageSize));
    vkUnmapMemory(device, stagingBufferMemory);

    stbi_image_free(pixels);

    createImage(texWidth, texHeight, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, textureImage, textureImageMemory);

    transitionImageLayout(textureImage, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    copyBufferToImage(stagingBuffer, textureImage, static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight));
    transitionImageLayout(textureImage, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

    vkDestroyBuffer(device, stagingBuffer, nullptr);
    vkFreeMemory(device, stagingBufferMemory, nullptr);
}



