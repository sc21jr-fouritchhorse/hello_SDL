//
// Created by magami on 28/10/22.
//

#include "shaderProgram.h"

shaderProgram::shaderProgram(std::vector<shader*> myShaders) : shaders(myShaders)
{
    ID = glCreateProgram();
    for(shader *s : myShaders)
    {
        glAttachShader(ID, s->getID());
        s->~shader();
    }
    glLinkProgram(ID);
    glGetProgramInfoLog(ID, 512, NULL, infoLog);
    printf("%s\n", infoLog);
}



shaderProgram::~shaderProgram()
{
    glDeleteProgram(ID);
}