#include "array_object.h"

 array_object::array_object()
{
    glGenVertexArrays(1, &ID);
}

void array_object::bind()
{
    glBindVertexArray(ID);
}

array_object::~array_object()
{
    glDeleteVertexArrays(1, &ID);
}

void array_object::add_buffer(buffer_object buffer)
{
    myBuffers.push_back(buffer);
}

