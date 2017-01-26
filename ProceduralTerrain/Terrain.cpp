#include "Terrain.h"
#include "Heightmap.h"
#include "Utilities.h"

#include <iostream>

Terrain::Terrain(const glm::uvec2 & size, Heightmap* heightmap)
    : _size(size),
      _heightmap(heightmap)
{
    generate();
}

void Terrain::generate()
{
    glm::uvec2 gridSize = { _size.x + 1, _size.y + 1 };
    float xStep =  1.0f / _size.x;
    float yStep = -1.0f / _size.y;

    uint32_t gridVerticesArraySize  = gridSize.x * gridSize.y * 3;
    uint32_t gridIndicesArraySize   = _size.x    * _size.y    * 6;

    float*    gridVertices         = new float[gridVerticesArraySize];
    uint16_t* gridIndices          = new uint16_t[gridIndicesArraySize];

    // making grid's vertices
    for (uint32_t y = 0, index = 0; y < gridSize.y; ++y)
    {
        for (uint32_t x = 0; x < gridSize.x; ++x, index += 3)
        {
            float mappedTerrainHeight = 0.0f;
            if(_heightmap)
                mappedTerrainHeight = mapValue(_heightmap->getWorldHeight(x, y), 0.0f, 255.0f, -0.2f, 0.2f);
            
            gridVertices[index]         = x * xStep;
            gridVertices[index + 1]     = mappedTerrainHeight;
            gridVertices[index + 2]     = y * yStep;
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

    setVertices(gridVertices, gridVerticesArraySize);
    setIndices(gridIndices, gridIndicesArraySize);

    delete[] gridVertices;
    delete[] gridIndices;
}
