#include "Entity.h"

void Entity::move(int x_, int y_) {
    x += x_;
    y += y_;
}

//Friend function for display
std::ostream & operator<<(std::ostream &os, const Entity *ent) {
    os << "x: " << ent->x << " y: " << ent->y << " hp: " << ent->health << std::endl;
    return os;
}

int Entity::get_health() {
    return health;
}

//Virtual destructor but useless right now
Entity::~Entity() {

}

int Entity::get_y_position() {
    return y;
}

int Entity::get_x_position() {
    return x;
}

Entity::Entity(int x_, int y_, int health_) {
    x = x_;
    y = y_;
    health = health_;
}
