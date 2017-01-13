#pragma once
#include <GL/gl3w.h>
#include <glm\mat4x4.hpp>
#include <string>
#include <map>

class Program final {
public:

    typedef std::map<std::string, GLuint> UniformTable;
    
    Program();
    void attachShader(const GLuint& shader);
    bool link();
    void bind();

    void setUniformMat4(const std::string& name, const glm::mat4& matrix);
    GLint getUniformLocation(const std::string& name);
    GLuint getHandle() const;
    ~Program();

private:
    GLuint _handler;

    UniformTable _uniformLocationCache;
};

