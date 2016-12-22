#pragma once
#include <inttypes.h>

class Drawable;

class Renderer
{
public:
    enum class RENDER_MODES : uint32_t {
        POINTS,
        WIRE_FRAME,
        SHADED
    };

    Renderer();
    void clear(float R, float G, float B, float A = 0.0f);
    
    void setRenderMode(RENDER_MODES&& renderMode);
    RENDER_MODES getRemderMode() const;

    // DOD rule of thumb if there is one there are many!
    void draw(const Drawable* object);
    ~Renderer();


private:
    RENDER_MODES _renderMode;
};

