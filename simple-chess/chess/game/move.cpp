#include "move.h"


namespace chess {
namespace game {

void move_chain::Append(move_chain* move_object, bool last){
  // Wenn noch kein weiterer Zug dran hängt, einfach dazu hängen:
  if(PreviousMove==0)
    PreviousMove = move_object;
  // Wenn schon einer dran hängt:
  else {
    // Wenn der neue Zug nach hinten soll, das Objekt an das schon angehängte Objekt weiterreichen.
    if(last)
      PreviousMove->Append(move_object, last);
    // ansonsten die vorhandenen Züge an das neue Objekt hängen und dieses als nächsten Zug setzen.
    else {
      move_object->Append(PreviousMove,last);
      PreviousMove = move_object;
    }
  }
}

// Destruktor:
move_chain::~move_chain() {
  if(PreviousMove!=0)
    delete PreviousMove;
}

// Konstruktoren:
move::move(coor from, coor to, color player) : source(from), dest(to), playercolor(player){
  PreviousMove=0;
}

remove::remove(coor field) : chessfield(field) {
  PreviousMove=0;
}

insert::insert(coor field, piece &figur) : chessfield(field), chessfigure(&figur) {
  PreviousMove=0;
}

//Apply-Funktionen: Wenn vorhanden, erst angehängten Zug anwenden.
void move::Apply(piece* spielfeld[chessboard_size][chessboard_size], piece *nonepiece){
  if(PreviousMove!=0) PreviousMove->Apply(spielfeld, nonepiece);
  spielfeld[dest.x()][dest.y()]=spielfeld[source.x()][source.y()];
  spielfeld[source.x()][source.y()]=nonepiece;
}

void remove::Apply(piece* spielfeld[chessboard_size][chessboard_size], piece *nonepiece){
  if(PreviousMove!=0) PreviousMove->Apply(spielfeld, nonepiece);
  delete spielfeld[chessfield.x()][chessfield.y()];
  spielfeld[chessfield.x()][chessfield.y()]=nonepiece;
}

void insert::Apply(piece* spielfeld[chessboard_size][chessboard_size], piece *nonepiece){
  if(PreviousMove!=0) PreviousMove->Apply(spielfeld, nonepiece);
  spielfeld[chessfield.x()][chessfield.y()]=chessfigure;
}

// Das wichtigste: die Check-Funktion:
/* Überprüft den Zug, ob Start- und Endfeld auf dem Spielfeld möglich sind
und ob es sich um einen besonderen Zug handelt.
Prüft, ob Figurenregeln zutreffen.
Beim Schlagen oder bei besonderen Zügen (z.B. Rochade) werden
die zusätzlichen Züge (Figur vom Spielfeld nehmen usw... ) dem Zug hinzugefügt,
sodass schließlich alle Informationen des Zuges enthalten sind.
Da über die `chessboard`-Klasse nur abfragen möglich sind, ist noch keine Manipulation möglich. */
bool move::CheckMove(chessboard &spielfeld) {

  // stimmt die Farbe beim Startfeld?:
  bool colorcheck = (spielfeld.GetPiece(source)->GetPiece()!=none) && (spielfeld.GetPiece(source)->GetColour() == playercolor);

  // stimmt das Zielfeld und wird geschlagen?
  bool targetcheck, throwfigure;
  if(spielfeld.GetPiece(dest)->GetPiece()!=none){
    if(spielfeld.GetPiece(dest)->GetColour()!=playercolor)
      throwfigure = targetcheck = true;
    else
      throwfigure = targetcheck = false;
  }
  else {
    throwfigure = false;
    targetcheck = true;
  }

  // ist der Zug geometrisch möglisch?
  bool geometrycheck = spielfeld.GetPiece(source)->possible_move(source,dest,spielfeld);

  // Abbrechen, wenn eine Bedingung nicht erfüllt:
  if(!colorcheck || !targetcheck || !geometrycheck) return false;

  // Beim Schlagen noch einen `remove`-Befehl anhängen:
  if(throwfigure){
    remove* destremove = new remove(dest);
    this->Append(destremove);
  }
  return true;
}



}
}
