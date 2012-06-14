#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "general.h"
#include "game/piece.h"
#include "game/chessboard.h"
#include "ui/userinterface.h"

namespace chess{

/* Die Klasse für das gesamte Schachspiel. */

class chessgame
{
    public:
        /* Konstruktor erzeugt ein chessboard */
        chessgame(ui::UserInterface* Interface);

        /* Destruktor, löscht Brett. */
        ~chessgame();

        void run(); // hier drin steckt der Spielablauf: Abwechselnd weiß und schwarz ziehen, bis König geschlagen.
    protected:
    private:
        color current_player;
        game::chessboard* Spielbrett;
        ui::UserInterface* iface;
};


}
#endif // CHESSGAME_H
