#ifndef PIECE_H
#define PIECE_H

#include <vector2.h>
#include <enum.h>


class Piece
{
public:
    Piece() = delete;
    Piece(TypePiece type, int x, int y, Color _color);


private:
    Vector2 _position;
    Color _color;
    StatuPiece _statu;

    TypePiece _type;
    char _letter;
};

#endif // PIECE_H
