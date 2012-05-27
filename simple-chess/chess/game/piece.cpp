#include "piece.h"

namespace chess {
namespace game {

piece::piece(bool piece_colour) {
    colour = piece_colour;
}

piece::piece(){
    //ctor
}

piece::~piece(){
    //dtor
}

int piece::getID(){
    return 0;
}

bool piece::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
    //ctor
}

namespace pieces {

int bauer::getID() {return id_bauer;}
int laeufer::getID() {return id_laeufer;}
int springer::getID() {return id_springer;}
int turm::getID() {return id_turm;}
int dame::getID() {return id_dame;}
int koenig::getID() {return id_koenig;}
int none::getID() {return id_none;}


bool bauer::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool laeufer::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool springer::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool turm::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool dame::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool koenig::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

bool none::possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]) {
    return false;
}

}

}
}

