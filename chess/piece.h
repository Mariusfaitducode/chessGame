#ifndef PIECE_H
#define PIECE_H

#include <enum.h>
#include <vector>
#include <iostream>


#include <QGraphicsPixmapItem>

const int BOARD_SIZE = 8;



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
    void SetItem(QGraphicsPixmapItem *item){_item = item;}
    QGraphicsPixmapItem *GetItem(){return _item;}

    Vector2 GetPos(){return _pos;}
    Color GetColor(){return _color;}
    TypePiece GetType(){return _type;}

    int L(){return _pos.l;}
    int C(){return _pos.c;}

    void SetPos(int c, int l);

    void ShowPiece();

    std::string ShowSign();


    virtual ~Piece();
    virtual std::vector<Vector2> Mouvement(Piece* plateau[8][8]) = 0;

    //virtual bool CanRock(){return false;}

    bool can_rock = false;
    virtual std::vector<Vector2> RockMouvement(Piece* plateau[8][8]) = 0;

    bool IsThreatened(Vector2 pos, Piece* plateau[8][8]);



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
    QGraphicsPixmapItem *_item;

};

#endif // PIECE_H
