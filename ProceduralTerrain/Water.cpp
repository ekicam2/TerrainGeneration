#include "Water.h"



Water::Water(const glm::uvec2& size)
    : _size(size)
{
    generate();
}


Water::~Water()
{
}

void Water::generate()
{
    glm::uvec2 gridSize = { _size.x + 1, _size.y + 1 };
    float xStep = 1.0f / _size.x;
    float yStep = -1.0f / _size.y;

    uint32_t gridArraySize = gridSize.x * gridSize.y * 3;
    uint32_t gridVerticesArraySize = _size.x * _size.y * 6;

    float*      gridVertices = new float[gridArraySize];
    uint16_t*   gridIndices = new uint16_t[gridVerticesArraySize];


    // making grid's vertices
    for (uint32_t y = 0, index = 0; y < gridSize.y; ++y)
    {
        for (uint32_t x = 0; x < gridSize.x; ++x, index += 3)
        {
            gridVertices[index]     = x * xStep;
            gridVertices[index + 1] = 0.0;
            gridVertices[index + 2] = y * yStep;
        }
    }


    // making indices array for indexed rendering
    for (uint32_t index = 0, counter = 0, y = 0; y < _size.y; ++y, ++counter)
    {
        for (uint32_t x = 0; x < _size.x; ++x, index += 6, ++counter)
        {
            gridIndices[index] = counter;
            gridIndices[index + 1] = counter + gridSize.x;
            gridIndices[index + 2] = counter + gridSize.x + 1;
            gridIndices[index + 3] = counter;
            gridIndices[index + 4] = counter + gridSize.x + 1;
            gridIndices[index + 5] = counter + 1;
        }
    }

    setVertices(gridVertices, gridArraySize);
    setIndices(gridIndices, gridVerticesArraySize);

    delete[] gridVertices;
    delete[] gridIndices;
}
