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

    if (game->IsInCheck()){
        std::cout << "Is In Check"<< std::endl;
    }


    if (clickedCase != NULL){ // Si il y'a bien une pièce

        clickedCase->ShowPiece();

        if (clickedCase->GetColor() == game->GetColorTour()){

            //Si aucune pièce n'est sélectionné
            if (game->IsFirstClick()){

                game->FirstClickedPiece(scene, clickedCase);
            }
            //Si une nouvelle pièce est sélectionné
            else{
                game->RemoveCoups(scene);
                game->FirstClickedPiece(scene, clickedCase);
            }
        }
        //Si une pièce est mangé
        else{
            if (game->ClickedInCoups(c, l)){
                game->PlayPiece(scene, c, l, clickedCase);
                game->RemoveCoups(scene);
            }
        }
    }
    else{
        if(game->ClickedInCoups(c, l)){

            game->PlayPiece(scene, c, l, clickedCase);
            //game->SetPiece(scene, clickedCase->GetImage(), clickedCase->C(), clickedCase->L());
            game->RemoveCoups(scene);
        }
    }
    game->DisplayPlateau();
}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressed(event);
}





