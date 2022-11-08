#include "Errors.h"


int ErrorReturn::printMsg(ErrorReturn::errorCode myCode, ErrorReturn::className caller,
                          const char *filename = "", const char *miscMessage = "")
{
    switch(caller)
    {
        case SURFACE:
            std::cout << "RenderSurface: ";
        break;
        case GAME:
            std::cout << "Game: ";
        break;
    }
    switch(myCode)
    {
        case 0:
        switch (caller)
        {
        case SURFACE:
            std::cout << "Render surface created!";
            break;
        default:
            break;
        }
        break;
        case SDL_INIT_FAILED:
            std::cerr << "Failed to initalize SDL";
        break;
        case WINDOW_CREATION_FAILED:
            std::cerr << "Failed to initalize window";
        break;
        case CONTEXT_CREATION_FAILED:
            std::cerr << "Failed to create OpenGL context";
        break;
        case GL_INIT_FAILED:
            std::cerr << "Failed to init GL/GLEW";
        break;
        default:
            std::cerr << "Miscellaneous error, see log";
        break;
    }
    if(strcmp(filename, ""))
        std::cerr << "(" << filename << ")";
    if(myCode)
        std::cerr << ": ";
    if(strcmp(miscMessage, ""))
        std::cerr << miscMessage;

    std::cout << std::endl;

    return myCode;
}