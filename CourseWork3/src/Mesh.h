#ifndef MESH_H
#define MESH_H

#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>

enum class TextureType {
    Albedo,
    Normal,
    Metallic,
    // AmbientOcclusion,
    Roughness    
};

std::string to_string(TextureType type);

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;   
};

struct Texture {
    unsigned int id;
    TextureType type;
    std::string path;
};

const int BLINN_PHONG = 4;

class Mesh {
public:       
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures);

    // Render the mesh
    void Draw(Shader shader);

    void setAmbient(glm::vec3 ambient) { _ambient = ambient; }

    void setDiffuse(glm::vec3 diffuse) { _diffuse = diffuse; }

    void setSpecular(glm::vec3 specular) { _specular = specular; }

    void setShininess(float shininess) { _shininess = shininess; }

    void setOpacityRatio(float opacity) { _opacityRatio = opacity; }

    void setRefractionRatio(float refraction) { _refractionRatio = refraction; }

    glm::vec3 getAmbient() { return _ambient; }

    glm::vec3 getDiffuse() { return _diffuse; }

    glm::vec3 getSpecular() { return _specular; }

    float getShininess() { return _shininess; }

    float getOpacityRatio() { return _opacityRatio; }

    float getRefractionRatio() { return _refractionRatio; }

private:
    // Initializes all the buffer objects/arrays
    void setupMesh();

private:
    // Render data
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    // Mesh data
    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    std::vector<Texture> _textures; 

    // Material properties
    glm::vec3 _ambient;
    glm::vec3 _diffuse;
    glm::vec3 _specular;
    float _opacityRatio;
    float _refractionRatio;
    float _shininess;
};
#endif

