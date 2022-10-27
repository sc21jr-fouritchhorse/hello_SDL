#include "gl_context.h"

gl_context::gl_context(int w, int h, int maj, int min) : 
                scr_width(w), scr_height(h),
                gl_maj_ver(maj), gl_min_ver(min)
{

    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        printf("Couldn't init video: %s\n", SDL_GetError());
        isFaulty = true;
    }
    
    else 
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_maj_ver);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_min_ver);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            
        if ((window = SDL_CreateWindow(
            "Hello SDL", 
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 
            scr_width, scr_height, 
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) == NULL) {
            printf("Couldn't create window: %s\n", SDL_GetError());
            isFaulty = true;
        }    
       else 
        {
            if((context = SDL_GL_CreateContext(window)) == NULL)
                printf("Couldn't make GL context: %s\n", SDL_GetError());
            isFaulty = true;
        }
    }

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
        printf("Couldn't init GLEW\n");
        isFaulty = true;
    }

    isFaulty = false;

} 

gl_context::~gl_context()
{

    SDL_GL_DeleteContext(context);
    SDL_Quit();
}