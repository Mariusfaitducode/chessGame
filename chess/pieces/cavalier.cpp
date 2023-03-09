#include "cavalier.h"

Cavalier::Cavalier(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::cavalier;
}

Cavalier::~Cavalier(){

}

void Cavalier:: Mouvement(int l, int c){
    std::cout << "Mouvement cavalier" << std::endl;
}
