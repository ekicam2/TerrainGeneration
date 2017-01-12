#include "App.h"
#include "Shader.h"


bool App::init(const glm::vec2 & windowSize, const char * title)
{
    _window = nullptr;
    _windowSize = windowSize;
    return initGLFW(title);
    debugProgram = nullptr;
}


bool App::componentsInit()
{
    _renderer = new Renderer();
    _renderer->setRenderMode(Renderer::RENDER_MODES::WIRE_FRAME);

    // everything below will be deleted
    {
        terrain = new Terrain(glm::vec2(16,16));

        Shader s1(Shader::Type::VERTEX, "./Shaders/debug.vs");
        Shader s2(Shader::Type::FRAGMENT, "./Shaders/debug.fs");

        if (!s1.compile() || !s2.compile())
            return false;

        debugProgram = new Program();
        debugProgram->attachShader(s1.getHandle());
        debugProgram->attachShader(s2.getHandle());

        if (!debugProgram->link())
            return false;
    }
    return true;
}

bool App::run()
{
    while (!glfwWindowShouldClose(_window))
    {
        // Keep running
        _renderer->clear(0.3f, 0.3f, 1.0f);
        debugProgram->bind();
        _renderer->draw(terrain);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    return 0;
}

App::~App()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
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
