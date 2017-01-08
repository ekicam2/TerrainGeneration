#pragma once
#include "Drawable.h"
#include <glm\vec2.hpp>

class Terrain : public Drawable
{
public:
    Terrain() = delete;

    /*
        Generete flat plane based on gived size.

        @param size The size of tiled terrain
    */
    Terrain(const glm::vec2& size);
    void generate();
    // TODO: heightmap 
    ~Terrain();

private:
    glm::vec2 _size;

};

