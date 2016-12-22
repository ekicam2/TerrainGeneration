#pragma once

class Drawable;

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void clear(float R, float G, float B, float A = 0.0f);

    // DOD rule of thumb if there is one there are many!
    void draw(const Drawable* object);

private:

};

