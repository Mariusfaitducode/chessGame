#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



    Game game;

    game.InitPlateau(scene);

    game.InstallPieces(scene);

    //connect(scene, &ChessScene::sceneClicked, this, &MainWindow::onSceneClicked);

    connect(scene, SIGNAL(mousePressed()), SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::onSceneClicked(QGraphicsSceneMouseEvent *event)
{
    // Récupérer les coordonnées de la case dans laquelle l'utilisateur a cliqué
    int x = event->scenePos().x() / SQUARE_SIZE;
    int y = event->scenePos().y() / SQUARE_SIZE;

    // Afficher les coordonnées dans la console
    //qDebug() << "Case cliquée : (" << x << ", " << y << ")";
}*/

void MainWindow::mousePressEvent(QMouseEvent * e)

{

    QPointF pt = ui->graphicsView->mapToScene(e->pos());//récupération de la position

    int pressedX=pt.x();                                                           //adaptation à la position : pressedX

    int pressedY=pt.y();                                                         //adaptation à la position : pressedY


    std::cout << "X : " << pressedX ;
    std::cout << "Y : " << pressedY ;

    //qDebug() << "Case cliquée : (" << x << ", " << y << ")";

    emit mousePressed();                                                      //émission du signal pour déclencher le slot
}
