#include "Unbreakable_Wall.h"
#include <iostream>

bool Unbreakable_Wall::is_walkable() {
    return false;
}

std::ostream &operator<<(std::ostream &os, Unbreakable_Wall uw) {
    os << "X  ";
    return os;
}

void Unbreakable_Wall::show() {
    std::cout << "X  ";
}

Unbreakable_Wall::Unbreakable_Wall(pair<int, int> pos_) : Tile(pos_) {

}
