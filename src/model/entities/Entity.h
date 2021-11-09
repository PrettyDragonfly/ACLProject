#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include "../map/Map.h"
#include <utility>
#include <ostream>

using namespace std;

class Entity {
    pair<int, int> pos;
    int health;
    Map* map;
public:
    //Constructors
    Entity(pair<int, int> pos, int health, Map* map);

    //Destructors
    ~Entity();

    //Functions members
    virtual void move(pair<int, int> newPos);
    virtual bool canMove(char input) = 0;

    //Getters
    int get_health();
    Map* get_map();
    pair<int, int> get_position();

    //Setters
    void set_health(int newHealth);
    void set_position(pair<int, int> pos);

    //Friends functions
    friend ostream & operator<<(ostream &os, const Entity *ent);
};


#endif //PROJET_ENTITY_H
