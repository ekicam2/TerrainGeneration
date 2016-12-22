#pragma once
#include <GL\gl3w.h>
#define GLFW_DLL 
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Program.h"
#include "Renderer.h"
#include "Drawable.h"

class App final {
public:
    App() = default;
    bool init(glm::vec2&& size, const char* title);
    bool componentsInit();
    bool run();


    ~App();
private:
    GLFWwindow* _window;
    Renderer* renderer;
    Drawable* drawable;

    bool initGLFW(glm::vec2 && size, const char * title);
    bool initGL3W(int major, int minor);

    Program* debugProgram;
};

