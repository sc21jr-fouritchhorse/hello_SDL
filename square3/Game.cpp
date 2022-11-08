#include "Game.h"

Game::Game(int width=640, int height=480)
{
    mIsRunning = true;
    mySurface = new RenderSurface(width, height);

    for(Actor *a : myActors)
        for(Component *c : a->components)
            c->Init();
}


void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(mySurface->getWindow());

    for(Actor *a : myActors)
        for(Component *c : a->components)
            c->Draw();
}

void Game::ProcessInput()
{
    SDL_PollEvent(&myEvent);
    if(myEvent.type == SDL_QUIT || 
    (myEvent.type == SDL_KEYUP && myEvent.key.keysym.sym == SDLK_ESCAPE))
        mIsRunning = false;

    for(Actor *a : myActors)
        for(Component *c : a->components)
            c->GetInput();
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

    //Iterate through the entities
    for(Actor *a : myActors)
        //Iterate through the components of each entity
        for(Component *c : a->components)
            c->Update();
            //We only care about super classes: i.e. what the entity is etc doesn't matter
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

    for(Actor *a : myActors)
        for(Component *c : a->components)
            c->Destroy();
            
    mySurface->~RenderSurface();

}


