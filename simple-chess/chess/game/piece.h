#ifndef PIECE_H
#define PIECE_H

#include "../general.h"

namespace chess{
namespace game {

class piece
{
    public:
        /* Default-Konstruktor, für initialisierung des Spielfelds benötigt.
        Daher ist diese Klasse auch nicht rein virtuell.
        Generell bezeichnet `piece` eine nicht vorhandene Figur, also ein leeres Feld. */
        piece();

        /* Überprüfung, ob ein Bewegen rein geometrisch von "from" nach "to"
        auf dem übergebenem Array möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell `check_line` auf, um zu testen, ob was im Weg steht */
        virtual bool possible_move(coor from, coor to, chessboard &spielfeld);

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
        none(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class pawn : public piece {
    public:
        pawn(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class rook : public piece {
    public:
        rook(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class knight : public piece {
    public:
        knight(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class bishop : public piece {
    public:
        bishop(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class queen : public piece {
    public:
        queen(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


class king : public piece {
    public:
        king(color player);
        bool possible_move(coor from, coor to, chessboard &spielfeld);
        chesspiece GetPiece();
};


}
}
}
#endif // PIECE_H
