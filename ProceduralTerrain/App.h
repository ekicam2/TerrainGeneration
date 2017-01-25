#pragma once
#include <GL\gl3w.h>
#define GLFW_DLL 
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Renderer.h"
#include "Scene.h"


class App final {
public:
    App() = default;
    bool init(const glm::vec2& windowSize, const char* title);
    bool componentsInit();
    bool run();

    void processInput();
    void render();

    ~App();
private:
    GLFWwindow* _window;
    glm::vec2 _windowSize;

    Renderer* _renderer;

    Scene scene;

    void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    bool initGLFW(const char * title);
    bool initGL3W(int major, int minor);
};

