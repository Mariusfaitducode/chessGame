#ifndef PLAYER_H
#define PLAYER_H


#include <piece.h>
#include <pieces\pion.h>
#include <enum.h>

#include <list>
#include <vector>
#include <ostream>


class Player
{
public:
    Player();
    ~Player();

    Piece* GetPiece(int i){return _pieces[i];}

private:
    //std::list<Piece*> _pieces;
    std::vector<Piece*> _pieces;
    Color _color;

};

#endif // PLAYER_H
