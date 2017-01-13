#include "Shader.h"

#include <fstream>

using namespace std;

Shader::Shader(Type type, const std::string& fileName)
: _type(type) {

    _handle = glCreateShader(static_cast<uint32_t>(_type));

    auto file = ifstream(fileName);
    string line;
    string source = "";
    if (file.is_open()) {
        while (getline(file, line)) {
            source.append(line + "\n");
        }
    }
    else {
        DebugBreak();
    }
    const GLchar* src = const_cast<GLchar*>(source.c_str());
    gl3wShaderSource(_handle, 1, &src, 0);
}

bool Shader::compile()
{
    glCompileShader(_handle);

    int32_t status;
    glGetShaderiv(_handle, GL_COMPILE_STATUS, &status);

    if (!status)
        return false;

    return true;
}

GLuint Shader::getHandle() const
{
    return _handle;
}

Shader::~Shader()
{
    glDeleteShader(_handle);
}
