#pragma once

#include <glm\vec2.hpp>
#include <map>

class Terrain;
class Camera;
class Program;
class Renderer;

class Scene {
public:
    Scene();
    virtual ~Scene();

    bool init(const glm::uvec2& winSize);

    void processInput(int key, int action, int mods);
    void draw(Renderer* renderer);

private:
    Terrain* _terrain;
    Camera*  _camera;
    std::map<std::string, Program*> _programs;
};