#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#include "gl_context.h"
#include "environment.h"
#include "buffer_objects.h"
#include "array_object.h"
#include "shader.h"
#include "shaderProgram.h"

int main(int argc, char** argv)
{
    gl_context my_context(640, 480, 4, 5);
    environment my_render_loop;
    if(!my_context.isValid())
    {
        printf("Failed to create context!\n");
        return -1;
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    array_object* my_array = new array_object();
    my_array->bind();
    my_render_loop.set_vao(my_array);
    buffer_object* my_object = new buffer_object("square.obj");
    std::vector<shader*> myShaders;
    myShaders.push_back(new shader("square_vert.glsl", GL_VERTEX_SHADER));
    myShaders.push_back(new shader("square_frag.glsl", GL_FRAGMENT_SHADER));
    my_object->my_shader = new shaderProgram(myShaders);
    my_array->add_buffer(my_object);
    my_render_loop.render(my_context.getWindow());
    return 0;
}  