#pragma once
#ifndef __GAME_H__
#define __GAME_H__


#include <SDL2/SDL.h>
#include "RenderSurface.h"
#include "Actor.h"

class Game
{
public:
    Game(int, int);
    ~Game();
    void RunLoop();
    void Shutdown();
protected:
    void ProcessInput();
    void Update();
    void Render();
    RenderSurface* mySurface;
    std::vector<Actor*> myActors;
    bool mIsRunning;
    SDL_Event myEvent;
    float tickCount;
private:
    const float deltaDenominator = 10000.0f;
    const float deltaClamp = 0.05f;
    const uint frameTime = 32;

    //Entity component model
    //TODO: Entity class 
    //Vectors or tree, implement vectors for iteration 1
    //Entities may have child entities
    //Entitys are composed of a vector of of components (no hieracrchy for components)
    //For future project: try an ECS (look up, Toby's slides)
};

#endif