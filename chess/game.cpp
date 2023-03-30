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

Player Game::GetPlayer(Piece *piece){

    if (piece->GetColor() == Color::blanc){
        return blanc;
    }
    else{
        return noir;
    }
}




void Game::FirstClickedPiece(QGraphicsScene *scene, Piece* piece){

    selectedPiece = piece;
    std::vector<Vector2> coups = piece->Mouvement(plateau);

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









