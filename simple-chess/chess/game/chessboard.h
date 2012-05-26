#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"

namespace game {

class chessboard
{
    public:
        chessboard();
        ~chessboard();
        // eigentlich könnte man auch Code von der piece-Klasse hierher übernehmen ...
        bool move(bool player_color, coord from, coord to);
    protected:
    private:
        piece[chessboard_size][chessboard_size];
};


}
#endif // CHESSBOARD_H
