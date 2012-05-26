#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
#include "../general.h"

namespace game {

const int chessboard_size = 8;

class chessboard
{
    public:
        chessboard();
        ~chessboard();
        // eigentlich könnte man auch Code von der piece-Klasse hierher übernehmen ...
        bool move(coord from, coord to);
    protected:
    private:
        piece[chessboard_size][chessboard_size];
};


}
#endif // CHESSBOARD_H
