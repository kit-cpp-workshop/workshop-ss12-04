#include "userinterface.h"

namespace chess {
namespace ui {

namespace uis{

CommandLine::CommandLine(){
  std::cout <<
          "Welcome to CHESS" << std::endl <<
          " by Christian Buntin" << std::endl <<
          "  and with ideas from others ..." << std::endl <<
          "----------------------------------" << std::endl << std::endl;
}

CommandLine::~CommandLine(){
  std::cout << std::endl << std::endl <<
          "Thanks for playing CHESS" << std::endl <<
          " bye!" << std::endl;
}

coor CommandLine::char2coor(char input[2]) {
  input[0] = std::tolower(input[0]);

  coor target(input[0]-'a',input[1]-'1');

  return target;
}

game::move* CommandLine::read_move(color player_color){
  if(player_color==white)
    std::cout << "Spieler Weiß, bitte Zug eingeben: " << std::flush;
  else
    std::cout << "Spieler Schwarz, bitte Zug eingeben: " << std::flush;

  char from[2], to[2];

  std::cin >> from >> to;

  return new game::move(char2coor(from),char2coor(to),player_color);
}


void CommandLine::draw_board(game::chessboard &Spielbrett) {
  for(int iy=chessboard_size-1;iy>=0;iy--) {
    for(int ix=0;ix<chessboard_size;ix++) {
      coor Position(ix,iy);
      if(Spielbrett.GetPiece(Position)->GetColour()==white) {
        switch(Spielbrett.GetPiece(Position)->GetPiece()){
          case none:
            std::cout << "."; break;
          case pawn:
            std::cout << "P"; break;
          case rook:
            std::cout << "R"; break;
          case knight:
            std::cout << "N"; break;
          case bishop:
            std::cout << "B"; break;
          case queen:
            std::cout << "Q"; break;
          case king:
            std::cout << "K"; break;
        }
      } else {
        switch(Spielbrett.GetPiece(Position)->GetPiece()){
          case none:
            std::cout << "."; break;
          case pawn:
            std::cout << "p"; break;
          case rook:
            std::cout << "r"; break;
          case knight:
            std::cout << "n"; break;
          case bishop:
            std::cout << "b"; break;
          case queen:
            std::cout << "q"; break;
          case king:
            std::cout << "k"; break;
        }

      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
}
}
}
