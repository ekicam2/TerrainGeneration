#include <glm\glm.hpp>

#include "App.h"
/*
TODO:
1 make a triangle and draw at the screen [ ]
    1 make 3 vertices [ ]
    2 make vertex shader [ ]
    3 make fragment shader [ ]
    4 compile shaders [ ]
    5 draw it on the screen [ ]
2 make perlin noise algorithm [ ]
    1 code perlin noise algorith [ ]
    2 draw it to a texture [ ]
    3 read from the texture [ ]
3 make a triangle strip and draw at the screen [ ]

*/

int main()
{
    App application;
    if (application.init(glm::vec2(1024, 768), "Triangle yai"))
        return -1;
    application.debugInit();

    return application.run();
}
