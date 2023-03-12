#include "pion.h"

Pion::Pion(int l, int c, Color color) : Piece(Vector2(c, l), color)
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

std::vector<Vector2> Pion:: Mouvement(Piece* plateau[8][8]){
    std::cout << "Mouvement pion" << std::endl;

    std::vector<Vector2> coups;

    return coups;
}
