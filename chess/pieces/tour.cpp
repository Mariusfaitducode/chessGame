#include "tour.h"


Tour::Tour(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::tour;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_rook.png");
    }
    else{
        _image = QPixmap(":/images/b_rook.png");
    }
}

Tour::~Tour(){

}

void Tour:: Mouvement(int l, int c){
    std::cout << "Mouvement tour" << std::endl;
}
