#ifndef ROI_H
#define ROI_H


#include <iostream>
#include <piece.h>
#include <enum.h>


class Roi : public Piece
{
public:
    Roi(int l, int c, Color color);
    ~Roi();
    std::vector<Vector2> Mouvement(Piece* plateau[8][8]) override;

    std::vector<Vector2> RockMouvement(Piece* plateau[8][8]) override;
    //bool CanRock() override;


};

#endif // ROI_H
