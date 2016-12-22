#include "Program.h"
#include "Shader.h"
#include <iostream>

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
    
    if (!status) {
        int32_t blen = 0;
        glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &blen);

        if (blen > 0)
        {
            GLsizei slen = 0;
            GLchar * compiler_log = new GLchar[blen];
            glGetProgramInfoLog(_handle, blen, &slen, compiler_log);

            std::cout << "Program linkage failed: " << compiler_log;
            delete[] compiler_log;
        }
        return false;
    }
    return true;
}


void Program::bind()
{
    glUseProgram(_handle);
}

GLuint Program::getHandle() const
{
    return _handle;
}

Program::~Program()
{
    glDeleteProgram(_handle);
}
