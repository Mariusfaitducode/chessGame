#include "roi.h"

Roi::Roi(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::roi;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_king.png");
    }
    else{
        _image = QPixmap(":/images/b_king.png");
    }
}

Roi::~Roi(){

}

void Roi:: Mouvement(int l, int c){
    std::cout << "Mouvement roi" << std::endl;
}
