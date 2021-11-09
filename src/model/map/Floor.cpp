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

Floor::Floor(pair<int, int> pos) : Tile(pos){

}

