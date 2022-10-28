//
// Created by magami on 28/10/22.
//

#include "shader.h"

shader::shader(const char *myDir = NULL, GLenum myType = GL_NONE) :
filename(myDir), type(myType)
{
    ID = glCreateShader(type);
    FILE *srcFile = fopen(filename, "rb");
    if(!srcFile)
    {
        printf("Error: invalid filename\n");
        return;
    }
    else
    {
        fseek(srcFile, 0, SEEK_END);
        long size = ftell(srcFile);
        rewind(srcFile);
        source = (char*) malloc(sizeof(char) * size);
        fread(source, 1, size, srcFile);
        glShaderSource(ID, 1, &source, NULL);
        printf("\n%s\n", source);

        glCompileShader(ID);
    }
}


shader::~shader()
{
    glDeleteShader(ID);
    delete [] source;
    delete [] filename;
}