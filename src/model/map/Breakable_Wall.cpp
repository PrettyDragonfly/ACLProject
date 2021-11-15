#include "Breakable_Wall.h"
#include <iostream>

using namespace std;

bool Breakable_Wall::is_walkable() {
    return false;
}

std::ostream &operator<<(std::ostream &os, Breakable_Wall uw) {
    os << "B  ";
    return os;
}

void Breakable_Wall::show() {
    cout << "B  ";
}

Breakable_Wall::Breakable_Wall(int x, int y) : Tile(x, y) {

}