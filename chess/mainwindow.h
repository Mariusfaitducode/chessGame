#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include <game.h>

#include "QMouseEvent"
#include "qgraphicssceneevent.h"



//Scene de notre plateau + Gestion des clicks


class ChessScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ChessScene(QObject* parent = nullptr) : QGraphicsScene(parent) {}
    void clearHighlights();
    //void highlightSquares(std::vector<Vector2> coups);

signals:
    //void sceneClicked(QPointF point);
    void mousePressed(QGraphicsSceneMouseEvent* event);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};



//Fenetre

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onSceneClicked(QGraphicsSceneMouseEvent *event);
    //void mousePressEvent(QMouseEvent * e);

signals:
    //void mousePressed();

private:
    Ui::MainWindow *ui;
    ChessScene *scene;

    Game *game;
};




#endif // MAINWINDOW_H
