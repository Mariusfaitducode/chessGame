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

    //On récupère le roi de la personne qui joue
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

    //On regarde tous les coups de l'adversaire
    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if (copy_plateau[c][l] != NULL){

                if (copy_plateau[c][l]->GetColor() == color[1]){

                    std::vector<Vector2> coups = copy_plateau[c][l]->Mouvement(copy_plateau);

                    //On regarde si le roi se trouve parmis les coups donc en échec
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

bool Game::EchecEtMat(){

    std::vector<Color> color = GetColorsTour();

    if (color[0] == Color::blanc){
        qDebug() << "les blancs sont échecs";
    }
    else{
        qDebug() << "les noirs sont échecs";
    }


    //On regarde tous nos coups
    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if (plateau[c][l] != NULL){

                if (plateau[c][l]->GetColor() == Color::blanc){

                    std::vector<Vector2> coups = plateau[c][l]->Mouvement(plateau);


                    if (!VerifyCoups(coups, plateau[c][l]).empty()){


                        qDebug() << "No mat";
                        for (auto coup: coups){

                            qDebug() << "Possible coups are :" << coup.c << coup.l;
                        }
                        return false;
                    }
                    coups.clear();
                }
            }
        }
    }

    qDebug() << "Echec et mat";
    return true;
}


void Game::SimulatePiece(int c, int l, Piece* copy_plateau[8][8], int last_c, int last_l, Piece* piece){

    //On enlève la pièce de sa case initiale
    copy_plateau[last_c][last_l] = NULL;

    //On ajoute la pièce à la bonne case
    piece->SetPos(c, l);
    copy_plateau[c][l] = piece;
}

//Fonction qui renvoie la liste des coups valides pour une pièce donnée

std::vector<Vector2> Game::VerifyCoups(std::vector<Vector2> coups, Piece* piece){

    //std::cout << "Debug selected_piece = " << ;
    std::vector<Vector2> valid_coups;

    Piece* copy_plateau[8][8];

    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            copy_plateau[c][l] = plateau[c][l];
        }
    }

    int last_c = piece->C();
    int last_l = piece->L();

    qDebug() <<"selected piece :"<<last_c<<last_l;


    for (auto coup : coups){

        int c = coup.c;
        int l = coup.l;

        qDebug() <<"coup :"<<c<<l;

        bool eat_piece = false;
        Piece* last_piece;

        if (copy_plateau[c][l] != NULL){

            last_piece = copy_plateau[c][l];
            //copy_plateau[c][l] = NULL;
            eat_piece = true;
            qDebug() << "eat piece";
        }

        //Simule le coup
        SimulatePiece(c, l, copy_plateau, last_c, last_l, piece);

        DisplayCopyPlateau(copy_plateau);

        if(!IsInCheck(copy_plateau)){
            qDebug() << "validate_coup";
            valid_coups.push_back(coup);
        }
        else{
            qDebug() << "not_valid";
        }

        //Replace la pièce simulé à sa position de départ
        SimulatePiece(last_c, last_l, copy_plateau, c, l, piece);

        if ( eat_piece){
            copy_plateau[c][l] = last_piece;
        }
    }

    return valid_coups;
}



//Fonction qui détecte lorsqu'une pièce est séléctionné et affiche les coups possibles

void Game::FirstClickedPiece(QGraphicsScene *scene, Piece* piece){

    selectedPiece = piece;

    //récupère les coups valides
    std::vector<Vector2> coups = VerifyCoups(piece->Mouvement(plateau), piece);

    if (selectedPiece->GetType() == TypePiece::roi){
        std::vector<Vector2> rock_coups = piece->RockMouvement(plateau);
        for (auto c : rock_coups){
            coups.push_back(c);
        }
    }
    //std::vector<Vector2> coups = piece->Mouvement(plateau);


    //affiche et sauvegarde les coups
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

    //Si l'utilisateur a cliqué une case vide
    if (clickedCase == NULL){

        //Dans le cas où un rock est joué
        if (selectedPiece->GetType() == TypePiece::roi && selectedPiece->can_rock && ( c == 2 || c == 6 )){

            int c_rook = 0;
            int new_c_rook = 0;

            if (c == 2){
                //Grand rock
                c_rook = 0;
                new_c_rook = 3;
            }else if (c == 6){
                //Petit rock
                c_rook = 7;
                new_c_rook = 5;
            }

            //On enlève le roi de sa case initiale
            plateau[selectedPiece->C()][selectedPiece->L()] = NULL;
            RemovePiece(scene, selectedPiece);

            //On enlève la tour de sa case initiale
            Piece* tour = plateau[c_rook][l];
            plateau[c_rook][l] = NULL;
            RemovePiece(scene, tour);

            //On ajoute le roi à la bonne case
            selectedPiece->SetPos(c, l);
            plateau[c][l] = selectedPiece;

            tour->SetPos(new_c_rook, l);
            plateau[new_c_rook][l] = tour;

            SetPiece(scene, plateau[c][l]);
            SetPiece(scene, plateau[new_c_rook][l]);

            selectedPiece->can_rock = false;

        }
        //Si le roi est joué normalement -> plus de rock
        else if (selectedPiece->GetType() == TypePiece::roi){
            selectedPiece->can_rock = false;
        }

        //On enlève la pièce de sa case initiale
        plateau[selectedPiece->C()][selectedPiece->L()] = NULL;
        RemovePiece(scene, selectedPiece);


        //On ajoute la pièce à la bonne case
        selectedPiece->SetPos(c, l);
        plateau[c][l] = selectedPiece;

        SetPiece(scene, plateau[c][l]);


    }
    //Si l'utilisateur mange une pièce
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
    if (selectedPiece->GetType() == TypePiece::tour){
        selectedPiece->can_rock = false;
    }
    //Si le pion est promu
    else if (selectedPiece->GetType() == TypePiece::pion && (l == 0 || l == 7)){

        if (l == 0){
            Piece* dame = new Dame(l, c, Color::noir);

            RemovePiece(scene, selectedPiece);
            selectedPiece = NULL;

            plateau[c][l] = dame;
            SetPiece(scene, plateau[c][l]);

            noir.AddPiece(dame);
        }
        else if (l == 7){
            Piece* dame = new Dame(l, c, Color::blanc);

            RemovePiece(scene, selectedPiece);
            selectedPiece = NULL;

            plateau[c][l] = dame;
            SetPiece(scene, plateau[c][l]);

            blanc.AddPiece(dame);
        }
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

void Game::DisplayCopyPlateau(Piece* copy_plateau[8][8]){

    std::cout << WHITE << " ---   ---   ---   ---   ---   ---   ---   --- "<< std::endl;
    for (int l = 0; l < BOARD_SIZE; l++){
        for (int c = 0; c < BOARD_SIZE; c++){

            if ( copy_plateau[c][l] != NULL){

                if (copy_plateau[c][l]->GetColor() == Color::blanc){
                    std::cout << WHITE << "| " << CYAN << copy_plateau[c][l]->ShowSign() << WHITE << " | ";
                }
                else{
                    std::cout << WHITE << "| " RED << copy_plateau[c][l]->ShowSign() << WHITE << " | ";
                }

            }
            else{
                std::cout << WHITE << "|   | ";
            }

        }
        std::cout << std::endl;
        std::cout << WHITE << " ---   ---   ---   ---   ---   ---   ---   --- "<< std::endl;
    }
}






