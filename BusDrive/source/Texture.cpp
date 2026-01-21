#include "../include/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include <iostream>

Texture::Texture(const char* filePath, GLenum wrapping, GLenum filtering)
{
    glGenTextures(1, &ID);

    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);

    if (data)
    {
        GLenum format = GL_RGB;
        if (nrChannels == 1)      format = GL_RED;
        else if (nrChannels == 3) format = GL_RGB;
        else if (nrChannels == 4) format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, ID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapping);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapping);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering);

        stbi_image_free(data);
    }
    else
    {
        std::cerr << "Failed to load texture at: " << filePath << std::endl;
        stbi_image_free(data);
    }
}

void Texture::bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}