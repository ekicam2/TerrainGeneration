#include "Program.h"
#include "Shader.h"
#include <iostream>

Program::Program()
{
    _handler = glCreateProgram();
}

void Program::attachShader(const GLuint& shader)
{
    glAttachShader(_handler, shader);
}

bool Program::link()
{
    glLinkProgram(_handler);

    int32_t status;
    glGetProgramiv(_handler, GL_LINK_STATUS, &status);
    
    if (!status) {
        int32_t blen = 0;
        glGetProgramiv(_handler, GL_INFO_LOG_LENGTH, &blen);

        if (blen > 0)
        {
            GLsizei slen = 0;
            GLchar * compiler_log = new GLchar[blen];
            glGetProgramInfoLog(_handler, blen, &slen, compiler_log);

            std::cout << "Program linkage failed: " << compiler_log;
            delete[] compiler_log;
        }
        return false;
    }
    return true;
}


void Program::bind()
{
    glUseProgram(_handler);
}

void Program::setUniformMat4(const std::string & name, const glm::mat4 & matrix)
{
    this->bind();

    auto location = getUniformLocation(name);
    if (location != -1)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
    }
}

GLint Program::getUniformLocation(const std::string & name)
{
    auto it = _uniformLocationCache.find(name.c_str());

    if (it != _uniformLocationCache.end())
    {
        return it->second;
    }
    else
    {
        glUseProgram(_handler);
        GLint location = glGetUniformLocation(_handler, name.c_str());

        if (location == -1) 
        {
            return -1;
        }

        _uniformLocationCache.insert(std::make_pair(name, location));
        return location;
    }
}

GLuint Program::getHandle() const
{
    return _handler;
}

Program::~Program()
{
    glDeleteProgram(_handler);
}
