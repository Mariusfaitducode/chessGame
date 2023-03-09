#include "fou.h"

Fou::Fou(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::fou;
}

Fou::~Fou(){

}

void Fou:: Mouvement(int l, int c){
    std::cout << "Mouvement fou" << std::endl;
}
