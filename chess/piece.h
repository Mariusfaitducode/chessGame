#ifndef PIECE_H
#define PIECE_H

#include <enum.h>
#include <vector>

class Piece
{
public:
    //Piece() = delete;
    //Piece(TypePiece type, int l, int c, Color color);

    Piece(int l, int c, Color color);

    virtual ~Piece();
    virtual void Mouvement(int x, int y) = 0;


protected:
    //Vector2 _position;

    //vector position();
    int _l, _c;

    Color _color;
    StatuPiece _statu;

    TypePiece _type;
    char _letter;
};

#endif // PIECE_H
