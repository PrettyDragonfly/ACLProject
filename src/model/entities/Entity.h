#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include <utility>

using namespace std;

class Entity {
private:
    pair<int, int> pos;
    int ptVie;
public:
    pair getPosition();
    bool canMove(char Direction);
};


#endif //PROJET_ENTITY_H
