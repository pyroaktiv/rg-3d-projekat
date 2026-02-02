#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>


struct Light {
    glm::vec3 pos;
    glm::vec3 kA;
    glm::vec3 kD;
    glm::vec3 kS;
};

struct Material {
    glm::vec3 kA;
    glm::vec3 kD;
    glm::vec3 kS;
    float shine;
    float alpha;
};

struct TexScale {
    float scaleS;
    float scaleT;
};


class Shader
{
public:
    unsigned int ID;

    Shader();

    // Constructor reads & builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Activate the shader
    void use() const;

    // Utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;

    void setMat3(const std::string& name, const glm::mat3& mat) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

    void setLight(const std::string& name, const Light& light) const;
    void setMaterial(const std::string& name, const Material& material) const;
    void setTexScale(const std::string& name, const TexScale& scale) const;

    int getUniformLocation(const std::string& name) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
