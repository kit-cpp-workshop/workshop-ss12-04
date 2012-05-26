#ifndef PIECE_H
#define PIECE_H

#include "../general.h"
#include "chessboard.h"

namespace chess{
namespace game {

class piece
{
    public:
        piece(bool piece_colour); // Figur mit Farbe erzeugen
        piece(); // Default-Konstruktor, für initialisierung des Spielfelds benötigt.
        virtual ~piece();

        /* Überprüfung, ob ein Bewegen rein geometrisch von "from" nach "to" auf Brett "board" möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell check_diagonal oder check_linear auf, um zu testen, ob was im Weg steht */
        virtual bool possible_move(coor from, coor to, chessboard &board);

        // Ausgabe zur Darstellung:
        virtual int GetID();
        bool getcolour();

    protected:
        bool colour;

        //Werden von "possible_move" von Dame, Läufer und Turm gebraucht, benutzt chessboard.occupied:
        bool check_linear(coor from, coor to, chessboard &board);
        bool ckeck_diagonal(coor from, coor to, chessboard &board);

};

namespace pieces {

class bauer : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};

class laeufer : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};

class springer : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};

class dame : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};

class koenig : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};

class none : public piece {
    int GetID();
    bool possible_move(coor from, coor to, chessboard &board);

};


}

}
}
#endif // PIECE_H
