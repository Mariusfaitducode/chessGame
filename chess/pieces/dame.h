#ifndef DAME_H
#define DAME_H


#include <iostream>
#include <piece.h>
#include <enum.h>

#include <pieces\tour.h>
#include <pieces\fou.h>


class Dame : public Piece
{
public:
    Dame(int l, int c, Color color);
    ~Dame();
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;
};

#endif // DAME_H
