#ifndef FOU_H
#define FOU_H


#include <iostream>
#include <piece.h>
#include <enum.h>


class Fou : public Piece
{
public:
    Fou(int l, int c, Color color);
    ~Fou();
    void Mouvement(int x, int y) override;
};

#endif // FOU_H
