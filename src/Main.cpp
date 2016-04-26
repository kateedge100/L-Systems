

#ifdef __linux__
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "GL/glu.h"
#include "Scene.h"
#include "Lsystems.h"
#include "Turtle.h"

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600

// Includes needed for SDL an GL
#include <SDL2/SDL.h>

// THINGS TO DO
// correct lighting
// DOXYGEN
// add leaves
// add textures (possibly for seasons)


Uint32 UpdateIteration(Uint32 _interval, void * _param)
{

  LSystems *lsystems =(LSystems*)_param;
  if(lsystems != nullptr && lsystems->m_iterations < lsystems->m_maxIterations)
  {
    lsystems->m_iterations+=1;
  }
    return _interval;
}

int main()
{

  Scene *scene = NULL;
  LSystems lsystems;
  Turtle turtle;
  SDL_Window*window = NULL;
  SDL_GLContext Context;

  //Use OpenGL 3.1 core
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

  window = SDL_CreateWindow( "L-Systems",
                                200,
                                100,
                                WINDOWWIDTH,
                                WINDOWHEIGHT,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if( window == NULL )
  {
    printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    return EXIT_FAILURE;
  }
  Context = SDL_GL_CreateContext( window );

  scene = new Scene();

  scene->init();


  bool quit = false;

  SDL_Event event;
  SDL_TimerID Update = SDL_AddTimer(500,UpdateIteration,&lsystems);

  while(quit!=true)
  {
    while( SDL_PollEvent(&event) != 0)
    {
      if(event.type == SDL_QUIT)
      {
        quit=true;
      }
      //If esc pressed exit window
      if(event.type == SDL_KEYDOWN)
      {
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
          {
            quit=true; break;
          }

          // if 1 is pressed draw 1st tree type
          case SDLK_1:
          {
            lsystems.selectTree(1);lsystems.m_iterations=0; break;
          }

          // if 2 is pressed draw 2ns tree type
          case SDLK_2:
          {
            lsystems.selectTree(2); lsystems.m_iterations=0 ; break;
          }

          // press up to increase angle
          case SDLK_UP:
          {
            turtle.m_angle+=5; break;
          }

          // press down to decrease angle
          case SDLK_DOWN:
          {
            turtle.m_angle -=5; break;
          }

          // if right pressed increase max increments (max growth)
          case SDLK_RIGHT:
          {
            lsystems.m_maxIterations+=1; lsystems.m_iterations=0; break;
          }

          // if left pressed decrease max increments (min graowth)
          case SDLK_LEFT:
          {
            lsystems.m_maxIterations-=1; lsystems.m_iterations=0; break;
          }

          default:
          {
            break;
          }
        }
      }
    }

    scene->drawScene();

    //lsystems.createLeaf();
    lsystems.setAxiom();
    lsystems.setRule();
    lsystems.setAlphabet();
    lsystems.setAlphabetRule();
    turtle.setAngle(turtle.m_angle);


    // number of iterations
    lsystems.productions(lsystems.m_iterations);
    lsystems.getDrawingRule();

    // width and height. width increases with each iteration
    turtle.Draw(lsystems,lsystems.m_iterations*0.008,0.20);

    SDL_GL_SwapWindow( window);
  }

  // Delete our scene
  delete scene;

  //Destroy window
  SDL_DestroyWindow( window );

  // Disable our timer
  SDL_RemoveTimer(Update);

  //Quit SDL subsystems
  SDL_Quit();

  return EXIT_SUCCESS;
}

