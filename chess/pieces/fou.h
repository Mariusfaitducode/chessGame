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
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;
};

#endif // FOU_H
