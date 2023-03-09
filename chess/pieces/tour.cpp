#include "tour.h"


Tour::Tour(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::tour;
}

Tour::~Tour(){

}

void Tour:: Mouvement(int l, int c){
    std::cout << "Mouvement tour" << std::endl;
}
