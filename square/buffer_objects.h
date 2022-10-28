#pragma once
#ifndef __buffer_object_H__
#define __buffer_object_H__

#include <string>
#include <vector>
#include <GL/glew.h>

#include "shaderProgram.h"


class array_object;
class buffer_object
{
public:
    buffer_object(const char *filename);
    ~buffer_object();
    void readFile();
    void write_buffer_object(const char *filename);
    void bind();
    void unbind();
    void render(array_object* vao);
    void destroy();
    int getVertCount() const { return verts.size(); }
    int getIndCount () const { return indices.size(); }
    shaderProgram *my_shader;
private:
    const char* buffer_object_filename;
    GLuint vbo_ID;
    GLuint ebo_ID;
    std::vector<GLfloat*> verts;
    std::vector<GLuint> indices;
    bool destroyed;
};

#endif