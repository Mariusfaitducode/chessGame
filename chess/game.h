#ifndef GAME_H
#define GAME_H

#include <player.h>

#include <QGraphicsPixmapItem>


const int SQUARE_SIZE = 99;
const int BOARD_SIZE = 8;


class Game
{
public:
    Game();

    void InitPlateau(QGraphicsScene *scene);

    void InstallPieces(QGraphicsScene *scene);

    void SetPiece(QGraphicsScene *scene, QPixmap piece, int c, int l);

public:
    Player blanc;
    Player noir;

    char plateau[8][8];
};

#endif // GAME_H
