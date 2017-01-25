#include "App.h"
#include "Shader.h"
#include "Heightmap.h"
#include "PerlinNoise.h"

bool App::init(const glm::vec2 & windowSize, const char * title)
{
    _window = nullptr;
    _windowSize = windowSize;

    if (!initGLFW(title))
        return false;

    return true;
}


bool App::componentsInit()
{
    _renderer = new Renderer();
    _renderer->setRenderMode(Renderer::RENDER_MODES::WIRE_FRAME);

    if (!scene.init(_windowSize))
        return false;

    return true;
}

bool App::run()
{
    while (!glfwWindowShouldClose(_window))
    {
        processInput();
        render();
    }

    return 0;
}

void App::processInput()
{
    glfwPollEvents();
}

void App::render()
{
    _renderer->clear(0.6f, 0.1f, 0.1f);
    scene.draw(_renderer);

    glfwSwapBuffers(_window);
}

App::~App()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void App::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    scene.processInput(key, action, mods);
}

bool App::initGLFW(const char * title)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    int major = 4, minor = 5;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    _window = glfwCreateWindow(_windowSize.x, _windowSize.y, title, NULL, NULL);
    if(_window == nullptr)
        return false;

    glfwMakeContextCurrent(_window);
    if (glfwGetCurrentContext == NULL)
        return false;
    
    if (!initGL3W(major, minor))
        return false;

    int w, h;
    glfwGetFramebufferSize(_window, &w, &h);
    glViewport(0, 0, w, h);

    glfwSwapInterval(1);

    // magic like in most C APIS
    glfwSetWindowUserPointer(_window, this);
    GLFWkeyfun keyboardCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        App* self = static_cast<App*>(glfwGetWindowUserPointer(window));
        self->keyboardCallback(window, key, scancode, action, mods);
    };

    glfwSetKeyCallback(_window, keyboardCallback);

    //glfwSetInputMode(_window, GLFW_STICKY_KEYS, 1);

    return true;
}

bool App::initGL3W(int major, int minor)
{
    if (gl3wInit())
        return false;

    if (!gl3wIsSupported(major, minor))
        return false;

    return true;
}
