#pragma once
#include <GL\gl3w.h>
#include <stdint.h>

#include "Program.h"
#include "Transform.h"
#include "Camera.h"

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


    Drawable(Program* program, Camera* cameara);

    /*
        Fills VBO with vertex data.

        @param vertices an array of vertices
        @param size of vertices array
    */
    void setVertices(float* vertices, uint32_t size);

    /*
        Fills VBO with index data.
        
        @param indices an array of vertices indices
        @param size of indices array
    */
    void setIndices(uint16_t* indices, uint32_t size);
    
    /*
        Get size of indices data stored in the drawable's VBO.

        @return indices count;
    */
    uint32_t getIndicesNum() const;

    /*
        Fills VBO with color data

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

    /*
        Get model matrix used to calculate position of the object.

        @return the model matrix
    */
    glm::mat4 getModelMatrix() const;
    
    /*
        Set a GPU program that will be used while rendering
        
        @param program raw pointer (for now) to the program
    */
    void setProgram(Program* program);

    /*
        Get current set program used while rendering this object.
        
        @return raw pointer (for now) to the program being used
    */
    Program* getProgram() const;
    
    /*
        Set camera object that will be used to capture the drawable object.

        @param camera raw pointer (for now) to the camera object
    */
    void setCamera(Camera* camera);

    /*
        Get camera that captures the object.

        @return raw pointer (for now) to the object camera
    */
    Camera* getCamera() const;

    /*
        Get current VAO that represents the drawable.

        @return GLuint handler to the VAO
    */
    GLuint getVAO() const;

    ~Drawable();

    void setPosition(const glm::vec3& position)
    {
        _transform.setPosition(position);
    }

protected:
    Transform _transform;
    Program*  _program;
    Camera*   _camera;
    GLuint    _VAO;
    GLuint    _VBO[static_cast<uint32_t>(BUFFERS::SIZE)];

    uint32_t _indicesNum;
};