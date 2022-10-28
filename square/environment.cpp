#include "environment.h"

void environment::render(SDL_Window *win)
{
    while(!shouldTerminate)
    {
        default_input();
        for(array_object *ao : vaos)
        {
            ao->bind();
            for(buffer_object *b : ao->getBuffers())
            {
                b->render(ao);
            }
        }
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
    for(array_object *a :vaos)
    {
        a->unbind();
        glDeleteVertexArrays(1, a->pointer_getID());
        delete a;
    }
}