#include "piece.h"

namespace chess {
namespace game {

piece::piece(color playercolor) {
    player = playercolor;
}

piece::piece(){
    player = white;
}

bool piece::possible_move(coor from, coor to, piece*** spielfeld) {
    return false;
}

color piece::GetColour() {
    return player;
}

bool piece::check_line(coor from, coor to, piece*** spielfeld) {

    return false;
}

}
}

