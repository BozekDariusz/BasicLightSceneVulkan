#pragma once

#include "vertex.h"
#include "VulkanInfoInstance.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>



const std::vector<std::string> explode(const std::string& s, const char& c)
{
    std::string buff{ "" };
    std::vector<std::string> v;

    for (auto n : s)
    {
        if (n != c) buff += n; else
            if (n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if (buff != "") v.push_back(buff);

    return v;
}


void VulkanInfoInstance::loadModel(std::string MODEL_PATH) {
/*
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

    Mesh* mesh = new Mesh(); ;
    mesh->name = "Duck";
    mesh->vertices = vertices ;
    mesh->indices = indices ;
    mesh->model=glm::mat4(1);

    allMeshes.push_back(mesh);



    fin.close();
    */


   
std::ifstream fin;
fin.open(MODEL_PATH);

    std::vector<std::string> v;
    std::string line;
    int i = -1;
    std::vector<glm::vec3> vertPos;
    std::vector<glm::vec3> vertTex;
    std::vector<glm::vec3> vertNorm;
    std::vector<std::vector<glm::vec3>> faces;
    if (fin.is_open())
    {

        Mesh* tempM = new Mesh;
        while (getline(fin, line)) {
            if (!line.empty()) {
                v = explode(line, ' ');
            }
            else {
                v[0] = "empty";
            }
            if (!v[0].compare("g")) {
                tempM->name = line;
                getline(fin, line);
                i++;
            }

            if (!v[0].compare("v")) {
                if (i == -1) {
                    i = 0;


                }
               vertPos.push_back(glm::vec3 { stof(v[1]),stof(v[2]),stof(v[3]) });

            }


            if (!v[0].compare("vt")) {
                vertTex.push_back(glm::vec3 { stof(v[1]),stof(v[2]),0 });

            }
            if (!v[0].compare("vn")) {
               vertNorm.push_back(glm::vec3 { stof(v[1]),stof(v[2]),stof(v[3]) });
            }
            if (!v[0].compare("f")) {
                std::vector<std::string> face1, face2, face3, face4;
                face1 = explode(v[1], '/');
                face2 = explode(v[2], '/');
                face3 = explode(v[3], '/');
                std::vector<glm::vec3> tempface;

                tempface.push_back(glm::vec3 { stof(face1[0]),stof(face1[1]),stof(face1[2]) });
                tempface.push_back(glm::vec3 { stof(face2[0]),stof(face2[1]),stof(face2[2]) });
                tempface.push_back(glm::vec3 { stof(face3[0]),stof(face3[1]),stof(face3[2]) });

                faces.push_back(tempface);


               
                if (v.size() == 5) {
                    face4 = explode(v[4], '/');
                    tempface.clear();

                    tempface.push_back(glm::vec3 { stof(face1[0]),stof(face1[1]),stof(face1[2]) });
                    tempface.push_back(glm::vec3 { stof(face3[0]),stof(face3[1]),stof(face3[2]) });
                    tempface.push_back(glm::vec3 { stof(face4[0]),stof(face4[1]),stof(face4[2]) });


                
                    faces.push_back(tempface);

                }
            }
        }
        for (auto f : faces) {

            indices.push_back(indices.size() );
            indices.push_back(indices.size() );
            indices.push_back(indices.size() );

            tempM->indices.push_back(tempM->indices.size() );
            tempM->indices.push_back(tempM->indices.size() );
            tempM->indices.push_back(tempM->indices.size() );
        }


            for (auto f : faces) {
            for (auto vec : f) {

                Vertex vert;
                vert.pos = vertPos[vec[0]-1];
                vert.texCoord = vertTex[vec[1] - 1];
                vert.normCoord = vertNorm[vec[2] - 1];
                tempM->vertices.push_back(vert);
                vertices.push_back(vert);
            }
        }
        tempM->model = glm::scale(glm::mat4(1), glm:: vec3(30));
        allMeshes.push_back(tempM);
    

}
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



