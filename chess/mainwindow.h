#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include <game.h>

#include "QMouseEvent"

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
    //void onSceneClicked(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QMouseEvent * e);

signals:
    void mousePressed();

private:
    Ui::MainWindow *ui;
};




#endif // MAINWINDOW_H
