#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Transform.h"

class Actor
{
public:
    Actor();
protected:
//TODO, implement this as a generic component
    Transform_2 gamePos();   
};

#endif