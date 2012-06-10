#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "general.h"
#include "game/piece.h"

namespace chess{

/* Die Klasse für das gesamte Schachspiel. */

class chessgame
{
    public:
        /* Konstruktor erzeugt ein chessboard */
        chessgame();

        /* Destruktor, löscht Brett. */
        ~chessgame();

        void run(); // hier drin steckt der Spielablauf: Abwechselnd weiß und schwarz ziehen, bis König geschlagen.
    protected:
    private:

        color current_player;
};


}
#endif // CHESSGAME_H
