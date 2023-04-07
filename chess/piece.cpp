#include "piece.h"

/*
Piece::Piece(TypePiece type, int l, int c, Color color)
{
    _type = type;
    _l = l;
    _c = c;
    _color = color;
}*/

Piece::Piece(Vector2 pos, Color color)
{
    _pos = pos;

    _color = color;
}

Piece::~Piece(){

}

void Piece::ShowPiece(){

    switch(_type){
        case TypePiece::pion: std::cout << "pion "; break;
        case TypePiece::cavalier: std::cout << "cavalier "; break;
        case TypePiece::fou: std::cout << "fou "; break;
        case TypePiece::tour: std::cout << "tour "; break;
        case TypePiece::dame: std::cout << "dame "; break;
        case TypePiece::roi: std::cout << "roi "; break;
        break;
    }

    switch(_color){
        case Color::blanc: std::cout << "blanc, "; break;
        case Color::noir: std::cout << "noir, "; break;
        break;
    }

    std::cout << "position : " << _pos.c << _pos.l << std::endl;

    std::cout << std::endl;
}

std::string Piece::ShowSign(){

    switch(_type){
        case TypePiece::pion: return "P";
        case TypePiece::cavalier: return "C";
        case TypePiece::fou: return "F";
        case TypePiece::tour: return "T";
        case TypePiece::dame: return "D";
        case TypePiece::roi: return "R";
        break;
    }
}


void Piece::SetPos(int c, int l){

    _pos.c = c;
    _pos.l = l;
}


void Piece::NextCases(Vector2 v1, Vector2 v2, std::vector<Vector2>* coups, Piece* plateau[8][8]){

    int c = 2 * v2.c - v1.c;
    int l = 2 * v2.l - v1.l;

    Vector2 v3(c, l);

    if (IsOnBoard(Vector2(c, l))){

        if (plateau[c][l] == NULL){

            coups->push_back(v3);

            NextCases(v2, v3, coups, plateau);

        }
        else if (plateau[c][l]->GetColor() != this->_color){

            coups->push_back(v3);
        }
    }
}

bool Piece::IsOnBoard(Vector2 v){

    if (0 <= v.c && v.c < 8 && 0 <= v.l && v.l < 8){
        return true;
    }
    return false;
}

