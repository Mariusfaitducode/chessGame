#include "roi.h"

Roi::Roi(int l, int c, Color color) : Piece(Vector2(c, l), color)
{
    _type = TypePiece::roi;
    can_rock = true;

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
    //std::cout << "Mouvement roi" << std::endl;

    std::vector<Vector2> coups;

    int c = _pos.c;
    int l = _pos.l;

    for (int i = -1; i < 2; i += 1){
        for (int j = -1; j < 2; j += 1){

            if (IsOnBoard(Vector2(c + i, l + j))){

                if (plateau[c + i][l + j] == NULL){

                    coups.push_back(Vector2(c + i, l + j));

                }
                else if(plateau[c + i][l + j]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + i, l + j));
                }
            }
        }
    }

    if (can_rock){

        bool left_rock = true;

        for (int i = 1; i < 4; i++){

            if (plateau[c - i][l] != NULL){
                left_rock = false;
            }
        }
        if (left_rock){
            if (plateau[0][l]->GetType() == TypePiece::tour && plateau[0][l]->GetColor() == this->_color){
                std::cout << "Rock possible";
                coups.push_back(Vector2(2, l));
            }
        }

        bool right_rock = true;

        for (int i = 1; i < 3; i++){

            if (plateau[c + i][l] != NULL){
                right_rock = false;
            }
        }
        if (right_rock){
            if (plateau[7][l]->GetType() == TypePiece::tour && plateau[7][l]->GetColor() == this->_color){
                std::cout << "Rock possible";
                coups.push_back(Vector2(6, l));
            }
        }
    }

    return coups;
}


