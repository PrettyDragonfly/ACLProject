#include "Floor.h"
#include <iostream>

bool Floor::is_walkable() {
    return true;
}

std::ostream &operator<<(std::ostream &os, const Floor& f) {
    os << "0  ";
    return os;
}

void Floor::show() {
    std::cout << "0  ";
}

Floor::Floor(int x, int y) : Tile(x, y){

}

bool Floor::is_floor() {
    return true;
}

bool Floor::is_ubreakable_wall() {
    return false;
}
