#ifndef __buffer_object_H__
#define __buffer_object_H__

#include <string>
#include <vector>
#include <GL/glew.h>
class buffer_object
{
public:
    buffer_object(const char *filename);
    void readFile();
    void write_buffer_object(const char *filename);
    void bind();
    ~buffer_object();
    int getVertCount() const { return verts.size(); }
    int getIndCount () const { return indices.size(); }
private:
    const char* buffer_object_filename;
    GLuint vbo_ID;
    GLuint ebo_ID;
    std::vector<GLfloat*> verts;
    std::vector<GLuint*>  indices;
};

#endif