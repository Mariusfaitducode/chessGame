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
    return coups;
}


std::vector<Vector2> Roi::RockMouvement(Piece* plateau[8][8]){

    std::vector<Vector2> coups;

    int c = _pos.c;
    int l = _pos.l;

    //Si le rock est autorisé et que le roi n'est pas échec
    if (can_rock && !IsThreatened(Vector2(c, l), plateau)){

        bool left_rock = true;
        bool right_rock = true;

        //Si le rock n'est pas entravé par une pièce ou une menace
        for (int i = 1; i < 3; i++){

            if (plateau[c - i][l] != NULL || IsThreatened(Vector2(c - i, l), plateau)){
                left_rock = false;
            }
            if (plateau[c + i][l] != NULL || IsThreatened(Vector2(c + i, l), plateau)){
                right_rock = false;
            }
        }
        //Cas du grand rock case menaçable
        if (plateau[1][l] != NULL){
            left_rock = false;
        }


        if (left_rock){
            if (plateau[0][l]->GetType() == TypePiece::tour && plateau[0][l]->GetColor() == this->_color && plateau[0][l]->can_rock){
                std::cout << "Rock possible";
                coups.push_back(Vector2(2, l));
            }
        }

        if (right_rock){
            if (plateau[7][l]->GetType() == TypePiece::tour && plateau[7][l]->GetColor() == this->_color && plateau[7][l]->can_rock){
                std::cout << "Rock possible";
                coups.push_back(Vector2(6, l));
            }
        }
    }
    return coups;
}


