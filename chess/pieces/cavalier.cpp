#include "cavalier.h"

Cavalier::Cavalier(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::cavalier;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_horse.png");
    }
    else{
        _image = QPixmap(":/images/b_horse.png");
    }
}

Cavalier::~Cavalier(){

}

void Cavalier:: Mouvement(int l, int c){
    std::cout << "Mouvement cavalier" << std::endl;
}
