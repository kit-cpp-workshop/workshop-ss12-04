#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

// General needed things
namespace chess {

/* Klasse zum Verwalten der Koordinaten, x und y immer zwischen 0 und chessboard_size */
class coor {
public:
  coor(int nx, int ny);
  int x();
  int y();
private:
    int pos_x;
    int pos_y;
};

// Damit man sich das nicht merken muss:
enum color {white, black};
enum chesspiece {none, pawn, rook, knight, bishop, queen, king};

const int chessboard_size = 8;

}
#endif // GENERAL_H_INCLUDED
