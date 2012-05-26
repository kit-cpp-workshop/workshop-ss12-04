#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"

namespace game {

/* Diese Klasse enthält das Spielbrett als Figuren-Array und dient zum durchführen der Züge.
Da dies die einzige erlaubte Manipulation ist, sind nicht mehr Befehle dafür vorhanden.
*/
class chessboard
{
    public:
        chessboard();
        ~chessboard();
        // int wegen "Alles OK", "Ungültiger Zug" und "Gewonnen"
        int move(bool player_color, coord from, coord to);

        // zur Darstellung:
        int getID(coor field); //gibt ID zurück
        bool getcolor(coor field);
    protected:
    private:
        piece[chessboard_size][chessboard_size];
};


}
#endif // CHESSBOARD_H
