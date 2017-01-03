#include "Terrain.h"



Terrain::Terrain(glm::vec2&& size)
    : _size(size)
{
    //for now we are just moving within standard -1...1 space verticaly and horizontaly
    float sqrVertices[12];

    sqrVertices[0]  = -0.5f;
    sqrVertices[1]  =  0.5f;
    sqrVertices[2]  =  0.0f;

    sqrVertices[3]  = -0.5f;
    sqrVertices[4]  = -0.5f;
    sqrVertices[5]  =  0.0f;

    sqrVertices[6]  =  0.5f;
    sqrVertices[7]  = -0.5f;
    sqrVertices[8]  =  0.0f;

    sqrVertices[9]  =  0.5f;
    sqrVertices[10] =  0.5f;
    sqrVertices[11] =  0.0f;

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
}


Terrain::~Terrain()
{
}
