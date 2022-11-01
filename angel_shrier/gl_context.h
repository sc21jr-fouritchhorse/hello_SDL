#ifndef __GL_CONTEXT_H__
#define __GL_CONTEXT_H__
#include <GL/glew.h>
#include <SDL2/SDL.h>

class gl_context
{
public:
    gl_context() {}
    gl_context(int, int, int, int);
    ~gl_context();
    SDL_Window *getWindow() const { return window; }
    SDL_GLContext getContext() const { return context; }
    int getWidth() const { return scr_width; }
    int getHeight() const { return scr_height; }
    bool isValid() const { return !isFaulty; }
private:
    int scr_width;
    int scr_height;
    int gl_maj_ver;
    int gl_min_ver;
    bool isFaulty;
    SDL_Window *window;
    SDL_GLContext context;
};

#endif //__GL_CONTEXT__