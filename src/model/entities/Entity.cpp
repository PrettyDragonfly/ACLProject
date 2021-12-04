#include <ostream>
#include <iostream>
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

bool Entity::canMove(char Direction) {
    int x_pos = get_x_position();
    int y_pos = get_y_position();
    Tile* tile = nullptr;
    switch (Direction) {
        case 'Z':
            tile = get_map()->get_tile(x_pos,y_pos-1);
            break;
        case 'S':
            tile = get_map()->get_tile(x_pos,y_pos+1);
            break;
        case 'Q':
            tile = get_map()->get_tile(x_pos-1, y_pos);
            break;
        case 'D':
            tile = get_map()->get_tile(x_pos+1, y_pos);
            break;
        default:
            std::cout << "Input inutile\n";
    }
    if (tile != nullptr && tile->is_walkable()) {
        //std::cout << "move\n";
        //std::cout << pos.first << " " << pos.second << std::endl;
        move(tile->get_x_position(), tile->get_y_position());
        return true;
    }
    else if(tile != nullptr && !tile->is_walkable()){
        std::cout << "Mouvement impossible (vous foncez dans un mur)\n";
    }
    return false;
};


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


