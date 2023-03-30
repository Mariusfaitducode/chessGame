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

    //Ajout et retrait d'une pièce sur l'interface
    void SetPiece(QGraphicsScene *scene, Piece *piece);
    void RemovePiece(QGraphicsScene *scene, Piece *piece);

    Piece* GetPiece(int c, int l){return plateau[c][l];}

    Player GetPlayer(Piece *piece);


    void FirstClickedPiece(QGraphicsScene *scene, Piece* piece);

    //Piece *[8][8] GetPlateau(){return plateau;}


    //Fonctions pour possible_coups
    void AddCoup(Vector2 pos, QGraphicsEllipseItem *ellipse);
    void RemoveCoups(QGraphicsScene *scene);

    // second clique si il y'a des coups possibles sélectionnés
    // possible_coup not empty
    bool IsFirstClick(){return possible_coups.empty();}

    bool ClickedInCoups(int c, int l);


    void PlayPiece(QGraphicsScene *scene, int c, int l, Piece* clickedCase);


    Color GetColorTour();

    void IncrementTour(){tour++;}

private:

    Player blanc;

    Player noir;

    Piece* plateau[8][8];

    //La classe Coup représente les coups affichés lorsque l'on clique sur une pièce, définit dans player.h
    std::vector<Coup> possible_coups;

    int tour;

    Piece* selectedPiece;

};

#endif // GAME_H
