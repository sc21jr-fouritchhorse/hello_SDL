//
// Created by magami on 28/10/22.
//

#include "shaderProgram.h"

shaderProgram::shaderProgram(std::vector<shader*> myShaders) : shaders(myShaders)
{
    ID = glCreateProgram();
    for(shader *s : myShaders)
    {
        glAttachShader(s->getID(), ID);
    }
    glLinkProgram(ID);
}

shaderProgram::~shaderProgram()
{
    for(shader *s : shaders)
    {
        s->~shader();
    }
}