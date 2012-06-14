
#include "general.h"

namespace chess {

coor::coor(int nx, int ny) : pos_x(nx), pos_y(ny){
  if(nx<0) pos_x=0;
  if(nx>chessboard_size-1) pos_x = chessboard_size-1;

  if(ny<0) pos_y=0;
  if(ny>chessboard_size-1) pos_y = chessboard_size-1;
}

int coor::x() {return pos_x;}
int coor::y() {return pos_y;}

}
