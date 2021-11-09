#include <ostream>
#include <iostream>
#include "Entity.h"
#include "../map/Tile.h"

using namespace std;

Entity::Entity(pair<int, int> _pos, int _health, Map* _map) {
    pos = _pos;
    health = _health;
    map = _map;
}

pair<int, int> Entity::getPosition() {
    return pos;
}

void Entity::move(pair<int, int> newPos) {
    pos = newPos;
}

bool Entity::canMove(char Direction) {
    Tile* tile = NULL;
    switch (Direction) {
        case 'Z':
            tile = map->get_tile(getPosition().first,getPosition().second-1);
            break;
        case 'S':
            tile = map->get_tile(getPosition().first,getPosition().second+1);
            break;
        case 'Q':
            tile = map->get_tile(getPosition().first-1, getPosition().second);
            break;
        case 'D':
            tile = map->get_tile(getPosition().first+1, getPosition().second);
            break;
        default:
            cout << "Input inutile\n";
    }
    if (tile != NULL) {
        if (tile->is_walkable() != 0) {
            move(tile->getPosition());
        }
    }
}

int Entity::get_health() {
    return health;
}

void Entity::set_health(int newHealth) {
    health = newHealth;
}

Entity::~Entity() {}

ostream & operator<<(ostream &os, const Entity *ent) {
    os << "x: " << ent->pos.first << " y: " << ent->pos.second << " hp: " << ent->health << endl;
    return os;
}

void Entity::move(int x, int y) {
    //Dummy function
}
