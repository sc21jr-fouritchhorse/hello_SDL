#ifndef __GL_ENVIRONMENT_H__
#define __GL_ENVIRONMENT_H__
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>
#include "gl_context.h"

class environment 
{
public:
    void render(SDL_Window *);
    void set_input(SDL_Event);
    void set_vao(GLuint ao) { vaos.push_back(ao); }
private:
    void default_input();
    SDL_Event input;
    bool shouldTerminate;
    std::vector<GLuint> vaos;
};

#endif
