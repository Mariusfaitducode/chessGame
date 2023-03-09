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
    void Mouvement(int x, int y) override;
};

#endif // ROI_H
