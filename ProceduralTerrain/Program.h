#pragma once
#include <GL/glew.h>
class Shader;

class Program final {
public:
    Program();
    void attachShader(GLuint&& shader);
    bool link();
    void bind();
    ~Program();

private:
    GLuint _handle;
};

