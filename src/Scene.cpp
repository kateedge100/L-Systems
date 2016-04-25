#include "Scene.h"
#include <sys/time.h>

Scene::Scene()
{

}

void Scene::init()
{
  // Enable texturing
  glDisable(GL_TEXTURE_2D);

  // Enable counter clockwise face ordering
  glFrontFace(GL_CCW);

  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);

  // Lighting borrowed from Jon Macey
  glEnable(GL_LIGHT0);
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  GLfloat lightpos[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat lightdiff[] = {0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat lightamb[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat lightspec[] = {1.0f, 1.0f, 1.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightamb);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);

  // Make our points lovely and smooth
  glEnable( GL_POINT_SMOOTH );
  glEnable( GL_MULTISAMPLE_ARB);
  glEnable(GL_DEPTH_TEST);

}

void Scene::drawScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, -1.0f, -1.0f);
}



