#include "Heightmap.h"
#include "PerlinNoise.h"
#include "Utilities.h"

#include <ostream>

Heightmap::Heightmap(const std::string & fileName, const glm::uvec2 & size,const PerlinNoise& perlin)
    : _bitmap(nullptr)
{
    if (!open(fileName))
        create(fileName, size, perlin);
}

uint32_t Heightmap::getWidth() const
{
    return _bitmap->width();
}

uint32_t Heightmap::getHeight() const
{
    return _bitmap->height();
}

glm::uvec2 & Heightmap::getSize() const
{
    return glm::uvec2(_bitmap->width(), _bitmap->height());
}

uint8_t Heightmap::getWorldHeight(uint32_t x, uint32_t y)
{
    rgb_t value;
    _bitmap->get_pixel(x, y, value);

    return (value.red == value.green && value.green == value.blue) ? value.red : 0;
}

bool Heightmap::open(const std::string & fileName)
{
    _bitmap = new bitmap_image(fileName);

    if (_bitmap->height() == 0 || _bitmap->width() == 0)
        return false;

    return true;
}

void Heightmap::create(const std::string& fileName, const glm::uvec2& size, const PerlinNoise& perlin)
{
    _bitmap = new bitmap_image(size.x, size.y);
    
    for (uint32_t i = 0; i < size.y; ++i)
    {
        for (uint32_t j = 0; j < size.x; ++j)
        {
            double y = (double)i / (double)size.y;
            double x = (double)j / (double)size.x;

            uint8_t value = mapValue(perlin.noise(10 * x, 10 * y, 0.8), -1.0, 1.0, 0, 255);
            
            rgb_t color;
            color.red = color.green = color.blue = value;
            _bitmap->set_pixel(i, j, color);
        }
    }
    
    _bitmap->save_image(fileName);
}

