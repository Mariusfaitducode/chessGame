#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}
