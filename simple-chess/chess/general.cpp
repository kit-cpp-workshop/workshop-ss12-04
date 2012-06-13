
#include "general.h"


coor::coor(int nx, int ny) {
  if(nx<0) x=0;
  if(nx>chessboard_size-1) x = chessboard_size-1;

  if(ny<0) y=0;
  if(ny>chessboard_size-1) y = chessboard_size-1;
}

int coor::x() {return x;}
int coor::y() {return y;}
