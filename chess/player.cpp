#include "player.h"

Player::Player()
{
    std::cout << "Constructeur par defaut" << std::endl;
    std::cout << "Pieces non initialisees" << std::endl;
}

Player::Player(Color color)
{
    if(color == Color::blanc){
        std::cout << "Constructeur blanc" << std::endl;

        for (int i = 0; i < 8; i++){
            _pieces.push_back(new Pion(1, i, color));
        }
        _pieces.push_back(new Tour(0, 0, color));
        _pieces.push_back(new Tour(0, 7, color));

        _pieces.push_back(new Cavalier(0, 1, color));
        _pieces.push_back(new Cavalier(0, 6, color));

        _pieces.push_back(new Fou(0, 2, color));
        _pieces.push_back(new Fou(0, 5, color));

        _pieces.push_back(new Dame(0, 3, color));
        _pieces.push_back(new Roi(0, 4, color));

    }
    else{
        std::cout << "Constructeur noir" << std::endl;

        for (int i = 0; i < 8; i++){
            _pieces.push_back(new Pion(6, i, color));
        }
        _pieces.push_back(new Tour(7, 0, color));
        _pieces.push_back(new Tour(7, 7, color));

        _pieces.push_back(new Cavalier(7, 1, color));
        _pieces.push_back(new Cavalier(7, 6, color));

        _pieces.push_back(new Fou(7, 2, color));
        _pieces.push_back(new Fou(7, 5, color));

        _pieces.push_back(new Dame(7, 3, color));
        _pieces.push_back(new Roi(7, 4, color));

    }

    //_pieces.push_back(new Pion(TypePiece::pion, 1, 1, Color::blanc));
}

Player::~Player(){

    std::cout << "Destructeur Player" << std::endl;

    for (auto piece : _pieces)
    {
        delete piece;
    }
    /*for (auto coup : _coups){
        delete coup;
    }*/
}

Player& Player:: operator = (const Player &p)
{
    if (this != &p){

        for (auto piece : _pieces)
        {
            delete piece;
        }

        _color = p._color;

        for (auto piece : p._pieces)
        {
            _pieces.push_back(piece);
        }


    }
    return *this;
}



void Player::ShowPieces(){

    for (auto piece : _pieces)
    {
        //std::cout << piece->Mouvement(1,1) << std::endl;
        piece->ShowPiece();
    }
}










