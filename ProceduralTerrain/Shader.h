#pragma once
#include <GL\glew.h>
#include <string>
#include <inttypes.h>

class Shader final{
public:
    enum class Type : uint32_t {
        VERTEX = 0x8B31,
        FRAGMENT = 0x8B30,
        GEOMETRY = 0x8DD9,
        TESS_CONTROL = 0x8E88,
        TESS_EVALUATION = 0x8E87,
        COMPUTE = 0x91B9
    };

    Shader() = delete;
    Shader(Type type, std::string&& fileName);
    bool compile();
    GLuint getHandle() const;
    ~Shader();

private:
    Type _type;
    GLuint _handle;
};

