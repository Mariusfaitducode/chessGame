#include "game.h"

Game::Game()
{
    std::cout << "Constructeur par defaut Game" << std::endl;

    blanc = *new Player(Color::blanc);
    noir = *new Player(Color::noir);


}
