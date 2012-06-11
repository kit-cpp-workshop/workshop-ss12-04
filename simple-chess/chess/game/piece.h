#ifndef PIECE_H
#define PIECE_H

#include "../general.h"

namespace chess{
namespace game {

class piece
{
    public:
        /* Default-Konstruktor, für initialisierung des Spielfelds benötigt.
        Daher ist diese Klasse auch nicht rein virtuell. */
        piece();

        piece(color player); // Figur mit Farbe erzeugen

        /* Überprüfung, ob ein Bewegen rein geometrisch von "from" nach "to"
        auf dem übergebenem Array möglich ist.
        Für jede Figur verschieden.
        Ruft eventuell check_diagonal oder check_linear auf, um zu testen, ob was im Weg steht */
        virtual bool possible_move(coor from, coor to, chessboard &spielfeld);

        color GetColour();

    protected:
        color player; //Die Farbe der Figur

        //Werden von "possible_move" von Dame, Läufer und Turm gebraucht:
        bool check_line(coor from, coor to, chessboard &spielfeld);

};

}
}
#endif // PIECE_H
