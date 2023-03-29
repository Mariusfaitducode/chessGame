#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


MainWindow::~MainWindow()
{
    delete ui;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QGraphicsScene *scene = new QGraphicsScene(this);

    scene = new ChessScene(this);

    ui->graphicsView->setScene(scene);


    //Initialisation du jeu

    game = new Game();

    game->InitPlateau(scene);

    game->InstallPieces(scene);


    //Detection des cliques

    connect(scene, &ChessScene::mousePressed, this, &MainWindow::onSceneClicked);

}




void MainWindow::onSceneClicked(QGraphicsSceneMouseEvent *event)
{
    // Récupérer les coordonnées de la case dans laquelle l'utilisateur a cliqué
    int c = event->scenePos().x() / SQUARE_SIZE;
    int l = event->scenePos().y() / SQUARE_SIZE;

    std::cout << "C : " << c << std::endl;
    std::cout << "L : " << l << std::endl;

    Piece* clickedCase = game->GetPiece(c, l);


    if (clickedCase != NULL){ // Si il y'a bien une pièce

        clickedCase->ShowPiece();

        if (game->IsFirstClick()){

            game->FirstClickedPiece(scene, clickedCase);
        }
        else if(!game->ClickedInCoups(c, l)){

            game->RemoveCoups(scene);
            game->FirstClickedPiece(scene, clickedCase);
        }
    }
    else{
        //erase click

        if(game->ClickedInCoups(c, l)){

            game->PlayPiece(scene, c, l, clickedCase);
            //game->SetPiece(scene, clickedCase->GetImage(), clickedCase->C(), clickedCase->L());
        }
    }
}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressed(event);
}





