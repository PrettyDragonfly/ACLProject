#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H


#include <ostream>

class Entity {
    int health;
    int x, y;
public:
    Entity(int x_, int y_, int health_);
    virtual ~Entity();
    virtual int get_x_position();
    virtual int get_y_position();
    virtual int get_health();
    void move(int x, int y);
    friend std::ostream & operator<<(std::ostream& os, const Entity* ent);
};


#endif //PROJET_ENTITY_H
