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
    void bind();
    void enableAccess();
private:
    std::vector<buffer_object> myBuffers;
    GLuint *ID;
    
};

#endif