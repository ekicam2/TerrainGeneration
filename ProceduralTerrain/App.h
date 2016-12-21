#pragma once
#include <GL\glew.h>
#define GLFW_DLL 
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Program.h"

class App final {
public:
    App() = default;
    bool init(glm::vec2&& size, const char* title);
    bool run();

    void debugInit();

    ~App();
private:
    GLFWwindow* _window;

    bool initGLFW(glm::vec2 && size, const char * title);
    bool initGLEW();

    Program* debugProgram;
    GLuint debugVAO;
    GLuint debugVBO;
};

