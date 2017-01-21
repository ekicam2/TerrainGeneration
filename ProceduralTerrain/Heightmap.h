#pragma once

#include <string>
#include <stdint.h>
#include <glm\vec2.hpp>

#include "libraries\bitmap_image.hpp"

class PerlinNoise;

class Heightmap
{
public:
    Heightmap() = delete;
    Heightmap(const std::string& fileName, const glm::uvec2& size, const PerlinNoise& perlin);
    ~Heightmap() = default;

    uint32_t getWidth() const;
    uint32_t getHeight() const;
    glm::uvec2& getSize() const;

    uint8_t getWorldHeight(uint32_t x, uint32_t y) const;

protected:
    bool open(const std::string& fileName);
    void create(const std::string& fileName, const glm::uvec2& size, const PerlinNoise& perlin);

private:
    bitmap_image* _bitmap;
};

