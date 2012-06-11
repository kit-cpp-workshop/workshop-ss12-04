#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

// General needed things
namespace chess {


struct coor {
    int x;
    int y;
};

// Damit man sich das nicht merken muss:
enum color {white, black};
enum chesspiece {none, pawn, rook, knight, bishop, queen, king};

const unsigned int chessboard_size = 8;

}
#endif // GENERAL_H_INCLUDED
