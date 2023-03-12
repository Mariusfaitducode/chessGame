#include "dame.h"

Dame::Dame(int l, int c, Color color) : Piece(Vector2(c, l), color)
{
    _type = TypePiece::dame;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_queen.png");
    }
    else{
        _image = QPixmap(":/images/b_queen.png");
    }
}

Dame::~Dame(){

}

std::vector<Vector2> Dame:: Mouvement(Piece *plateau[8][8]){
    std::cout << "Mouvement dame" << std::endl;

    std::vector<Vector2> coups;

    return coups;
}
