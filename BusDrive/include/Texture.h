#pragma once

#include <GL/glew.h>
#include <string>

class Texture
{
public:
    unsigned int ID;
    int width, height, nrChannels;

    Texture();
    Texture(const char* filePath, GLenum wrapping = GL_REPEAT, GLenum filtering = GL_LINEAR);

    void bind(unsigned int unit = 0) const;
    void unbind() const;
};