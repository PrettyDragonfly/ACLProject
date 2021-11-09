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
    pair<int, int> getPosition();
    virtual void move(pair<int, int> newPos);
    virtual bool canMove(char input) = 0;

    //Getters
    int get_health();
    Map* get_map();

    //Setters
    void set_health(int newHealth);

    //Friends functions
    friend ostream & operator<<(ostream &os, const Entity *ent);
};


#endif //PROJET_ENTITY_H
