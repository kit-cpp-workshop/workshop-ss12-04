#ifndef PIECE_H
#define PIECE_H

#include "../general.h"

namespace chess{
namespace game {

class piece
{
    public:
        piece(); // Default-Konstruktor, für initialisierung des Spielfelds benötigt.
        piece(bool piece_colour); // Figur mit Farbe erzeugen
        ~piece();

        /* Überprüfung, ob ein Bewegen rein geometrisch von "from" nach "to" auf dem Spielfeld "board" möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell check_diagonal oder check_linear auf, um zu testen, ob was im Weg steht */
        virtual bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

        // Ausgabe zur Darstellung:
        virtual int getID();
        bool getcolour();

    protected:
        bool colour;

        //Werden von "possible_move" von Dame, Läufer und Turm gebraucht, benutzt chessboard.occupied:
        bool check_linear(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);
        bool ckeck_diagonal(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

namespace pieces {

class bauer : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class laeufer : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class springer : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class dame : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class koenig : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class none : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};

class turm : public piece {
    int getID();
    bool possible_move(coor from, coor to, piece spielfeld[chessboard_size][chessboard_size]);

};


}

}
}
#endif // PIECE_H
