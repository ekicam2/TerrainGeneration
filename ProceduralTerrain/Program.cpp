#include "Program.h"
#include "Shader.h"

Program::Program()
{
    _handle = glCreateProgram();
}

void Program::attachShader(GLuint&& shader)
{
    glAttachShader(_handle, shader);
}

bool Program::link()
{
    glLinkProgram(_handle);

    int32_t status;
    glGetProgramiv(_handle, GL_LINK_STATUS, &status);
    
    if (!status)
        return false;

    return true;
}

void Program::bind()
{
    glUseProgram(_handle);
}

Program::~Program()
{
    glDeleteProgram(_handle);
}
