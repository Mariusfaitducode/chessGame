#include "pion.h"

Pion::Pion(TypePiece type, int x, int y, Color color) : Piece(type, x, y, color)
{

}

Pion::~Pion(){

}

void Pion:: Mouvement(int x, int y){
    std::cout << "Mouvement pion" << std::endl;
}
