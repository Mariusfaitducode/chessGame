#include "fou.h"

Fou::Fou(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::fou;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_bishop.png");
    }
    else{
        _image = QPixmap(":/images/b_bishop.png");
    }

}

Fou::~Fou(){

}

void Fou:: Mouvement(int l, int c){
    std::cout << "Mouvement fou" << std::endl;
}
