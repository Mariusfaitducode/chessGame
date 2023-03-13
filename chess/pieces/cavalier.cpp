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

    int c = _pos.c;
    int l = _pos.l;

    for (int i = -1; i<2; i+=2){  //(-1, +1)

        for (int j = -2; j<3; j+=4){  //(-2, +2)

            if (IsOnBoard(Vector2(c + i, l + j))){

                if (plateau[c + i][l + j] == NULL){

                    coups.push_back(Vector2(c + i, l + j));

                }
                else if(plateau[c + i][l + j]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + i, l + j));
                }
            }
            if (IsOnBoard(Vector2(c + j, l + i))){

                if (plateau[c + j][l + i] == NULL){

                    coups.push_back(Vector2(c + j, l + i));

                }
                else if(plateau[c + j][l + i]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + j, l + i));
                }
            }
        }
    }

    return coups;
}
