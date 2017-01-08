#include "Terrain.h"

#include <iostream>

Terrain::Terrain(glm::vec2&& size)
    : _size(size)
{
    generate();
    /*
    //for now we are just moving within standard -1...1 space verticaly and horizontaly
    float sqrVertices[12];

    for (uint32_t y = 0; y < _size.y + 1; ++y) {
        for (uint32_t x = 0; x < (size.x * 3) + 1; x += 3) {
            uint32_t currIndex = (_size.x + 1) * y + (x / 3);

            sqrVertices[currIndex] = 
        }
    }

    setVertices(sqrVertices, 12 * sizeof(float));


    unsigned short sqrIndices[6] = {
        0,
        1,
        2,
        3,
        0,
        2
    };

    setIndices(sqrIndices, 6 * sizeof(short));
    */
}


Terrain::~Terrain()
{
}


void Terrain::generate() {
    glm::vec2 gridSize       = { _size.x + 1, _size.y + 1 };
    float xStep              = 1.0f / _size.x;
    float yStep              = -1.0f / _size.y;

    float*      gridVertices = new float[gridSize.x * gridSize.y * 3];
    uint16_t*   gridIndices  = new uint16_t[_size.x * _size.y * 6];



    for (uint32_t y = 0, index = 0; y < gridSize.y; ++y) {
        for (uint32_t x = 0; x < gridSize.x; ++x, index += 3) {
            uint16_t currentIndex = y * gridSize.x + x;

            gridVertices[index] = x * xStep;
            gridVertices[index + 1] = y * yStep;
            gridVertices[index + 2] = 0.0f;

            //debug code left for now
            std::cout << currentIndex << " :" << gridVertices[index] << ", " <<
                                          gridVertices[index + 1] << ", " <<
                                          gridVertices[index + 2] << std::endl;
        }
    }

    setVertices(gridVertices, gridSize.x * gridSize.y * 3 * sizeof(float));

    uint16_t ind[24];

    for (uint32_t index = 0, counter = 0, y = 0; y < _size.y; ++y, ++counter)
    {
        for (uint32_t x = 0; x < _size.x; ++x, index += 6, ++counter) {
            gridIndices[index]     = counter;
            gridIndices[index + 1] = counter + gridSize.x;
            gridIndices[index + 2] = counter + gridSize.x + 1;
            gridIndices[index + 3] = counter;
            gridIndices[index + 4] = counter + gridSize.x + 1;
            gridIndices[index + 5] = counter + 1;

            //debug code left for now
            std::cout << index     << ": " << gridIndices[index] << std::endl;
            std::cout << index + 1 << ": " << gridIndices[index + 1] << std::endl;
            std::cout << index + 2 << ": " << gridIndices[index + 2] << std::endl;
            std::cout << index + 3 << ": " << gridIndices[index + 3] << std::endl;
            std::cout << index + 4 << ": " << gridIndices[index + 4] << std::endl;
            std::cout << index + 5 << ": " << gridIndices[index + 5] << std::endl;
        }
    }

    uint32_t indsize = _size.x * _size.y * 6 * sizeof(uint16_t);
    setIndices(gridIndices, indsize);
}