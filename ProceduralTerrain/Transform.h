#pragma once

#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>

#include <glm/gtx/transform.hpp>

class Transform final {
public:
    Transform() = default;
    Transform(const glm::vec3& position, const glm::vec3& rotation,const glm::vec3& scale = glm::vec3(1.0f));

    glm::mat4 getModelMatrix();

    void setPosition(glm::vec3 position);
    void translate(glm::vec3 transform);
    glm::vec3 getPosition() const;

    void setRotation(glm::vec3 rotation);
    /* 
        TO BE IMPLEMENTED

    void rotate(glm::vec3 rotation);
    glm::vec3 getRotation() const;

    void setScale(glm::vec3 scale);
    void scale(glm::vec3 scale);
    glm::vec3 getScale() const;
    */

private:
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
};