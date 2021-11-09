#include <ostream>
#include "Entity.h"

using namespace std;

Entity::Entity(pair<int, int> _pos, int _health, Map* _map) {
    pos = _pos;
    health = _health;
    map = _map;
}

pair<int, int> Entity::get_position() {
    return pos;
}

void Entity::move(pair<int, int> newPos) {
    pos = newPos;
}

int Entity::get_health() {
    return health;
}

void Entity::set_health(int newHealth) {
    health = newHealth;
}

Entity::~Entity() {}

ostream & operator<<(ostream &os, const Entity *ent) {
    os << "Entity : x: " << ent->pos.first << " y: " << ent->pos.second << " hp: " << ent->health << endl;
    return os;
}

Map *Entity::get_map() {
    return map;
}

void Entity::set_position(pair<int, int> pos_) {
    pos = pos_;
}


