#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAJ_VER 4
#define MIN_VER 5


int main(int argc, char** argv)
{
    SDL_Window* window = NULL;

    SDL_GLContext context;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("Couldn't init video: %s\n", SDL_GetError());
    else 
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJ_VER);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MIN_VER);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            
        if ((window = SDL_CreateWindow(
            "Hello SDL", 
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) == NULL)
            printf("Couldn't create window: %s\n", SDL_GetError());
        else 
        {
            if((context = SDL_GL_CreateContext(window)) == NULL)
                printf("Couldn't make GL context: %s\n", SDL_GetError());
            else
            {
                glewExperimental = GL_TRUE;
                if(glewInit() != GLEW_OK) 
                   printf("Couldn't init GLEW\n");
                {
                    SDL_Event winEvent;
                    while(winEvent.type != SDL_QUIT)
                    {
                        SDL_PollEvent(&winEvent);
                        SDL_GL_SwapWindow(window);
                    }
                }
            }
        }
        
        SDL_GL_DeleteContext(context);
        SDL_Quit();
        return 0;
    }
    return -1;

}  