#pragma once
#include <GL\gl3w.h>
#define GLFW_DLL 
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Program.h"
#include "Renderer.h"
#include "Drawable.h"
#include "Terrain.h"

class App final {
public:
    App() = default;
    bool init(const glm::vec2& windowSize, const char* title);
    bool componentsInit();
    bool run();


    ~App();
private:
    GLFWwindow* _window;
    glm::vec2 _windowSize;

    Renderer* _renderer;
    Terrain* terrain;

    bool initGLFW(const char * title);
    bool initGL3W(int major, int minor);

    Program* debugProgram;
    Camera* camera;
};

