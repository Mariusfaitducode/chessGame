#ifndef CAVALIER_H
#define CAVALIER_H

#include <iostream>
#include <piece.h>
#include <enum.h>


class Cavalier : public Piece
{
public:
    Cavalier(int l, int c, Color color);
    ~Cavalier();
    void Mouvement(int x, int y) override;
};

#endif // CAVALIER_H
