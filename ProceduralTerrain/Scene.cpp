#include "Scene.h"
#include "Terrain.h"
#include "Camera.h"
#include "Program.h"
#include "Heightmap.h"
#include "PerlinNoise.h"
#include "Shader.h"
#include "Renderer.h"
#include "Water.h"

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
    _terrain = new Terrain(glm::vec2(200, 200), new Heightmap("heightmap.bmp", { 600, 600 }, PerlinNoise(8123)));
    _waterPlane = new Water(glm::uvec2(125, 125));
    
    // terrain shader
    _programs.insert(std::make_pair("terrainProgram", new Program()));
    auto terrainProgram = _programs.find("terrainProgram")->second;

    Shader ts1(Shader::Type::VERTEX, "./Shaders/terrainShader.vs");
    Shader ts2(Shader::Type::FRAGMENT, "./Shaders/terrainShader.fs");

    if (!ts1.compile() || !ts2.compile())
        return false;

    terrainProgram->attachShader(ts1.getHandle());
    terrainProgram->attachShader(ts2.getHandle());

    if (!_programs.find("terrainProgram")->second->link())
        return false;

    // water shader
    _programs.insert(std::make_pair("waterProgram", new Program()));
    auto waterProgram = _programs.find("waterProgram")->second;

    Shader ws1(Shader::Type::VERTEX, "./Shaders/waterShader.vs");
    Shader ws2(Shader::Type::FRAGMENT, "./Shaders/waterShader.fs");

    if (!ws1.compile() || !ws2.compile())
        return false;

    waterProgram->attachShader(ws1.getHandle());
    waterProgram->attachShader(ws2.getHandle());

    if (!_programs.find("waterProgram")->second->link())
        return false;

    _terrain->setPosition({ -0.5f, 0.0f, 1.0f });
    _terrain->setRotation({ glm::radians(-30.0f), 0.0f, 0.0f });
    _terrain->setProgram(terrainProgram);
    _terrain->setCamera(_camera);

    _waterPlane->setPosition({ -0.5f, -0.02f, 1.0f });
    _waterPlane->setRotation({ glm::radians(-30.0f), 0.0f, 0.0f });
    _waterPlane->setProgram(waterProgram);
    _waterPlane->setCamera(_camera);
    
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
    renderer->setRenderMode(Renderer::RENDER_MODES::SHADED);
    renderer->draw(_terrain);
    renderer->draw(_waterPlane);
}
