#ifndef DAME_H
#define DAME_H


#include <iostream>
#include <piece.h>
#include <enum.h>


class Dame : public Piece
{
public:
    Dame(int l, int c, Color color);
    ~Dame();
    void Mouvement(int x, int y) override;
};

#endif // DAME_H
