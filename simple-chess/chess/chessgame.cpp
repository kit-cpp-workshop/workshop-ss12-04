#include "chessgame.h"

namespace chess{

chessgame::chessgame(ui::UserInterface *Interface){
  Spielbrett = new game::chessboard();
  current_player = white;
  iface = Interface;
}

chessgame::~chessgame(){
  delete Spielbrett;
}

void chessgame::run(){
  iface->draw_board(*Spielbrett);

  game::move* nextMove;

  while(true) {
    // Zug einlesen...
    nextMove = iface->read_move(current_player, *Spielbrett);
    // bis gültiger Zug
    if(!Spielbrett->ApplyMove(*nextMove)) continue;

    //Dann Farbe wechseln:
    if(current_player==white)
      current_player=black;
    else
      current_player=white;

    // und von vorne ...

    // Ein- und Ausgabe natürlich noch Ausbaufähig ...
  }





}


}
