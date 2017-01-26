#pragma once

#include <stdint.h>
#include <GL\gl3w.h>

class Texture
{
public:
    enum Type {
        TEXTURE_2D = 0x0DE1
    };

    Texture() = delete;
    Texture(const std::string& fileName, Type textureType);
    ~Texture();

private:
    GLuint     _handler;
    const Type _type;
};

