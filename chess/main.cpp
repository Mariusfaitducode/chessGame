#include <iostream>

using namespace std;

#include <piece.h>
#include <pieces\pion.h>
#include <player.h>
#include <enum.h>

int main()
{
    cout << "Chess Game !" << endl;

    Player p(Color::blanc);

    //Piece* piece = p.GetPiece(0);

    //piece->Mouvement(1,1);

    p.ShowPieces();
    //Piece pion = new Pion(TypePiece.pion, 1, 1, Color.white);



    return 0;
}
