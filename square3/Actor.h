#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <vector>
#include "Component.h"

class Actor
{
public:
    std::vector<Component*> components;
};

#endif