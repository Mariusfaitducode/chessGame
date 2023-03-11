#include "pion.h"

Pion::Pion(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::pion;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_pawn.png");
    }
    else{
        _image = QPixmap(":/images/b_pawn.png");
    }
}

Pion::~Pion(){

}

void Pion:: Mouvement(int l, int c){
    std::cout << "Mouvement pion" << std::endl;
}
