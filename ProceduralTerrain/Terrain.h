#pragma once
#include "Drawable.h"
#include <glm\vec2.hpp>

class Heightmap;

class Terrain : public Drawable
{
public:
    Terrain() = delete;

    /*
        Generete flat plane based on gived size.

        @param size The size of tiled terrain
    */
    Terrain(const glm::uvec2& size);

    /*
        Generete flat plane based on gived size.

        @param size The size of tiled terrain
        @param heightmap 
    */
    Terrain(const glm::uvec2& size, Heightmap* heightmap);

    ~Terrain() = default;

protected:
    void generate();
    void generate(Heightmap* heightmap);

private:
    glm::uvec2 _size;

};

