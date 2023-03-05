#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <piece.h>
#include <enum.h>


class Player
{
public:
    Player();


private:
    std::list<Piece> pieces;
    Color color;

};

#endif // PLAYER_H
