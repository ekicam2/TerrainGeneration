#pragma once
#include <GL\gl3w.h>
#define GLFW_DLL 
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Program.h"
#include "Renderer.h"
#include "Drawable.h"
#include "Terrain.h"

/*
    Terrain, Program and Camera should be placed in a Scene class or something like that.
    Anyway for now it's not needed as long as program does what it has to, 
        so for simplicity it will be placed here and naming convention will be broken for them. (better than TODO: cause everyone can see that there is something wrong in here)
*/
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

