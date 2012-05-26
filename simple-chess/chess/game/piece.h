#ifndef PIECE_H
#define PIECE_H

#include "../general.h"

namespace game {

class piece
{
    public:
        piece(bool piece_colour); // Figur mit Farbe
        virtual ~piece();
        int move(coord from, coord to, chessboard &board);
        virtual int GetID();
        //virtual void remove(); // Aktionen auslösen beim besiegen von Figuren, wie z.B. dem König
    protected:
    private:
        bool colour;
        bool check_source_field(coord from);
        bool check_target_field(coord to);

        // Unterschiedlich für verschiedene Figuren:
        virtual bool check_geometrical_possible(coord from, coord to);

        //Werden von Dame, Läufer und Turm gebraucht:
        bool check_linear(coord from, coord to);
        bool ckeck_diagonal(coord from, coord to);

};



}
#endif // PIECE_H
