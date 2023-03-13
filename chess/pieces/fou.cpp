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

    int c = _pos.c;
    int l = _pos.l;

    for (int i = -1; i < 2; i += 2){
        for (int j = -1; j < 2; j += 2){

            if (IsOnBoard(Vector2(c + i, l + j))){

                if (plateau[c + i][l + j] == NULL){

                    coups.push_back(Vector2(c + i, l + j));

                    NextCases(_pos, Vector2(c + i, l + j), &coups, plateau);
                }
                else if(plateau[c + i][l + j]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + i, l + j));
                }
            }
        }
    }

    return coups;
}
