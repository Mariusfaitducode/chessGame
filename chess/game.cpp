#include "game.h"
#include "qbrush.h"
#include "qgraphicsscene.h"
#include "qpen.h"



Game::Game()
{
    std::cout << "Constructeur par defaut Game" << std::endl;

    blanc = *new Player(Color::blanc);
    noir = *new Player(Color::noir);

    tour = 0;
}

void Game::InitPlateau(QGraphicsScene *scene)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {

            QColor color;

            if ((i + j) % 2 == 0){
                color = QColor(255, 206, 158);
            }
            else{
                color = QColor(209, 139, 71);
            }

            QBrush brush(color);
            QPen pen(Qt::black);
            pen.setWidth(1);
            scene->addRect(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, pen, brush);
        }
    }
}

void Game::InstallPieces(QGraphicsScene *scene)
{
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            plateau[i][j] = NULL;
        }
    }

    for (auto piece : blanc.GetPieces())
    {
        SetPiece(scene, piece);

        plateau[piece->C()][piece->L()] = piece;
    }
    for (auto piece : noir.GetPieces())
    {
        SetPiece(scene, piece);

        plateau[piece->C()][piece->L()] = piece;
    }

}

void Game::SetPiece(QGraphicsScene *scene, Piece *piece){

    QPixmap img = piece->GetImage();
    int c = piece->C();
    int l = piece->L();

    QGraphicsPixmapItem *pieceItem = scene->addPixmap(img);

    pieceItem->setScale(0.3333);

    int x = c * SQUARE_SIZE + (SQUARE_SIZE / 2) - (img.width() / 6);
    int y = l * SQUARE_SIZE + (SQUARE_SIZE / 2) - (img.height() / 6);

    pieceItem->setPos(x, y);

    //piece->_item = pieceItem;
    piece->SetItem(pieceItem);

    //pawnItem->setPos(c * SQUARE_SIZE, l * SQUARE_SIZE);
}



void Game::RemovePiece(QGraphicsScene *scene, Piece *piece){

    scene->removeItem(piece->GetItem());

    //pawnItem->setPos(c * SQUARE_SIZE, l * SQUARE_SIZE);
}

/*
bool Game::IsInCheck(Piece* copy_plateau[8][8]){

    //GetPlayer renvoie le joueur à qui c'est le tour en première position et l'autre en deuxième

    std::vector<Player*> players = GetPlayersTour();

    for (auto piece : players[1]->GetPieces())
    {

        std::vector<Vector2> coups = piece->Mouvement(plateau);

        //On vérifie que le roi n'est pas dans coups
        //Le roi est la première pièce de chaque joueur

        Vector2 king = players[0]->GetPiece(0)->GetPos();

        for (auto coup : coups){
            if (king.c == coup.c && king.l == coup.l){
                coups.clear();
                return true;
            }
        }
        coups.clear();
    }
    return false;
}*/


//Fonction qui regarde si il y'a échec

bool Game::IsInCheck(Piece* copy_plateau[8][8]){

    //GetPlayer renvoie le joueur à qui c'est le tour en première position et l'autre en deuxième

    //std::vector<Player*> players = GetPlayersTour();

    std::vector<Color> color = GetColorsTour();

    Vector2 king;

    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if (copy_plateau[c][l] != NULL){

                Piece* piece = copy_plateau[c][l];

                if (piece->GetColor() == color[0] && piece->GetType() == TypePiece::roi){

                    king = piece->GetPos();
                }
            }

        }
    }

    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if (copy_plateau[c][l] != NULL){

                if (copy_plateau[c][l]->GetColor() == color[1]){

                    std::vector<Vector2> coups = copy_plateau[c][l]->Mouvement(plateau);
                    for (auto coup : coups){
                        if (king.c == coup.c && king.l == coup.l){
                            coups.clear();
                            return true;
                        }
                    }
                    coups.clear();
                }
            }
        }
    }
    return false;
}


void Game::SimulatePiece(int c, int l, Piece* copy_plateau[8][8], int last_c, int last_l){

    //On enlève la pièce de sa case initiale
    copy_plateau[last_c][last_l] = NULL;

    //On ajoute la pièce à la bonne case
    selectedPiece->SetPos(c, l);
    copy_plateau[c][l] = selectedPiece;
}


