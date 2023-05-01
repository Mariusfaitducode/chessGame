#ifndef TOUR_H
#define TOUR_H


#include <iostream>
#include <piece.h>
#include <enum.h>


class Tour : public Piece
{
public:
    Tour(int l, int c, Color color);
    ~Tour();
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;

    std::vector<Vector2> RockMouvement(Piece* plateau[8][8]) override{
        std::vector<Vector2> coups;
        return coups;
    };
};


#endif // TOUR_H
