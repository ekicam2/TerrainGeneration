#include "Texture.h"
#include "libraries\bitmap_image.hpp"


Texture::Texture(const std::string& fileName, Type textureType)
    : _type(textureType)
{
    bitmap_image image(fileName);

    glGenTextures(1, &_handler);

    glBindTexture(_type, _handler);

    glTextureStorage2D(_type, 4, GL_RGBA, image.width, image.height);
    glTextureSubImage2D(_type, 4, 0, 0, image.width, image.height, GL_RGB, GL_UNSIGNED_BYTE, image.data);

    glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}


Texture::~Texture()
{
    glDeleteTextures(1, &_handler);
}
