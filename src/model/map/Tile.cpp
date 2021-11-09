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


pair<int, int> Tile::setPosition(pair<int, int> position){
    pos=position;
}

pair<int, int> Tile::getPosition(){
    return pos;
}
