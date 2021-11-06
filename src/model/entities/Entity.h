#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include <utility>
#include "../map/World.h"

using namespace std;

class Entity {
protected:
    pair<int, int> pos;
    int health;
    World world;
public:
    Entity(pair <int, int> pos, int health);
    pair<int, int> getPosition();
    bool canMove(char Direction);
    int get_health();
    void set_health(int newHealth);
    void move(pair<int, int> newPos);
    ~Entity();

    //friend ostream & operator<<(std::ostream &os, const Entity *ent);
};


#endif //PROJET_ENTITY_H
