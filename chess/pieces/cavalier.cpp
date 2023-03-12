#include "cavalier.h"

Cavalier::Cavalier(int l, int c, Color color) : Piece(Vector2(c, l), color)
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

std::vector<Vector2> Cavalier:: Mouvement(Piece* plateau[8][8]){
    std::cout << "Mouvement cavalier" << std::endl;

    std::vector<Vector2> coups;

    return coups;
}
