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


    bool played = false;



    if (clickedCase != NULL){ // Si il y'a bien une pièce

        clickedCase->ShowPiece();

        if (clickedCase->GetColor() == game->GetColorTour()){

            //Si aucune pièce n'est sélectionné
            if (game->IsFirstClick()){

                std::cout<<"Initial plateau"<<std::endl;
                game->DisplayPlateau();

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
                played = true;
            }
        }
    }
    else{
        if(game->ClickedInCoups(c, l)){

            game->PlayPiece(scene, c, l, clickedCase);
            //game->SetPiece(scene, clickedCase->GetImage(), clickedCase->C(), clickedCase->L());
            game->RemoveCoups(scene);
            played = true;
        }
    }

    if ( played){
        if (game->GetColorTour() == Color::blanc){
            ui->label_tour->setText("Tour : "+ QString::number(game->GetTour() + 1)+ ", Coups aux blancs");
        }
        else{
            ui->label_tour->setText("Tour : "+ QString::number(game->GetTour() + 1)+ ", Coups aux noirs");
        }

        if (game->CheckInGame()){

            if (game->EchecEtMat()){
                if (game->GetColorTour() == Color::blanc){
                    ui->label_check->setText("Blancs échec et mat");
                }
                else{
                    ui->label_check->setText("Noirs échec et mat");
                }
            }
            else{
                if (game->GetColorTour() == Color::blanc){
                    ui->label_check->setText("Blancs échec");
                }
                else{
                    ui->label_check->setText("Noirs échec");
                }
            }

        }
        else{
            ui->label_check->setText("");
        }
    }
    //game->DisplayPlateau();
}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressed(event);
}





