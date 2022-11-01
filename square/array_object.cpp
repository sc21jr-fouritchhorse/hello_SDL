#include "array_object.h"

 array_object::array_object()
{
    vert_count = 0;
    element_count = 0;
    glGenVertexArrays(1, &ID);
}


void array_object::bind()
{
    glBindVertexArray(ID);
}

void array_object::unbind()
{
    glBindVertexArray(0);
}

void array_object::add_buffer(buffer_object* buffer)
{
    myBuffers.push_back(buffer);
    vert_count += buffer->getVertCount();
    element_count += buffer->getIndCount();
}

array_object::~array_object()
{
    for(buffer_object *b : myBuffers)
    {
        b->destroy();
    }
}

