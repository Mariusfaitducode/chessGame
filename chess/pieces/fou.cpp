#include "fou.h"

Fou::Fou(int l, int c, Color color) : Piece(Vector2(c, l), color)
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

std::vector<Vector2> Fou:: Mouvement(Piece* plateau[8][8]){
    std::cout << "Mouvement fou" << std::endl;

    std::vector<Vector2> coups;

    return coups;
}
