#include "piece.h"

namespace chess {
namespace game {

//piece::piece(color playercolor) {player = playercolor;}
//piece::piece(){player = white;}
//bool piece::possible_move(coor, coor, chessboard) {return false;}
color piece::GetColour() {return player;}
//chesspiece piece::GetPiece() {return chess::none;}

// Funktion, die von anderen verwendet wird:
bool piece::check_line(coor from, coor to, chessboard &spielfeld) {
  int delta_x=std::abs(to.x() - from.x());
  int delta_y=std::abs(to.y() - from.y());

  // Schritte in positiver oder negativer Richtung:
  int dx = delta_x==0 ? 0 : delta_x / (to.x() - from.x());
  int dy = delta_y==0 ? 0 : delta_y / (to.y() - from.y());

  // Abbrechen, wenn keine Bewegung:
  if((dx==0)&&(dy==0)) return false;

  // Abbrechen, wenn nicht Linie oder Diagonale:
  if(!((delta_x==delta_y) || ((delta_y!=0) && (delta_x==0))) || ((delta_x!=0) && (delta_y == 0))) return false;

  // Alle Felder dazwischen prüfen:
  for(int ix=from.x()+dx; ix<= to.x()-dx; ix+=dx) {
    for(int iy=from.y()+dy; iy<= to.y()-dy; iy+=dy) {
      // Zug nicht möglich, wenn Figur im Weg steht.
      coor position(ix,iy);
      if(spielfeld.GetPiece(position)->GetPiece()!=chess::none) return false;
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
bool none::possible_move(coor, coor, chessboard&) {
  return false;
}

bool pawn::possible_move(coor from, coor to, chessboard &spielfeld) {

  // Steht der Bauer noch auf der Grundlinie?
  bool grundlinie = (((player==white) && (from.y() == 1)) || ((player==black) && (from.y() == chessboard_size - 2)));

  //noch kein en passant ...

  // wo ist "vorne"?
  int dy = ((player==white) ? 1 : -1);

  // Schlägt der Bauer eine Figur?
  bool schlagen = (spielfeld.GetPiece(to)->GetPiece()!=chess::none);
  // dann nur diagonal nach vorne.
  bool diagonal = ((to.y() - from.y()) == dy) && (std::abs(to.x() - from.x()) == 1);
  if(schlagen && !diagonal) return false;

  //beim nicht schlagen, von grundlinie 2, sonst 1 geradeaus:
  bool geradeaus = (to.y() - from.y() == dy);
  if(grundlinie)
    geradeaus |= (to.y() - from.y() == dy*2);

  //Geradeaus heißt, nicht rechts oder links:
   geradeaus &= (std::abs(to.x() - from.x()) == 0);

  if(!schlagen && !geradeaus) return false;

  return true;
}

bool rook::possible_move(coor from, coor to, chessboard &spielfeld) {

  // nur geradlinig bewegen:
  bool geradlinig = (from.x()-to.x() == 0) || (from.y()-to.y() == 0);
  if(!geradlinig) return false;

  //keine Figur dazwischen:
  if(!check_line(from, to, spielfeld)) return false;

  return true;
}

bool knight::possible_move(coor from, coor to, chessboard&) {

  // nur "über eck", wenn dx^2 + dy^2 == 5 ist:
  bool eck = std::pow(to.x() - from.x(),2) + std::pow(to.y() - from.y(),2) == 5;
  if(!eck) return false;

  return true;
}

bool bishop::possible_move(coor from, coor to, chessboard &spielfeld) {

  // nur diagonal bewegen:
  bool diagonal = (std::abs(from.x()-to.x()) == std::abs(from.y()-to.y()));
  if(!diagonal) return false;

  //keine Figur dazwischen:
  if(!check_line(from, to, spielfeld)) return false;

  return true;
}


bool queen::possible_move(coor from, coor to, chessboard &spielfeld) {

  //diagonal und linear, keine Figur dazwischen:
  if(!check_line(from, to, spielfeld)) return false;

  return true;
}

bool king::possible_move(coor from, coor to, chessboard &) {

  // nur ein Feld bewegen:
  int distance = std::pow(to.x() - from.x(),2) + std::pow(to.y() - from.y(),2);
  bool einfeld =  (distance== 1) || (distance==2);
  if(!einfeld) return false;

  return true;
}


}
}
}

