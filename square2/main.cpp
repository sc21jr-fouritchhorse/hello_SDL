#include "Game.h"

int main(int argc, char** argv)
{
    Game* game = new Game(640, 480);
    game->RunLoop();
    return 0;
}