std::vector<Vector2> Game::VerifyCoups(std::vector<Vector2> coups){

    //std::cout << "Debug selected_piece = " << ;
    std::vector<Vector2> valid_coups;

    Piece* copy_plateau[8][8];

    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            copy_plateau[c][l] = plateau[c][l];
        }
    }

    int last_c = selectedPiece->C();
    int last_l = selectedPiece->L();

    for (auto coup : coups){

        int c = coup.c;
        int l = coup.l;

        bool eat_piece = false;
        Piece* last_piece;

        if (copy_plateau[c][l] != NULL){

            last_piece = copy_plateau[c][l];
            //copy_plateau[c][l] = NULL;
            eat_piece = true;
        }

        SimulatePiece(c, l, copy_plateau, last_c, last_l);

        if(!IsInCheck(copy_plateau)){
            std::cout << "validate_coup" << std::endl;
            valid_coups.push_back(coup);
        }

        SimulatePiece(last_c, last_l, copy_plateau, c, l);

        if ( eat_piece){
            copy_plateau[last_c][last_l] = last_piece;
        }
    }

    return valid_coups;
}



//Fonction qui détecte lorsqu'une pièce est séléctionné et affiche les coups possibles

void Game::FirstClickedPiece(QGraphicsScene *scene, Piece* piece){

    selectedPiece = piece;
    std::vector<Vector2> coups = VerifyCoups(piece->Mouvement(plateau));
    //std::vector<Vector2> coups = piece->Mouvement(plateau);

    for (auto coup : coups){
        std::cout << coup.c << coup.l << std::endl;

        int row = coup.l;
        int col = coup.c;

        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();

        ellipse->setRect(col * SQUARE_SIZE + 3*SQUARE_SIZE/8, row * SQUARE_SIZE + 3*SQUARE_SIZE/8, SQUARE_SIZE/4, SQUARE_SIZE/4);
        ellipse->setBrush(QColor(128, 128, 128, 128));
        QPen pen(Qt::transparent);
        ellipse->setPen(pen);


        //GetPlayer(piece).AddCoup(*new Vector2(col, row), ellipse);

        scene->addItem(ellipse);

        AddCoup(*new Vector2(col, row), ellipse);
    }
}


//Fonction permettant de jouer la pièce sélectionné sur la case cliquée (c, l)

void Game::PlayPiece(QGraphicsScene *scene, int c, int l, Piece* clickedCase){

    if (clickedCase == NULL){

        //On enlève la pièce de sa case initiale
        plateau[selectedPiece->C()][selectedPiece->L()] = NULL;
        RemovePiece(scene, selectedPiece);


        //On ajoute la pièce à la bonne case
        selectedPiece->SetPos(c, l);
        plateau[c][l] = selectedPiece;

        SetPiece(scene, plateau[c][l]);
    }
    else{

        //On enlève la pièce de sa case initiale
        plateau[selectedPiece->C()][selectedPiece->L()] = NULL;
        RemovePiece(scene, selectedPiece);

        //On enlève la pièce qui se fait manger
        RemovePiece(scene, clickedCase);
        clickedCase = NULL;


        //On ajoute la pièce à la bonne case
        selectedPiece->SetPos(c, l);
        plateau[c][l] = selectedPiece;

        SetPiece(scene, plateau[c][l]);

    }
    IncrementTour();
    std::cout << "Piece played " << std::endl;
    //clickedCase->ShowPiece();
    //GetPiece(c, l)->ShowPiece();
}




void Game::AddCoup(Vector2 pos, QGraphicsEllipseItem *ellipse){

    possible_coups.push_back(*new Coup(pos, ellipse));
}

void Game::RemoveCoups(QGraphicsScene *scene){

    for (auto coup : possible_coups){
        scene->removeItem(coup._ellipse);

    }
    possible_coups.clear();
}


bool Game::ClickedInCoups(int c, int l){

    for (auto coup : possible_coups){

        int C = coup._pos.c;
        int L = coup._pos.l;

        if ( c == C && l == L){
            return true;
        }
    }
    return false;
}


Color Game::GetColorTour(){

    if (tour % 2 == 0){
        return Color::blanc;
    }
    else{
        return Color::noir;
    }
}

std::vector<Color> Game::GetColorsTour(){

    std::vector<Color> colors;

    if (tour % 2 == 0){
        colors.push_back(Color::blanc);
        colors.push_back(Color::noir);
        return colors;
    }
    else{
        colors.push_back(Color::noir);
        colors.push_back(Color::blanc);
        return colors;
    }
}

std::vector<Player*> Game::GetPlayersTour(){

    std::vector<Player*> players;

    if (tour % 2 == 0){
        players.push_back(&blanc);
        players.push_back(&noir);
        return players;
    }
    else{
        players.push_back(&noir);
        players.push_back(&blanc);
        return players;
    }
}

void Game::DisplayPlateau(){

    std::cout << " ---   ---   ---   ---   ---   ---   ---   --- "<< std::endl;
    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if ( plateau[c][l] != NULL){
                std::cout << "| " << plateau[c][l]->ShowSign() << " | ";
            }
            else{
                std::cout << "|   | ";
            }

        }
        std::cout << std::endl;
        std::cout << " ---   ---   ---   ---   ---   ---   ---   --- "<< std::endl;
    }
}






