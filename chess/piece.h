#ifndef PIECE_H
#define PIECE_H

#include <enum.h>
#include <vector>
#include <iostream>


#include <QGraphicsPixmapItem>


class Vector2
{
public:
    Vector2() = default;
    Vector2(int c, int l){ this->c = c; this->l = l;}

    //~Vector2();

public:

    int c;
    int l;
};


class Piece
{
public:
    //Piece() = delete;
    //Piece(TypePiece type, int l, int c, Color color);

    Piece(Vector2 pos, Color color);

    QPixmap GetImage(){return _image;}
    Vector2 GetPos(){return _pos;}
    Color GetColor(){return _color;}

    int L(){return _pos.l;}
    int C(){return _pos.c;}

    void ShowPiece();

    virtual ~Piece();
    virtual std::vector<Vector2> Mouvement(Piece* plateau[8][8]) = 0;

protected:
    void NextCases(Vector2 v1, Vector2 v2, std::vector<Vector2>* coups, Piece* plateau[8][8]);
    bool IsOnBoard(Vector2 v);

protected:

    Vector2 _pos;
    //int _l, _c;

    Color _color;
    StatuPiece _statu;

    TypePiece _type;
    QPixmap _image;
};

#endif // PIECE_H
