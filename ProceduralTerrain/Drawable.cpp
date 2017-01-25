#include "Drawable.h"


Drawable::Drawable()
    : _program(nullptr),
      _camera(nullptr)
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    
    glGenBuffers(static_cast<uint32_t>(BUFFERS::SIZE), _VBO);
    
    glBindVertexArray(0);
}

Drawable::Drawable(Program* program, Camera* camera)
:    Drawable()
{
    _program = program;
    _camera  = camera;
}

void Drawable::setVertices(float* vertices, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::VERTEX)]);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setIndices(uint16_t* indices, uint32_t size)
{
    _indicesNum = size;

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::INDEX)]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(uint16_t), indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_UNSIGNED_SHORT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

uint32_t Drawable::getIndicesNum() const
{
    return _indicesNum;
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

void Drawable::setNormals(float * normals, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::COLOR)]);
    glBufferData(GL_ARRAY_BUFFER, size, normals, GL_STATIC_DRAW);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setTextureCoords(float* uvs, uint32_t size)
{
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::COLOR)]);
    glBufferData(GL_ARRAY_BUFFER, size, uvs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}

void Drawable::setProgram(Program * program)
{
    _program = program;
}

Program * Drawable::getProgram() const
{
    return _program;
}

void Drawable::setCamera(Camera * camera)
{
    _camera = camera;
}

Camera * Drawable::getCamera() const
{
    return _camera;
}

GLuint Drawable::getVAO() const
{
    return _VAO;
}

Drawable::~Drawable()
{
    glDeleteBuffers(static_cast<uint32_t>(BUFFERS::SIZE), _VBO);
    glDeleteVertexArrays(1, &_VAO);
}