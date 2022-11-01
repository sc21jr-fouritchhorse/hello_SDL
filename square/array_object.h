#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__

#include <string>
#include <vector>
#include <GL/glew.h>

#include "buffer_objects.h"
#include "shaderProgram.h"

class array_object
{
public:
    array_object();
    ~array_object();
    void add_buffer(buffer_object*);
    void bind();
    void unbind();
    void render();
    void enableAccess();
    GLuint getID() const { return ID; }
    GLuint* pointer_getID() { return &ID; }
    GLuint getVertCount() const { return vert_count; }
    std::vector<buffer_object*> getBuffers() const { return myBuffers; } 
private:
    std::vector<buffer_object*> myBuffers;
    GLuint vert_count;
    GLuint element_count;
    GLuint ID;
    GLint loc_position;
};

#endif