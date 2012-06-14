#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "../general.h"
#include "../game/piece.h"

namespace chess {
namespace ui {

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        virtual void draw_board(game::chessboard &Spielbrett) = 0; /* Stellt das Schachbrett dar */

        /* Holt sich die Koordinaten für den nächsten Zug des entsprechenden Spielers
         in "from" und "to" */
        virtual game::move* read_move(color player_color, game::chessboard &Spielbrett) = 0;

        /* Ausgabe von Informationen */
        virtual void print_error_message(int error_id) = 0;
        virtual void print_info_message(int info_id) = 0;
};

}
}
#endif // USERINTERFACE_H
