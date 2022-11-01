#include "Game.h"

Game::Game(int width=640, int height=480)
{
    mIsRunning = true;
    mySurface = new RenderSurface(width, height);
}


void Game::Render()
{
    MyRender();
    SDL_GL_SwapWindow(mySurface->getWindow());
}

void Game::ProcessInput()
{
    SDL_PollEvent(&myEvent);
    if(myEvent.type == SDL_QUIT)
        mIsRunning = false;
    MyInput();
}

void Game::Update()
{
    MyUpdate();
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


