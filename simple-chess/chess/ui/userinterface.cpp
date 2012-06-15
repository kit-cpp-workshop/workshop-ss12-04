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
  std::cout << std::endl << "   A   B   C   D   E   F   G   H" << std::endl;
  std::cout <<              " ╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗ " << std::endl;

  for(int iy=chessboard_size-1;iy>=0;iy--) {
    std::cout << iy+1 << "║";
    for(int ix=0;ix<chessboard_size;ix++) {
      coor Position(ix,iy);
      std::cout << " ";
      if(Spielbrett.GetPiece(Position)->GetColour()==white) {
        switch(Spielbrett.GetPiece(Position)->GetPiece()){
          case none:
            std::cout << " "; break;
          case pawn:
            std::cout << "♙"; break;
          case rook:
            std::cout << "♖"; break;
          case knight:
            std::cout << "♘"; break;
          case bishop:
            std::cout << "♗"; break;
          case queen:
            std::cout << "♕"; break;
          case king:
            std::cout << "♔"; break;
        }
      } else {
        switch(Spielbrett.GetPiece(Position)->GetPiece()){
          case none:
            std::cout << " "; break;
          case pawn:
            std::cout << "♟"; break;
          case rook:
            std::cout << "♜"; break;
          case knight:
            std::cout << "♞"; break;
          case bishop:
            std::cout << "♝"; break;
          case queen:
            std::cout << "♛"; break;
          case king:
            std::cout << "♚"; break;
        }

      }
      if(ix<chessboard_size-1)
        std::cout << " │";
      else
        std::cout << " ";
    }
    std::cout << "║" << iy+1 << std::endl;
    if(iy > 0)
      std::cout << " ╟───┼───┼───┼───┼───┼───┼───┼───╢" << std::endl;
  }

  std::cout << " ╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝ " << std::endl;
  std::cout << "   A   B   C   D   E   F   G   H" << std::endl << std::endl;
}
}
}
}
