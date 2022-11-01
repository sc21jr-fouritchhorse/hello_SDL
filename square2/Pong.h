#pragma once
#ifndef __PONG_H__
#define __PONG_H__


#include "Game.h"

class Pong : public Game
{
public:
        Pong() : Game(640, 480) {};
    virtual void Initialize();
    virtual void MyInput();
    virtual void MyUpdate(float deltaTime);
    virtual void MyRender();
private:
    //Paddle player1
    //Paddle player2
    //Ball ball1
};


#endif //__PONG_H__