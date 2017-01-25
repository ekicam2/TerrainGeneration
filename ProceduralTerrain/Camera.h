#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Camera final {
public:
    Camera() = delete;

    Camera(const glm::vec3& position, float fov, float aspect, float zNear, float zFar);

    glm::mat4 getViewProjection() const;

    void setPosition(const glm::vec3& position);
    void translate(const glm::vec3& position);

private:
    glm::mat4 _projection;
    glm::vec3 _position;
    glm::vec3 _forward;
    glm::vec3 _up;
};