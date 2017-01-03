#pragma once
#include "Drawable.h"
#include <glm\vec2.hpp>

class Terrain : public Drawable
{
public:
    Terrain() = delete;
    Terrain(glm::vec2&& size);
    // TODO: heightmap 
    ~Terrain();

private:
    glm::vec2 _size;

};

