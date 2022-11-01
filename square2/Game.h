#pragma once
#ifndef __GAME_H__
#define __GAME_H__


#include <SDL2/SDL.h>
#include "RenderSurface.h"

class Game
{
public:
    Game(int, int);
    ~Game();
    virtual void Initialize() {}
    void RunLoop();
    void Shutdown();
protected:
    void ProcessInput();
    virtual void MyInput() {}
    void Update();
    virtual void MyUpdate(float deltaTime) {}
    void Render();
    virtual void MyRender() {}
    RenderSurface* mySurface;
    bool mIsRunning;
    SDL_Event myEvent;
    float tickCount;
private:
    const float deltaDenominator = 10000.0f;
    const float deltaClamp = 0.05f;
    const uint frameTime = 32;
};

#endif