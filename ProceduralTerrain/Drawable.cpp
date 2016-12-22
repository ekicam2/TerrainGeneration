#include "Drawable.h"



Drawable::Drawable()
{
    static const GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    // create buffer
    glGenBuffers(1, &_VBO[static_cast<uint32_t>(BUFFERS::VERTEX)]);
    // bind it to use it
    glBindBuffer(GL_ARRAY_BUFFER, _VBO[static_cast<uint32_t>(BUFFERS::VERTEX)]);
    // fill it with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // and mark it as useable
    glEnableVertexAttribArray(0);
    // tell opengl how to read it
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);
}


Drawable::~Drawable()
{
}

Program * Drawable::getProgram() const
{
    return _program;
}

GLuint Drawable::getVAO() const
{
    return _VAO;
}
