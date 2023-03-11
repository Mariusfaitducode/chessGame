#include "dame.h"

Dame::Dame(int l, int c, Color color) : Piece(l, c, color)
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

void Dame:: Mouvement(int l, int c){
    std::cout << "Mouvement dame" << std::endl;
}
