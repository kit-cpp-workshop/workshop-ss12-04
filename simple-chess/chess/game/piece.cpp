#include "piece.h"

namespace chess {
namespace game {

//piece::piece(color playercolor) {player = playercolor;}
piece::piece(){player = white;}
bool piece::possible_move(coor from, coor to, chessboard &spielfeld) {return false;}
color piece::GetColour() {return player;}
chesspiece piece::GetPiece() {return chess::none;}

// Funktion, die von anderen verwendet wird:
bool piece::check_line(coor from, coor to, chessboard &spielfeld) {
  int delta_x=std::abs(to.x() - from.x());
  int delta_y=std::abs(to.y() - from.y());

  // Schritte in positiver oder negativer Richtung:
  int dx = delta_x==0 ? 0 : delta_x / (to.x() - from.x());
  int dy = delta_y==0 ? 0 : delta_y / (to.y() - from.y());

  // Abbrechen, wenn nicht Linie oder Diagonale:
  if(!((delta_x==delta_y) || ((delta_y!=0) && (delta_x==0))) || ((delta_x!=0) && (delta_y == 0))) return false;

  // Alle Felder dazwischen prüfen:
  for(int ix=from.x()+dx; ix<= to.x()-dx; ix+=dx) {
    for(int iy=from.y()+dy; iy<= to.y()-dy; iy+=dy) {
      // Zug nicht möglich, wenn Figur im Weg steht.
      coor position(ix,iy);
      if(spielfeld.GetPiece(position).GetPiece()!=chess::none) return false;
    }
  }
  return true;
}

namespace pieces {

// Konstruktoren:
none::none(color playercolor) {player = playercolor;}
pawn::pawn(color playercolor) {player = playercolor;}
rook::rook(color playercolor) {player = playercolor;}
knight::knight(color playercolor) {player = playercolor;}
bishop::bishop(color playercolor) {player = playercolor;}
queen::queen(color playercolor) {player = playercolor;}
king::king(color playercolor) {player = playercolor;}

// Objektabfragen:
chesspiece none::GetPiece() {return chess::none;}
chesspiece pawn::GetPiece() {return chess::pawn;}
chesspiece rook::GetPiece() {return chess::rook;}
chesspiece knight::GetPiece() {return chess::knight;}
chesspiece bishop::GetPiece() {return chess::bishop;}
chesspiece queen::GetPiece() {return chess::queen;}
chesspiece king::GetPiece() {return chess::king;}

// Überprüfungen:
bool none::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}

bool pawn::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}

bool rook::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}

bool knight::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}

bool bishop::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}


bool queen::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}

bool king::possible_move(coor from, coor to, chessboard &spielfeld) {
  return false;
}


}
}
}

