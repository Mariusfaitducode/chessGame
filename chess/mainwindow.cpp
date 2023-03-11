#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    const int SQUARE_SIZE = 99;
    const int BOARD_SIZE = 8;

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

MainWindow::~MainWindow()
{
    delete ui;
}
