#ifndef PLAYER_H
#define PLAYER_H


#include <piece.h>
#include <pieces\pion.h>
#include <pieces\cavalier.h>
#include <pieces\fou.h>
#include <pieces\tour.h>
#include <pieces\dame.h>
#include <pieces\roi.h>
#include <enum.h>

#include <list>
#include <vector>
#include <ostream>


class Coup{

public:
    Coup(Vector2 pos, QGraphicsEllipseItem *ellipse){
        _pos = pos;
        _ellipse = ellipse;
    }

    //QGraphicsEllipseItem getEllipse(){return *_ellipse;}

    //~Coup();
    QGraphicsEllipseItem *_ellipse;
    Vector2 _pos;


};


class Player
{
public:
    Player();
    Player(Color color);
    ~Player();

    Player & operator = (const Player &p);

    std::vector<Piece*> GetPieces(){return _pieces;}
    Piece* GetPiece(int i){return _pieces[i];}

    void ShowPieces();



private:
    //std::list<Piece*> _pieces;
    std::vector<Piece*> _pieces;
    Color _color;



};

#endif // PLAYER_H
