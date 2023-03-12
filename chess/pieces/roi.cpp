#include "roi.h"

Roi::Roi(int l, int c, Color color) : Piece(Vector2(c, l), color)
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

std::vector<Vector2> Roi::Mouvement(Piece* plateau[8][8]){
    std::cout << "Mouvement roi" << std::endl;

    std::vector<Vector2> coups;

    return coups;
}
