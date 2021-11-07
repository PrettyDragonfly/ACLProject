//
// Created by Camille on 19/10/2021.
//
#include <ostream>
#include "Entity.h"

using namespace std;

Entity::Entity(pair<int, int> _pos, int _health) {
    pos = _pos;
    health = _health;
}

pair<int, int> Entity::getPosition() {
    return pos;
}

void Entity::move(pair<int, int> newPos) {
    pos = newPos;
}
/**
bool Entity::canMove(char Direction) {
    Tile* tile;
    switch (Direction) {
        case 'Z':
            tile = world.get_map.get_tile(getPosition().first,getPosition().second-1);
            break;
        case 'S':
            tile = world.get_map.get_tile(getPosition().first,getPosition().second+1);
            break;
        case 'Q':
            tile = world.get_map.get_tile(getPosition().first-1, getPosition().second);
            break;
        case 'D':
            tile = world.get_map.get_tile(getPosition().first+1, getPosition().second);
            break;
    }
    /**
    if (tile.is_breakable()) {
        move(tile.getPosition());
    }
}
**/
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
