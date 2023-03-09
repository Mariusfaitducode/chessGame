#include "roi.h"

Roi::Roi(int l, int c, Color color) : Piece(l, c, color)
{
    _type = TypePiece::roi;
}

Roi::~Roi(){

}

void Roi:: Mouvement(int l, int c){
    std::cout << "Mouvement roi" << std::endl;
}
