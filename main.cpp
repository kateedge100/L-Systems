#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

// Includes needed for SDL and GL
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>




int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    //The window we'll be rendering to
    SDL_Window* gWindow;

    //OpenGL context
    SDL_GLContext gContext;

    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );


    //Create window
    gWindow = SDL_CreateWindow( "L-Systems",
                                200,
                                100,
                                640,
                                480,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    //Create context
    gContext = SDL_GL_CreateContext( gWindow );





    // Set the background colour
    glClearColor(0.1f, 0.1f, 1.0f, 1.0f);
    glViewport(0,0,600,400);


    // Clear the display buffer
glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}
