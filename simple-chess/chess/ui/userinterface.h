#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "../general.h"

namespace chess {
namespace ui {

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        virtual void draw_board(chessboard board); /* Stellt das Schachbrett dar */

        /* Holt sich die Koordinaten für den nächsten Zug des entsprechenden Spielers
         in "from" und "to" */
        virtual void read_move(bool player_color, coor &from, coor &to);

        /* Ausgabe von Informationen */
        virtual void print_error_message(int error_id);
        virtual void print_info_message(int info_id);
};

}
}
#endif // USERINTERFACE_H
