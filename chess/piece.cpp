#include "piece.h"


Piece::Piece(TypePiece type, int x, int y, Color color)
{
    _type = type;
    _x = x;
    _y = y;
    _color = color;
}

Piece::~Piece(){

}

