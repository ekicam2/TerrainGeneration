#include "Camera.h"

Camera::Camera(const glm::vec3 & position, float fov, float aspect, float zNear, float zFar)
{
    _position = position;
    _forward = glm::vec3(0.0f, 0.0f, 1.0f);
    _up = glm::vec3(0.0f, 1.0f, 0.0f);
    _projection = glm::perspective(fov, aspect, zNear, zFar);
}

glm::mat4 Camera::getViewProjection() const
{
    return _projection * glm::lookAt(_position, _position + _forward, _up);
}

void Camera::setPosition(const glm::vec3 & position)
{
    _position = position;
}

void Camera::translate(const glm::vec3 & position)
{
    _position += position;
}
