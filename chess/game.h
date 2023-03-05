#ifndef GAME_H
#define GAME_H

#include <player.h>


class Game
{
public:
    Game();


private:
    Player blanc;
    Player noir;

    char plateau[8][8];
};

#endif // GAME_H
