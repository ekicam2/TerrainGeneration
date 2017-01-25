#pragma once

#include "Drawable.h"

class Water : public Drawable
{
public:
    Water(const glm::uvec2& size);
    ~Water();

protected:
    void generate();

private:
    glm::uvec2 _size;
};

