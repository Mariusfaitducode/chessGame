#ifndef PIECE_H
#define PIECE_H

#include <enum.h>
#include <vector>

class Piece
{
public:
    //Piece() = delete;
    Piece(TypePiece type, int x, int y, Color color);

    virtual ~Piece();
    virtual void Mouvement(int x, int y) = 0;


private:
    //Vector2 _position;

    //vector position();
    int _x, _y;

    Color _color;
    StatuPiece _statu;

    TypePiece _type;
    char _letter;
};

#endif // PIECE_H
