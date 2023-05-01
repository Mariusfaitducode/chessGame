#ifndef GAME_H
#define GAME_H

#include <player.h>

#include <QGraphicsPixmapItem>

#include <QDebug>

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


const int SQUARE_SIZE = 99;
//const int BOARD_SIZE = 8;




class Game
{
public:
    Game();

    //Initialisations du plateau
    void InitPlateau(QGraphicsScene *scene);

    void InstallPieces(QGraphicsScene *scene);

    //Ajout et retrait d'une pièce sur l'interface
    void SetPiece(QGraphicsScene *scene, Piece *piece);
    void RemovePiece(QGraphicsScene *scene, Piece *piece);

    Piece* GetPiece(int c, int l){return plateau[c][l];}


    void SimulatePiece(int c, int l, Piece* copy_plateau[8][8], int last_c, int last_l, Piece* piece);

    //Fonction permettant de vérifier si les coups donnés ne provoquent pas d'échecs
    //Ressort les coups seulement valide
    std::vector<Vector2> VerifyCoups(std::vector<Vector2> coups, Piece* piece);

    //Fonction qui détecte lorsqu'une pièce est séléctionné et affiche les coups possibles
    void FirstClickedPiece(QGraphicsScene *scene, Piece* piece);

    //Piece *[8][8] GetPlateau(){return plateau;}


    //Fonctions pour possible_coups
    void AddCoup(Vector2 pos, QGraphicsEllipseItem *ellipse);
    void RemoveCoups(QGraphicsScene *scene);

    // second clique si il y'a des coups possibles sélectionnés
    // possible_coup not empty

    bool IsInCheck(Piece* copy_plateau[8][8]);

    bool CheckInGame(){
        return IsInCheck(plateau);
    }

    bool EchecEtMat();

    bool IsFirstClick(){return possible_coups.empty();}

    bool ClickedInCoups(int c, int l);


    void PlayPiece(QGraphicsScene *scene, int c, int l, Piece* clickedCase);


    int GetTour(){return tour;}
    Color GetColorTour();
    std::vector<Color> GetColorsTour();
    std::vector<Player*> GetPlayersTour();

    void IncrementTour(){tour++;}

    void DisplayPlateau();
    void DisplayCopyPlateau(Piece* copy_plateau[8][8]);

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
