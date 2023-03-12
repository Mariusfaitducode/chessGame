#ifndef PION_H
#define PION_H

#include <iostream>
#include <piece.h>
#include <enum.h>


class Pion : public Piece
{
public:
    Pion(int l, int c, Color color);
    ~Pion();
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;
};

#endif // PION_H
