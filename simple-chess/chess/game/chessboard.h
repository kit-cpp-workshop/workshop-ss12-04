#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"

namespace chess{
namespace game {

/* Diese Klasse enthält das Spielbrett als Figuren-Array und dient zum durchführen der Züge.
Da dies die einzige erlaubte Manipulation ist, sind nicht mehr Befehle dafür vorhanden.
*/
class chessboard
{
    public:
        chessboard(); /* Füllt das Schachbrett mit der Startaufstellung */
        ~chessboard();

        /* Methode, um eine Figur des Spielers "player_color" zu bewegen.
        Prüft, ob "from" eine eigene figur und "to" nicht mit einer eigenen Figur belegt ist.
        Anschließend wird die "move"-Methode der Figur auf dem Feld aufgerufen, um die geometrische Richtigkeit des Zuges zu überprüfen.
        Wenn der zug möglich ist, so wird dieser durchgeführt.
        int-Return-Wert wegen "Alles OK", "Ungültiger Zug" und "Gewonnen". */
        int move(bool player_color, coor from, coor to);

        // zur Darstellung:
        int getID(coor field); //gibt ID zurück
        bool getcolor(coor field);

        bool occupied(coor field); // Zum testen, ob da eine Figur steht.
    protected:
    private:
        piece spielfeld[chessboard_size][chessboard_size];
};


}
}
#endif // CHESSBOARD_H
