#include "Renderer.h"
#include <GL\gl3w.h>

#include "Drawable.h"

Renderer::Renderer() 
{
}


Renderer::~Renderer()
{
}

void Renderer::clear(float R, float G, float B, float A)
{
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const Drawable* drawable)
{


    glBindVertexArray(drawable->getVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
