#include "array_object.h"

 array_object::array_object()
{
    vert_count = 0;
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

    for(buffer_object *b : myBuffers)
    {
        vert_count += b->getVertCount();
    }
}

array_object::~array_object()
{
    for(buffer_object *b : myBuffers)
    {
        b->unbind();
        b->destroy();
    }
}

