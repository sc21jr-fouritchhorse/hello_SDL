#pragma once
#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <iostream>
#include <string.h>

namespace ErrorReturn 
{
    enum className {GAME, SURFACE, BUFFER_OBJECT, ARRAY_OBJECT};
    enum errorCode { SUCCESS=0, SDL_INIT_FAILED=1, WINDOW_CREATION_FAILED=2,
    CONTEXT_CREATION_FAILED=3, GL_INIT_FAILED=4};
    int printMsg(errorCode code, className caller,
                 const char *filename, const char *miscMessage);
}

#endif