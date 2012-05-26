#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

// General needed things

struct coor {
    int x;
    int y;
};

// Damit man sich das nicht merken muss:
const bool color_white = true;
const bool color_black = false;

const unsigned int chessboard_size = 8;

const unsigned int id_none = 0;
const unsigned int id_bauer = 1;
const unsigned int id_springer = 2;
const unsigned int id_laeufer = 3;
const unsigned int id_turm = 4;
const unsigned int id_dame = 5;
const unsigned int id_koenig = 6;

#endif // GENERAL_H_INCLUDED
