#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Camera final {
public:
    Camera() = delete;

    Camera(const glm::vec3& position, float fov, float aspect, float zNear, float zFar) 
    {
        _position   = position;
        _forward    = glm::vec3(0.0f, 0.0f, 1.0f);
        _up         = glm::vec3(0.0f, 1.0f, 0.0f);
        _projection = glm::perspective(fov, aspect, zNear, zFar);
    }

    glm::mat4 GetViewProjection() const
    {
        return _projection * glm::lookAt(_position, _position + _forward, _up);
    }

private:
    glm::mat4 _projection;
    glm::vec3 _position;
    glm::vec3 _forward;
    glm::vec3 _up;
};