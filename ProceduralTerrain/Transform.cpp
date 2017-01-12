#include "Transform.h"

Transform::Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
    : _position(position), _rotation(rotation), _scale(scale)
{
}

glm::mat4 Transform::getModelMatrix()
{
    glm::mat4 positionMatrix = glm::translate(_position);

    glm::mat4 rotationMatrix;
    glm::mat4 rotationX      = glm::rotate(_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rotationY      = glm::rotate(_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotationZ      = glm::rotate(_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    rotationMatrix           = rotationX * rotationY * rotationZ;

    glm::mat4 scaleMatrix    = glm::scale(_scale);

    return positionMatrix * rotationMatrix * scaleMatrix;
}

void Transform::setPosition(glm::vec3 position)
{
    _position = position;
}

void Transform::translate(glm::vec3 transform)
{
    _position += transform;
}

glm::vec3 Transform::getPosition() const
{
    return _position;
}

void Transform::setRotation(glm::vec3 rotation)
{
    _rotation = rotation;
}
