//
// Created by magami on 28/10/22.
//

#ifndef SQUARE_SHADERPROGRAM_H
#define SQUARE_SHADERPROGRAM_H

#include "shader.h"
#include <vector>

class shaderProgram {
    shaderProgram(std::vector<shader*> myShaders);
    ~shaderProgram();
    GLuint getID() const { return ID; }
    GLuint *getID_pointer() { return &ID; }
private:
    std::vector<shader*> shaders;
    GLuint ID;
};


#endif //SQUARE_SHADERPROGRAM_H
