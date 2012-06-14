#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"
#include "move.h"

namespace chess{
namespace game {


class move;
class piece;

/* Diese Klasse enthält das Spielbrett als Figuren-Array.
*/
class chessboard
{
    public:
        /* Konstruktor */
        chessboard();

        /* Löscht das Schachbrett und seine Figuren. */
        ~chessboard();

        /* Gibt die Figur an der Position zurück. */
        piece GetPiece(coor position);

        /* Wendet einen Zug an, damit nur `move` was ändern kann */
        bool ApplyMove(move &Zug);

    private:
        /* Das eigentliche Spielfeld, als Array von Figuren */
        game::piece* spielfeld[chessboard_size][chessboard_size];

        /* Füllt das Schachbrett mit der Startaufstellung oder löscht es */
        void setStartPosition();
        void cleanBoard();
        piece* NullFigure;

};


}
}
#endif // CHESSBOARD_H
