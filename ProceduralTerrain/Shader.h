#pragma once
#include <GL\gl3w.h>
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

    /*
        Create a shader object.
        
        @param type of creating shader specified by enum Shader::Type
        @param fileName souce shader file
    */

    Shader(Type type, const std::string& fileName);

    /*
        Compile the shader.

        @return true on success false otherwise
    */
    bool compile();

    /*
        Get shader object handler.

        @return GLuint shader handler
    */
    GLuint getHandle() const;

    ~Shader();

private:
    Type _type;
    GLuint _handle;
};

