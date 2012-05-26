#ifndef PIECE_H
#define PIECE_H

#include "../general.h"

namespace chess{
namespace game {

class piece
{
    public:
        piece(bool piece_colour); // Figur mit Farbe erzeugen
        virtual ~piece();

        /* Überprüfung, ob ein Bewegen von "from" nach "to" möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell check_diagonal oder check_linear auf */
        virtual bool possible_move(coord from, coord to, chessboard &board);

        // Ausgabe zur Darstellung:
        virtual int GetID();
        bool getcolour();

    protected:
        bool colour;

        //Werden von "possible_move" von Dame, Läufer und Turm gebraucht:
        bool check_linear(coord from, coord to, chessboard &board);
        bool ckeck_diagonal(coord from, coord to, chessboard &board);

};

class piece_bauer : public piece {
    int GetID();
    bool possible_move(coord from, coord to, chessboard &board);

};

}
}
#endif // PIECE_H
