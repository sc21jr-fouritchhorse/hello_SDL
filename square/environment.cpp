#include "environment.h"

void environment::render(SDL_Window *win)
{
    while(!shouldTerminate)
    {
        default_input();
        for(GLuint ao : vaos)
        {
            glBindVertexArray(ao);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        SDL_GL_SwapWindow(win);
    }
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

