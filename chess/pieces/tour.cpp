#include "tour.h"


Tour::Tour(int l, int c, Color color) : Piece(Vector2(c, l), color)
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

std::vector<Vector2> Tour:: Mouvement(Piece* plateau[8][8]){

    std::cout << "Mouvement tour" << std::endl;

    std::vector<Vector2> coups;

    int c = _pos.c;
    int l = _pos.l;

    //ligne

    for (int i = -1; i< 2; i += 2){

        std::cout << "ok1" << std::endl;
        std::cout << IsOnBoard(Vector2(c + i, l)) << std::endl;
        std::cout << IsOnBoard(Vector2(c, l + i)) << std::endl;


        if (IsOnBoard(Vector2(c + i, l))){

            if (plateau[c + i][l] == NULL){

                std::cout << "ok" << std::endl;

                coups.push_back(Vector2(c + i, l));

                NextCases(_pos, Vector2(c + i, l), &coups, plateau);
            }
            else if(plateau[c + i][l]->GetColor() != this->_color){

                coups.push_back(Vector2(c + i, l));
            }
        }

        if (IsOnBoard(Vector2(c, l + i))){

            if (plateau[c][l + i] == NULL){

                coups.push_back(Vector2(c, l + i));

                NextCases(_pos, Vector2(c, l + i), &coups, plateau);
            }
            else if(plateau[c][l + i]->GetColor() != this->_color){

                coups.push_back(Vector2(c, l + i));
            }
        }
    }

    return coups;
}
