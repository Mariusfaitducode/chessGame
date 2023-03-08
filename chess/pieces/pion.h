#ifndef PION_H
#define PION_H

#include <iostream>
#include <piece.h>
#include <enum.h>


class Pion : public Piece
{
public:
    Pion(TypePiece type, int x, int y, Color color);
    ~Pion();
    void Mouvement(int x, int y) override;
};

#endif // PION_H
