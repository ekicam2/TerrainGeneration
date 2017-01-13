#include "Renderer.h"
#include <GL\gl3w.h>

#include "Drawable.h"

Renderer::Renderer() 
: _renderMode(RENDER_MODES::SHADED){
}


Renderer::~Renderer()
{
}

void Renderer::clear(float R, float G, float B, float A)
{
    glClearColor(R, G, B, A);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::setRenderMode(RENDER_MODES && renderMode)
{
    _renderMode = renderMode;
}

Renderer::RENDER_MODES Renderer::getRemderMode() const
{
    return _renderMode;
}

void Renderer::draw(const Drawable* drawable)
{
    switch (_renderMode) {
    case RENDER_MODES::POINTS:
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        glEnable(GL_POINT_SIZE);
        glPointSize(3);
        break;

    case RENDER_MODES::WIRE_FRAME:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;

    case RENDER_MODES::SHADED:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    }

    auto shaderProgram = drawable->getProgram();
    
    if (shaderProgram)
        shaderProgram->bind();

    glm::mat4 vp = drawable->getCamera()->getViewProjection();
    glm::mat4 m  = drawable->getModelMatrix();
    shaderProgram->setUniformMat4("mvp", vp * m);

    glBindVertexArray(drawable->getVAO());
    glDrawElementsBaseVertex(GL_TRIANGLES, drawable->getIndicesNum(), GL_UNSIGNED_SHORT, (void*)0, 0);
    glBindVertexArray(0);
}
