#include "RenderSurface.h"

RenderSurface::RenderSurface(int w=640, int h=480) : scr_width(w), scr_height(h)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ErrorReturn::printMsg(ErrorReturn::SDL_INIT_FAILED, 
        ErrorReturn::SURFACE, "", SDL_GetError());     
    }
    else 
    {
        window = SDL_CreateWindow(windowTitle, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        scr_width, scr_height, SDL_WINDOW_OPENGL);
        if(!window)
        {
            ErrorReturn::printMsg(ErrorReturn::WINDOW_CREATION_FAILED, 
            ErrorReturn::SURFACE, "", SDL_GetError());
        }
        else
        {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, profile);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major_ver);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor_ver);
            SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, stencil);
            context = SDL_GL_CreateContext(window);
            if(!context)
            {
                ErrorReturn::printMsg(ErrorReturn::CONTEXT_CREATION_FAILED, 
                ErrorReturn::SURFACE, "", SDL_GetError());
            }
            else
            {
                glewExperimental = GL_TRUE;
                if(glewInit() != GLEW_OK)
                {
                    ErrorReturn::printMsg(ErrorReturn::GL_INIT_FAILED,
                                          ErrorReturn::SURFACE, "", "");
                }
                else
                {
                    ErrorReturn::printMsg(ErrorReturn::SUCCESS,
                                          ErrorReturn::SURFACE, "", "");
                }
            }
        }
    }   

}

RenderSurface::~RenderSurface()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}