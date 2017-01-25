#pragma once
#include "Drawable.h"
#include <glm\vec2.hpp>

class Heightmap;

class Terrain : public Drawable
{
public:
    Terrain() = delete;

    /*
        Generate terrain based of height ma,
        otherwise generate a flat plane.

        @param size amount of tiles
        @param heightmap 
    */
    Terrain(const glm::uvec2& size, Heightmap* heightmap = nullptr);

    ~Terrain() = default;

protected:
    void generate(Heightmap* heightmap);

private:
    glm::uvec2 _size;

};

