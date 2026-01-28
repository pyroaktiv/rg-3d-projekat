#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

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

    int getUniformLocation(const std::string& name) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
