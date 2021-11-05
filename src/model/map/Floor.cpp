#include "Floor.h"

bool Floor::is_walkable() {
    return true;
}

std::ostream &operator<<(std::ostream &os, Floor f) {
    os << "0  ";
    return os;
}
