#include "App.h"

/*
TODO:
1 make a triangle and draw at the screen [X]
    1 make 3 vertices [X]
    2 make vertex shader [X]
    3 make fragment shader [X]
    4 compile shaders [X]
    5 link them into a program [X]
    6 draw it on the screen [X]
2 make a triangle strip and draw at the screen [X]
    1 make a grid based on a triangle strip [X]
3 make mvp and so on [X]
    1 extend programs to send matrices to shaders [X]
    2 rewrite shaders and use mvp [X]
        1 for now just rotate and move plane [X]
4 make perlin noise algorithm [ ]
    1 code perlin noise algorith [X]
    2 draw it to a texture [ ]
    3 read from the texture [ ]
*/

#include <iostream>
using namespace std;

int main()
{
    App application;
    if (!application.init(glm::vec2(1024, 768), "Triangle yai"))
        return -1;

    if (!application.componentsInit())
        return -2;

    return application.run();
}
