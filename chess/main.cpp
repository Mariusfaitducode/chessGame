#include <iostream>

using namespace std;

#include <piece.h>
#include <pieces\pion.h>
#include <player.h>
#include <enum.h>
#include <game.h>

#include <QApplication>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    cout << "Chess Game !" << endl;

    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
