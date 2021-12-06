#include "Tile.h"

/**bool Tile::isBreakable(Tile tile) {
    switch(tile){
        case "Floor":
            return false;
            break;
        case "Unbreakable_Wall":
            return false;
            break;
        case "Breakable_Wall":
            return true;
            break;
        default:
            break;
    }
}**/


void Tile::set_position(int x_, int y_) {
    x = x_;
    y = y_;
}

int Tile::get_y_position(){
    return y;
}

int Tile::get_x_position(){
    return x;
}

Tile::Tile(int x_, int y_) {
    x = x_;
    y = y_;
}

Tile::~Tile(){

}

