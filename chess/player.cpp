#include "player.h"

Player::Player()
{
    _pieces.push_back(new Pion(TypePiece::pion, 1, 1, Color::blanc));
}

Player::~Player(){

    std::cout << "Destructeur Player" << std::endl;

    for (auto piece : _pieces)
    {
        delete piece;
    }
}
