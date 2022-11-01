#pragma once
#ifndef __RENDER_CONTEXT_H__
#define __RENDER_CONTEXT_H__

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Errors.h"

class RenderSurface
{
public:
    RenderSurface(int, int);
    ~RenderSurface();
    SDL_Window *getWindow() const { return window; }
    SDL_GLContext getContext() const { return context; }
    int getWidth() const { return scr_width; }
    int getHeight() const { return scr_height; }
    void setWindowSize(int w, int h);
private:
    int scr_width;
    int scr_height;
    const int profile = SDL_GL_CONTEXT_PROFILE_CORE;
    const int stencil = 8;
    const int major_ver = 4;
    const int minor_ver = 5;
    const char *windowTitle = "Hello Polygons II";
    SDL_Window *window;
    SDL_GLContext context;
};

#endif //__RENDER_CONTEXT_H__