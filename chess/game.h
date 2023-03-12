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

    Piece* GetPiece(int c, int l){return plateau[c][l];}

    void FirstClickedPiece(Piece* piece);

    //Piece *[8][8] GetPlateau(){return plateau;}

private:
    Player blanc;
    Player noir;

    Piece* plateau[8][8];
};

#endif // GAME_H
