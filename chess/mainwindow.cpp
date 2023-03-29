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



    game = new Game();

    game->InitPlateau(scene);

    game->InstallPieces(scene);



    //connect(scene, &ChessScene::sceneClicked, this, &MainWindow::onSceneClicked);

    connect(scene, &ChessScene::mousePressed, this, &MainWindow::onSceneClicked);

    //QObject::connect(this, SIGNAL(mousePressed()), SLOT(placerPionBleu()));

    //connect(scene, mousePressed(), this, &MainWindow::mousePressEvent);
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

        //std::vector<Vector2> coups = clickedCase->Mouvement()

        game->FirstClickedPiece(scene, clickedCase);
    }
    else{
        //erase click
        game->RemoveCoups(scene);

    }


}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressed(event);
}

/*
void ChessScene::clearHighlights()
{
    // Parcours tous les éléments de la scène
    QList<QGraphicsItem *> itemsList = items();
    for (QGraphicsItem *item : itemsList) {
        // Si l'élément est un cercle de highlight, on le supprime
        if (item->data(HighlightRole) == true) {
            removeItem(item);
            delete item;
        }
    }
}*/



/*
void MainWindow::mousePressEvent(QMouseEvent * e)

{

    QPointF pt = ui->graphicsView->mapToScene(e->pos());//récupération de la position

    int pressedX=pt.x();                                                           //adaptation à la position : pressedX

    int pressedY=pt.y();                                                         //adaptation à la position : pressedY


    std::cout << "X : " << pressedX ;
    std::cout << "Y : " << pressedY ;

    //qDebug() << "Case cliquée : (" << x << ", " << y << ")";

    emit mousePressed();                                                      //émission du signal pour déclencher le slot
}*/
