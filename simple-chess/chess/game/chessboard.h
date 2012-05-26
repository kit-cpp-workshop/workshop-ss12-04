#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"

namespace game {

/* Diese Klasse enthält das Spielbrett als Figuren-Array und dient zum durchführen der Züge.
Da dies die einzige erlaubte manipulation ist, sind nicht mehr Befehle vorhanden.
*/
class chessboard
{
    public:
        chessboard();
        ~chessboard();
        // eigentlich könnte man auch Code von der piece-Klasse hierher übernehmen ...
        int move(bool player_color, coord from, coord to);
    protected:
    private:
        piece[chessboard_size][chessboard_size];
};


}
#endif // CHESSBOARD_H
