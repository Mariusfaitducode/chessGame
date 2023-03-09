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
    void Mouvement(int x, int y) override;
};


#endif // TOUR_H
