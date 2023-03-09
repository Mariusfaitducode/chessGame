#include "pion.h"

Pion::Pion(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::pion;
}

Pion::~Pion(){

}

void Pion:: Mouvement(int l, int c){
    std::cout << "Mouvement pion" << std::endl;
}
