#ifndef SCENE_H
#define SCENE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>



class Scene
{
public:
    Scene();
    void init();
    void drawScene();
    void update();

    double m_startTime;
    double m_elapsedTime;




};

#endif // SCENE_H
