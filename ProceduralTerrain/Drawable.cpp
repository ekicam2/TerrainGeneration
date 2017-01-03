#include "Drawable.h"


Drawable::Drawable()
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    
    glGenBuffers(static_cast<uint32_t>(BUFFERS::TEXTURE_COORD), _VBO);
    
    glBindVertexArray(0);
}

Drawable::Drawable(Program* program)
:    Drawable()
{
    _program = program;
}

void Drawable::setVertices(float* vertices, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::VERTEX)]);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setIndices(unsigned short * indices, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::INDEX)]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_UNSIGNED_SHORT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setColor(float* colors, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::COLOR)]);
    glBufferData(GL_ARRAY_BUFFER, size, colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setTextureCoords(float* uvs, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::COLOR)]);
    glBufferData(GL_ARRAY_BUFFER, size, uvs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}


Drawable::~Drawable()
{
    glDeleteBuffers(static_cast<uint32_t>(BUFFERS::SIZE), _VBO);
    glDeleteVertexArrays(1, &_VAO);
}

Program * Drawable::getProgram() const
{
    return _program;
}

GLuint Drawable::getVAO() const
{
    return _VAO;
}
