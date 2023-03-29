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

    Player GetPlayer(Piece *piece);

    void SetCoupsPlayer(Vector2 pos, QGraphicsEllipseItem ellipse);

    void FirstClickedPiece(QGraphicsScene *scene, Piece* piece);

    //Piece *[8][8] GetPlateau(){return plateau;}


    //Fonctions pour possible_coups
    void AddCoup(Vector2 pos, QGraphicsEllipseItem *ellipse);
    void RemoveCoups(QGraphicsScene *scene);


private:

    Player blanc;

    Player noir;

    Piece* plateau[8][8];

    //La classe Coup représente les coups affichés lorsque l'on clique sur une pièce, définit dans player.h
    std::vector<Coup> possible_coups;

};

#endif // GAME_H
