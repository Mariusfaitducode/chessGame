#ifndef PIECE_H
#define PIECE_H

#include <enum.h>
#include <vector>

#include <QGraphicsPixmapItem>

class Piece
{
public:
    //Piece() = delete;
    //Piece(TypePiece type, int l, int c, Color color);

    Piece(int l, int c, Color color);

    QPixmap GetImage(){return _image;}
    int L(){return _l;}
    int C(){return _c;}

    virtual ~Piece();
    virtual void Mouvement(int x, int y) = 0;


protected:
    //Vector2 _position;

    //vector position();
    int _l, _c;

    Color _color;
    StatuPiece _statu;

    TypePiece _type;
    QPixmap _image;
};

#endif // PIECE_H
