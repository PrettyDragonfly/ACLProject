#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H


#include <ostream>

class Entity {
    int health;
    int x, y;
public:
    virtual ~Entity();
    virtual int get_x_position() = 0;
    virtual int get_y_position() = 0;
    void move(int x, int y);
    friend std::ostream & operator<<(std::ostream& os, const Entity* ent);
};


#endif //PROJET_ENTITY_H
