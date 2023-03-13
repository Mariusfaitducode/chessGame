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
