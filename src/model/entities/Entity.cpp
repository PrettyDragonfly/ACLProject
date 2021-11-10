#include <ostream>
#include "Entity.h"

using namespace std;

Entity::Entity(int x_, int y_, int _health, Map* _map) {
    x = x_;
    y = y_;
    health = _health;
    map = _map;
}

int Entity::get_x_position() const {
    return x;
}

int Entity::get_y_position() const {
    return y;
}

void Entity::move(int x_, int y_) {
    x = x_;
    y = y_;
}

int Entity::get_health() const {
    return health;
}

void Entity::set_health(int newHealth) {
    health = newHealth;
}

Entity::~Entity() = default;

ostream & operator<<(ostream &os, const Entity *ent) {
    os << "Entity : x: " << ent->x << " y: " << ent->y << " hp: " << ent->health << endl;
    return os;
}

Map *Entity::get_map() {
    return map;
}

void Entity::set_position(int x_, int y_) {
    x = x_;
    y = y_;
}


