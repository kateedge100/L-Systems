#ifndef SCENE_H
#define SCENE_H

#include "GL/gl.h"
#include "GL/glu.h"
#include <stdlib.h>

/// \author Kate Edge
/// \version 1.0
/// \date 26/4/2016
/// \class Scene
/// \brief Initilises the scene and prepares for drawing

class Scene
{
public:
    Scene();
    void init();
    void drawScene();
};

#endif // SCENE_H
