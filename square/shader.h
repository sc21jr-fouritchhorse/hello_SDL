//
// Created by magami on 28/10/22.
//

#ifndef SQUARE_SHADER_H
#define SQUARE_SHADER_H


#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class shader {
public:
    shader(const char *filename, GLenum type);
    ~shader();
    GLuint getID() const { return ID; }
    GLuint* pointer_getID() { return &ID; }
    const char* get_filename() const { return filename; }
private:
    void readFile();
    const char* filename;
    GLenum type;
    GLuint ID;
    char infoLog[512];
    char* source;
};


#endif //SQUARE_SHADER_H
