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
        bool getcolour();

    protected:
        bool colour;

        // Unterschiedlich für verschiedene Figuren:
        virtual bool check_geometrical_possible(coord from, coord to);

        //Werden von obriger Funktion von Dame, Läufer und Turm gebraucht:
        bool check_linear(coord from, coord to);
        bool ckeck_diagonal(coord from, coord to);

};

class piece_bauer : public piece {
    int GetID();
    bool check_geometrical_possible(coord from, coord to);

};

}
#endif // PIECE_H
