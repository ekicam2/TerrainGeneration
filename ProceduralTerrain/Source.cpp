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
    3 for now just rotate and move plane [X]
4 make perlin noise algorithm [X]
    1 code perlin noise algorith [X]
    2 draw it to a texture [X]
    3 read from the texture [X]
    4 make terrain "noisy" while creating [X]
5 I/O menagment [X]
    1 just make scene class and let it swallow all inputs and process em [X]
6 Water plane [ ]
    1 make flat plane [ ]
    2 shaders, shaders, shaders [ ]
    3 debug [ ]
7 Fog
    1 has to read about it, on nvidia site is pretty cool article about fog and fog math
8 Lighting
    1 dynamic lighting
    2 depending on config or something (has to be reinvented)
    3 prepare shaders to receive light sources
    4 compute it and make it works
9 Shadows
    1 pick one solution shadow maps or self shadowing with shadow contact
    2 depending on choice read about and code!
10 UnderWater (post processing?)
    1 calculate where the camera is above, under or in middle
    2 compute it a bit
    3 shaders, shaders
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
