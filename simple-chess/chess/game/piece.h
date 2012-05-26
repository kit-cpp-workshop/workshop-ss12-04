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
        ruft die virtuelle Funktion "check_geometrical_possible" auf, die für jede Figur verschieden ist.
        Diese Funktion hier ist nicht virtuell zwecks einheitlicher Rückgabewerte. */
        int possible_move(coord from, coord to, chessboard &board);

        // Ausgabe zur Darstellung:
        virtual int GetID();
        bool getcolour();

    protected:
        bool colour;

        // Unterschiedlich für verschiedene Figuren:
        virtual bool check_geometrical_possible(coord from, coord to);

        //Werden von obriger Funktion von Dame, Läufer und Turm gebraucht:
        bool check_linear(coord from, coord to, chessboard &board);
        bool ckeck_diagonal(coord from, coord to, chessboard &board);

};

class piece_bauer : public piece {
    int GetID();
    bool check_geometrical_possible(coord from, coord to);

};

}
}
#endif // PIECE_H
