#pragma once
#include <GL\gl3w.h>
#include <stdint.h>

#include "Program.h"

class Drawable
{
public:
    enum class BUFFERS {
        VERTEX,
        INDEX,
        COLOR,
        TEXTURE_COORD,
        SIZE
    };
    Drawable();
    Drawable(Program* program);

    /*
        Fills VBO with vertex data.

        @param vertices an array of vertices
        @param size of vertices array in bytes
    */
    void setVertices(float* vertices, uint32_t size);

    /*
        Fills VBO with index data.
        
        @param indices an array of vertices indices
        @param size of indices array in bytes
    */
    void setIndices(uint16_t* indices, uint32_t size);
    
    /*
    Get size of indices data stored in the drawable's VBO.

    @return vertices size in bytes;
    */
    uint32_t getIndicesSize() const;

    /*
    Fills VBO with color data.

    @param colors an array of colors
    @param size of colors array in bytes
    */
    void setColor(float* colors, uint32_t size);

    /*
    Fills VBO with UVs data.

    @param uvs an array of texture coordinates
    @param size of uvs array in bytes
    */
    void setTextureCoords(float* uvs, uint32_t size);

    Program* getProgram() const;
    GLuint   getVAO() const;
    ~Drawable();


protected:
    Program* _program;
    GLuint   _VAO;
    GLuint   _VBO[static_cast<uint32_t>(BUFFERS::SIZE)];

    uint32_t _indicesSize;
};