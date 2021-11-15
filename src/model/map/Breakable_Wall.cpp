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


void Breakable_Wall::Break(Breakable_Wall* wall, Bomb* bomb, Map* map) {
    if (wall->get_x_position() == bomb->get_x_position()) {
        for (int i = (bomb->get_y_position()) - bomb->getSize(); i++; i <= ((bomb->get_y_position()) + bomb->getSize())) {
            if (wall->get_y_position() == i) {
                map->setTile(wall->get_x_position(), i, 0);
            }
        }
    }
    if (wall->get_y_position() == bomb->get_y_position()) {
        for (int i = (bomb->get_x_position()) - bomb->getSize(); i++; i <= ((bomb->get_x_position()) + bomb->getSize())) {
            if (wall->get_x_position() == i) {
                map->setTile(i, wall->get_y_position(), 0);
            }
        }
    }
}