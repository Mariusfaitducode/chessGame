#include "game.h"
#include "qbrush.h"
#include "qgraphicsscene.h"
#include "qpen.h"



Game::Game()
{
    std::cout << "Constructeur par defaut Game" << std::endl;

    blanc = *new Player(Color::blanc);
    noir = *new Player(Color::noir);


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
        SetPiece(scene, piece->GetImage(), piece->C(), piece->L());

        plateau[piece->C()][piece->L()] = piece;
    }
    for (auto piece : noir.GetPieces())
    {
        SetPiece(scene, piece->GetImage(), piece->C(), piece->L());

        plateau[piece->C()][piece->L()] = piece;
    }

}

void Game::SetPiece(QGraphicsScene *scene, QPixmap piece, int c, int l){

    QGraphicsPixmapItem *pawnItem = scene->addPixmap(piece);

    pawnItem->setScale(0.3333);

    int x = c * SQUARE_SIZE + (SQUARE_SIZE / 2) - (piece.width() / 6);
    int y = l * SQUARE_SIZE + (SQUARE_SIZE / 2) - (piece.height() / 6);

    pawnItem->setPos(x, y);

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


void Game::SetCoupsPlayer(Vector2 pos, QGraphicsEllipseItem ellipse){


}

void Game::FirstClickedPiece(QGraphicsScene *scene, Piece* piece){

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




void Game::AddCoup(Vector2 pos, QGraphicsEllipseItem *ellipse){

    possible_coups.push_back(*new Coup(pos, ellipse));
}

void Game::RemoveCoups(QGraphicsScene *scene){

    for (auto coup : possible_coups){
        scene->removeItem(coup._ellipse);

    }
    possible_coups.clear();
}













