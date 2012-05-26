#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "general.h"
#include "game/chessboard.h"

namespace chess{

/* Die Klasse für das gesamte Schachspiel. */

class chessgame
{
    public:
        chessgame(); /* Konstruktor erzeugt ein chessboard */
        ~chessgame();
        void run(); // hier drin steckt der Spielablauf: Abwechselnd weiß und schwarz ziehen, bis König geschlagen.
    protected:
    private:
        bool current_player_color;
};


}
#endif // CHESSGAME_H
