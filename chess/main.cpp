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

    Game g;


    g.blanc.ShowPieces();
    //Player p(Color::blanc);

    //Piece* piece = p.GetPiece(0);

    //piece->Mouvement(1,1);

    //p.ShowPieces();
    //Piece pion = new Pion(TypePiece.pion, 1, 1, Color.white);

    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
