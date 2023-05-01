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
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;

    std::vector<Vector2> RockMouvement(Piece* plateau[8][8]) override{
        std::vector<Vector2> coups;
        return coups;
    };
};

#endif // CAVALIER_H
