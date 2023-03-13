#include "pion.h"

Pion::Pion(int l, int c, Color color) : Piece(Vector2(c, l), color)
{
    _type = TypePiece::pion;

    if (color == Color::blanc){
        _image = QPixmap(":/images/w_pawn.png");
    }
    else{
        _image = QPixmap(":/images/b_pawn.png");
    }
}

Pion::~Pion(){

}

std::vector<Vector2> Pion:: Mouvement(Piece* plateau[8][8]){
    std::cout << "Mouvement pion" << std::endl;

    std::vector<Vector2> coups;

    int c = _pos.c;
    int l = _pos.l;

    if (_color == Color::blanc){

        //avance d'une case
        if (IsOnBoard(Vector2(c, l + 1))){

            if (plateau[c][l + 1] == NULL){

                coups.push_back(Vector2(c, l + 1));
            }
        }
        //avance de 2 cases si premier coup
        if (IsOnBoard(Vector2(c, l + 2)) && l == 1){

            if (plateau[c][l + 2] == NULL){

                coups.push_back(Vector2(c, l + 2));
            }
        }
        //manger pièces
        for (int i = -1; i < 2; i+=2){

            if (IsOnBoard(Vector2(c + i, l + 1)) && plateau[c + i][l + 1]!= NULL){

                if(plateau[c + i][l + 1]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + i, l + 1));
                }
            }
        }
    }
    else{
        //avance d'une case
        if (IsOnBoard(Vector2(c, l - 1))){

            if (plateau[c][l - 1] == NULL){

                coups.push_back(Vector2(c, l - 1));
            }
        }
        //avance de 2 cases si premier coup
        if (IsOnBoard(Vector2(c, l - 2)) && l == 6){

            if (plateau[c][l - 2] == NULL){

                coups.push_back(Vector2(c, l - 2));
            }
        }
        //manger pièces
        for (int i = -1; i < 2; i+=2){

            if (IsOnBoard(Vector2(c + i, l - 1)) && plateau[c + i][l - 1]!= NULL){

                if(plateau[c + i][l - 1]->GetColor() != this->_color){

                    coups.push_back(Vector2(c + i, l - 1));
                }
            }
        }
    }

    return coups;
}
