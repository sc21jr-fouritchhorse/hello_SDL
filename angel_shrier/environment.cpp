#include "environment.h"

void environment::render(SDL_Window *win)
{
    while(!shouldTerminate)
    {
        default_input();
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(win);
    }
    glBindVertexArray(0);
}

void environment::default_input()
{
    SDL_PollEvent(&input);
    switch(input.type)
    {
        case SDL_QUIT:
            shouldTerminate = true;
        break;
    }
}

void environment::set_input(SDL_Event my_event)
{
    input = my_event;
}

environment::~environment()
{

}