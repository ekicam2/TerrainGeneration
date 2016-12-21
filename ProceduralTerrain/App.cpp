#include "App.h"
#include "Shader.h"


bool App::init(glm::vec2 && size, const char * title)
{
    _window = nullptr;
    debugProgram = nullptr;
    return initGLFW(std::move(size), title);
}


bool App::debugInit()
{
    static const GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    Shader s1(Shader::Type::VERTEX, "./Shaders/debug.vs");
    Shader s2(Shader::Type::FRAGMENT, "./Shaders/debug.fs");

    if (!s1.compile() || !s2.compile())
        return false;

    debugProgram = new Program();
    debugProgram->attachShader(s1.getHandle());
    debugProgram->attachShader(s2.getHandle());

    if (!debugProgram->link())
        return false;

    glGenVertexArrays(1, &debugVAO);
    glBindVertexArray(debugVAO);

    glGenBuffers(1, &debugVBO);
    glBindBuffer(GL_ARRAY_BUFFER, debugVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

bool App::run()
{
    while (!glfwWindowShouldClose(_window))
    {
        // Keep running
        glClearColor(1.0f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        
        debugProgram->bind();
        glBindBuffer(GL_ARRAY_BUFFER, debugVBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glEnableVertexAttribArray(0);

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

bool App::initGLFW(glm::vec2 && size, const char * title)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    int major = 4, minor = 5;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    _window = glfwCreateWindow(size.x, size.y, title, NULL, NULL);
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
