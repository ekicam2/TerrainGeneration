#include "Scene.h"
#include "Terrain.h"
#include "Camera.h"
#include "Program.h"
#include "Heightmap.h"
#include "PerlinNoise.h"
#include "Shader.h"
#include "Renderer.h"

#include <GLFW\glfw3.h>

Scene::Scene()
    : _terrain(nullptr), 
      _camera(nullptr)
{

}

Scene::~Scene()
{
    delete _terrain;
    delete _camera;

    auto it  = _programs.begin();
    auto end = _programs.end();
    
    while (it != end)
    {
        delete it->second;
        it = _programs.erase(it);
    }
}

bool Scene::init(const glm::uvec2 & winSize)
{
    _camera = new Camera(glm::vec3(0, 0, 0), glm::radians(45.0f), winSize.x / winSize.y, 0.001f, 100.0f);
    _programs.insert(std::make_pair("terrainProgram", new Program()));
    _terrain = new Terrain(glm::vec2(126, 126), new Heightmap("heightmap.bmp", { 600, 600 }, PerlinNoise(8123)));
    
    auto terrainProgram = _programs.find("terrainProgram")->second;

    Shader s1(Shader::Type::VERTEX, "./Shaders/debug.vs");
    Shader s2(Shader::Type::FRAGMENT, "./Shaders/debug.fs");

    if (!s1.compile() || !s2.compile())
        return false;

    terrainProgram->attachShader(s1.getHandle());
    terrainProgram->attachShader(s2.getHandle());

    if (!_programs.find("terrainProgram")->second->link())
        return false;

    _terrain->setPosition({ -0.5f, 0.3f, 1.0f });
    _terrain->setRotation({ glm::radians(60.0f), 0.0f, 0.0f });
    _terrain->setProgram(terrainProgram);
    _terrain->setCamera(_camera);
    
    return true;
}

void Scene::processInput(int key, int action, int mods)
{
    float step = 0.008;

    if (key == GLFW_KEY_W && action == GLFW_REPEAT)
        _camera->translate({ 0, 0, step });

    if (key == GLFW_KEY_S && action == GLFW_REPEAT)
        _camera->translate({ 0, 0, -step });
    
    if (key == GLFW_KEY_A && action == GLFW_REPEAT)
        _camera->translate({ step, 0, 0 });

    if (key == GLFW_KEY_D && action == GLFW_REPEAT)
        _camera->translate({ -step, 0, 0 });
}

void Scene::draw(Renderer * renderer)
{
    renderer->draw(_terrain);
}
