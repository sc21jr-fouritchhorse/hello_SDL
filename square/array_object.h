#ifndef __OBJ_H__
#define __OBJ_H__

#include <string>
#include <vector>
#include <GL/glew.h>

#include "buffer_objects.h"

class array_object
{
public:
    array_object();
    ~array_object();
    void add_buffer(buffer_object);
    void bind();
    void enableAccess();
    GLuint getID() const { return ID; }
private:
    std::vector<buffer_object> myBuffers;
    GLuint ID;
    GLint loc_position;
};

#endif