#include "App.h"

#include "Shader.h"

bool App::init(glm::vec2 && size, const char * title)
{
    return initGLFW(std::move(size), title);
}


void App::debugInit()
{
    static const GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };



    Shader s1(Shader::Type::VERTEX, "Shaders/debug.vs");
    Shader s2(Shader::Type::FRAGMENT, "Shaders/debug.fs");

    if (!s1.compile() || !s2.compile())
        throw("lolololo");

    debugProgram->attachShader(s1.getHandle());
    debugProgram->attachShader(s2.getHandle());

    if (!debugProgram->link())
        throw("lololo2");

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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    if (_window = glfwCreateWindow(size.x, size.y, title, NULL, NULL))
        return false;

    glfwMakeContextCurrent(_window);
    if (glfwGetCurrentContext == NULL)
        return false;

    initGLEW();

    int w, h;
    glfwGetFramebufferSize(_window, &w, &h);
    glViewport(0, 0, w, h);

    glfwSwapInterval(1);

    return true;
}

bool App::initGLEW()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        return false;

    glGenVertexArrays(1, &debugVAO);
    glBindVertexArray(debugVAO);

    return true;
}
