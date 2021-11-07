#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include <utility>
#include <ostream>

using namespace std;

class Entity {
protected:
    pair<int, int> pos;
    int health;
public:
    Entity(pair <int, int> pos, int health);
    pair<int, int> getPosition();
    bool canMove(char Direction);
    void move(int x, int y);
    int get_health();
    void set_health(int newHealth);
    void move(pair<int, int> newPos);
    ~Entity();

    friend ostream & operator<<(ostream &os, const Entity *ent);
};


#endif //PROJET_ENTITY_H
