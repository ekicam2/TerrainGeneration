#pragma once
#include <GL/gl3w.h>
class Shader;

class Program final {
public:
    Program();
    void attachShader(GLuint&& shader);
    bool link();
    void bind();
    GLuint getHandle() const;
    ~Program();

private:
    GLuint _handle;
};

