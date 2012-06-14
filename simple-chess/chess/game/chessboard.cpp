#include "chessboard.h"

namespace chess{
namespace game {

chessboard::chessboard(){
  NullFigure = new pieces::none(white);
  this->setStartPosition();
}

chessboard::~chessboard(){
  this->cleanBoard();
  delete NullFigure;
}

piece chessboard::GetPiece(coor position) {
  return *spielfeld[position.x()][position.y()];
}

bool chessboard::ApplyMove(move &Zug){
  if(!Zug.CheckMove(*this)) return false;
  Zug.Apply(spielfeld,NullFigure);
  return true;
}

// Löscht in einer Schleife alle Figuren auf dem Brett
void chessboard::cleanBoard(){
  for(int ix=0;ix<chessboard_size;ix++) {
    for(int iy=0;iy<chessboard_size;iy++) {
      if(spielfeld[ix][iy]!=0) {
        delete spielfeld[ix][iy];
        spielfeld[ix][iy]=0;
      }
    }
  }
}

// Stellt die Startaufstellung her
void chessboard::setStartPosition(){
  //zur Sicherheit:
  this->cleanBoard();

  color currentColor=white;

  for(int ix=0;ix<chessboard_size;ix++) {
    for(int iy=0;iy<chessboard_size;iy++) {

      //Farbe:
      if(iy < 2) currentColor=white;
      if(iy > chessboard_size-3) currentColor=black;

      //Nicht-Figuren:
      if((iy>1) && (iy < chessboard_size-2))
        spielfeld[ix][iy] = NullFigure;

      // Bauern:
      if((iy==1) || (iy == chessboard_size-2))
        spielfeld[ix][iy] = new pieces::pawn(currentColor);

      // Grundlinien:
      if((iy==1)||(iy==chessboard_size-1)) {

        //Türme:
        if((ix==1)||(ix==chessboard_size-1))
          spielfeld[ix][iy] = new pieces::rook(currentColor);

        //Springer:
        if((ix==2)||(ix==chessboard_size-2))
          spielfeld[ix][iy] = new pieces::knight(currentColor);

        //Läufer:
        if((ix==3)||(ix==chessboard_size-3))
          spielfeld[ix][iy] = new pieces::bishop(currentColor);

        //Dame:
        if(ix==4)
          spielfeld[ix][iy] = new pieces::queen(currentColor);

        //Dame:
        if(ix==chessboard_size-4)
          spielfeld[ix][iy] = new pieces::king(currentColor);
      }
    }
  }
}

}
}
