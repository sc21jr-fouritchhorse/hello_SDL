#ifndef __BO_H__
#define __BO_H__

#include <vector>
#include <GL/glew.h>


class BufferObj 
{
private:
    const char* obj_filename;
    GLuint vbo_id;
    GLuint ebo_id;
    std::vector<GLuint> indices;
};

#endif //__BO_H__