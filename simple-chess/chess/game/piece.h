#ifndef PIECE_H
#define PIECE_H

#include "../general.h"
#include "./chessboard.h"
#include <cmath>

namespace chess{
namespace game {

class chessboard;

class piece
{
    public:
        /* Default-Konstruktor, für initialisierung des Spielfelds benötigt.
        Daher ist diese Klasse auch nicht rein virtuell.
        Generell bezeichnet `piece` eine nicht vorhandene Figur, also ein leeres Feld. */
        piece();
        virtual ~piece(){};
        /* Überprüfung, ob ein Bewegen rein geometrisch von "from" nach "to"
        auf dem übergebenem Array möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell `check_line` auf, um zu testen, ob was im Weg steht */
        virtual bool possible_move(coor, coor, chessboard);

        color GetColour();
        virtual chesspiece GetPiece();
    protected:
        color player; //Die Farbe der Figur

        //Werden von `possible_move` von Dame, Läufer und Turm gebraucht:
        bool check_line(coor from, coor to, chessboard &spielfeld);

};

namespace pieces {

class none : public piece {
    public:
        none(color playercolor);
        bool possible_move(coor, coor, chessboard);
        chesspiece GetPiece();
};


class pawn : public piece {
    public:
        pawn(color playercolor);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class rook : public piece {
    public:
        rook(color playercolor);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class knight : public piece {
    public:
        knight(color playercolor);
        bool possible_move(coor from, coor to, chessboard);
        chesspiece GetPiece();
};


class bishop : public piece {
    public:
        bishop(color playercolor);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class queen : public piece {
    public:
        queen(color playercolor);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class king : public piece {
    public:
        king(color playercolor);
        bool possible_move(coor from, coor to, chessboard);
        chesspiece GetPiece();
};


}
}
}
#endif // PIECE_H
