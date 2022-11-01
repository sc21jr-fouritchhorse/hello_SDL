#include "Game.h"

Game::Game(int width=640, int height=480)
{
    mIsRunning = true;
    mySurface = new RenderSurface(width, height);
    Initialize();
}


void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    MyRender();
    SDL_GL_SwapWindow(mySurface->getWindow());
}

void Game::ProcessInput()
{
    SDL_PollEvent(&myEvent);
    if(myEvent.type == SDL_QUIT || 
    (myEvent.type == SDL_KEYUP && myEvent.key.keysym.sym == SDLK_ESCAPE))
        mIsRunning = false;
    MyInput();
}

void Game::Update()
{

    while(!SDL_TICKS_PASSED(SDL_GetTicks(), tickCount + frameTime));

    float deltaTime = (SDL_GetTicks() - tickCount) / deltaDenominator;
    

    if(deltaTime > deltaClamp)
    {
        deltaTime = deltaClamp;
    }

    tickCount = SDL_GetTicks();

    MyUpdate(deltaTime);
}

void Game::RunLoop()
{
    while(mIsRunning) {
        ProcessInput();
        Update();
        Render();
    }
}

Game::~Game()
{
    mySurface->~RenderSurface();
}


