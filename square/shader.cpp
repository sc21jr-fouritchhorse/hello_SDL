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
        fclose(srcFile);
        printf("Error: invalid filename\n");
        return;
    }
    else
    {
        fseek(srcFile, 0, SEEK_END);
        int size = ftell(srcFile);
        fseek(srcFile, 0, SEEK_SET);
        source =  new char[size + 1];
        fread(source,  1, size, srcFile);
        fclose(srcFile);
        const char* mySrc = const_cast<const GLchar*>(source);
        glShaderSource(ID, 1, &mySrc, (const GLint*) &size);
        source[size] = '\0';
        printf("\n%s\n", source);
        glCompileShader(ID);
        glGetShaderInfoLog(ID, 512, NULL, infoLog);
        printf("%s\n", infoLog);
    }
}


shader::~shader()
{
    delete [] source;
    glDeleteShader(ID);
}