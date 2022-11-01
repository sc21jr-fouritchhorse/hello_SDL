#include "Pong.h"
#include <iostream>
#include <math.h>

void Pong::Initialize()
{
    glClearColor(0.0f, 0.2f, 0.5f, 1.0f);
}

void Pong::MyInput()
{
    if(myEvent.type == SDL_KEYUP) {
       if (myEvent.key.keysym.sym == SDLK_w)
            std::cout << "W key pressed!" << std::endl;
    }
}

void Pong::MyUpdate(float dt)
{
    std::cout << "Delta time =" << dt << '\r';
    glClearColor(std::sin(tickCount * dt), std::cos(tickCount * dt), 1.0f / std::cos(tickCount * dt), 1.0f);
}

void Pong::MyRender()
{

}