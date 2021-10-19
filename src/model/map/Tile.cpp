#include "Tile.h"

bool Tile::isBreakable(Tile tile) {
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
    }


}

