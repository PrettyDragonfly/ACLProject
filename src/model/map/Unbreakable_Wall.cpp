#include "Unbreakable_Wall.h"
#include <iostream>

Unbreakable_Wall::Unbreakable_Wall() = default;

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
