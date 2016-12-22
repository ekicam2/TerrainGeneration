#pragma once
#include <GL\gl3w.h>
#include <stdint.h>

#include "Program.h"

class Drawable
{
public:
    enum class BUFFERS {
        VERTEX,
        COLOR,
        TEXTURE_COORD,
        SIZE
    };
    Drawable();
    Program* getProgram() const;
    GLuint   getVAO() const;
    ~Drawable();


protected:
    Program* _program;
    GLuint _VAO;
    GLuint _VBO[static_cast<uint32_t>(BUFFERS::SIZE)];
};

