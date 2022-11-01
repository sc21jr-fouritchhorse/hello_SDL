#include "Pong.h"

int main(int argc, char** argv)
{
    Pong* game = new Pong();
    game->RunLoop();
    return 0;
}