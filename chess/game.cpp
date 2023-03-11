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

    for (auto piece : blanc.GetPieces())
    {
        SetPiece(scene, piece->GetImage(), piece->C(), piece->L());
    }
    for (auto piece : noir.GetPieces())
    {
        SetPiece(scene, piece->GetImage(), piece->C(), piece->L());
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











