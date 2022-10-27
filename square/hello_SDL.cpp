#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#include "gl_context.h"
#include "environment.h"
#include "buffer_objects.h"

int main(int argc, char** argv)
{
    gl_context my_context(640, 480, 4, 5);
    environment my_render_loop;
    if(!my_context.isValid())
    {
        printf("Failed to create context!\n");
        return -1;
    }
    buffer_object my_object("square.obj");
    my_render_loop.render(my_context.getWindow());
    return 0;
}  