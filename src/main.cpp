#include <GL/glu.h>

#ifdef __linux__
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif



#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GLFunctions.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "scene.h"
#include "branch.h"
#include "lsystems.h"
#include "turtle.h"

// Includes needed for SDL an GL
#include <SDL2/SDL.h>

// THINGS TO DO
// get width and length to decrease based on depth
// grow tree eg draw 1 recursion at a time using timer or depth
// connect attributes eg length, angle etc to class
// allow alpabet and alphabet rule to be read from file
// DOXYGEN
// allow different files to be read from switch statements
// add leaves
// add textures (possibly for seasons)




int main()
{

    Scene *scene = NULL;

    Branch branch;

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
                                500,
                                400,
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

SDL_StartTextInput();

int iterations =3;

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
            case SDLK_ESCAPE : quit=true; break;
                // if 1 is pressed draw 1st tree type
            case SDLK_1 : lsystems.selectTree(1); break;
                // if 2 is pressed draw 2ns tree type
            case SDLK_2 : lsystems.selectTree(2); break;
                // if right pressed increase increments
            case SDLK_RIGHT : iterations+=1; break;
                // if left pressed decrease increments
            case SDLK_LEFT : iterations-=1; break;


            }
        }

        scene->drawScene();

        //lsystems.createLeaf();

        lsystems.setAxiom();
        lsystems.setAngle();
        lsystems.setRule();
        lsystems.setAlphabet();
        lsystems.setAlphabetRule();

         // number of iterations
         lsystems.productions(iterations);

         lsystems.getDrawingRule();

         // width and height
         turtle.Draw(lsystems,0.01,0.15);


         //branch->createBranch();


         //branch->drawRecurse(0,3);




       SDL_GL_SwapWindow( window);



    }

}


// Delete our scene
delete scene;

//Destroy window
SDL_DestroyWindow( window );

//Quit SDL subsystems
SDL_Quit();

return EXIT_SUCCESS;








}

