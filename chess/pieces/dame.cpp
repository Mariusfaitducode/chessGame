#include "dame.h"

Dame::Dame(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::dame;
}

Dame::~Dame(){

}

void Dame:: Mouvement(int l, int c){
    std::cout << "Mouvement dame" << std::endl;
}
