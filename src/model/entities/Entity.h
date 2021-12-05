#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include "../map/Map.h"
#include <utility>
#include <ostream>

using namespace std;

class Entity {
    int x;
    int y;
    int health;
    int value;
    Map* map;
public:
    //Constructors
    Entity(int x, int y, int health, Map* map);

    //Destructors
    ~Entity();

    //Functions members
    virtual void move(int x, int y);
    virtual bool canMove(char input) = 0;

    //Getters
    int get_health() const;
    Map* get_map();
    int get_x_position() const;
    int get_y_position() const;
    int get_value() const;

    //Setters
    void set_health(int newHealth);
    void set_position(int x, int y);
    void set_value(int v);

    //Friends functions
    friend ostream & operator<<(ostream &os, const Entity *ent);
};


#endif //PROJET_ENTITY_H
