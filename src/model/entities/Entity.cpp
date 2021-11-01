#include "Entity.h"

void Entity::move(int x_, int y_) {
    x += x_;
    y += y_;
}

std::ostream & operator<<(std::ostream &os, const Entity *ent) {
    os << "x: " << ent->x << " y: " << ent->y << std::endl;
    return os;
}

Entity::~Entity() {

}
