#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
#include <utility>

using namespace std;

class Entity {
protected:
    pair<int, int> pos;
    int ptVie;
public:
    pair<int, int> getPosition();
    bool canMove(char Direction);
    int getPtVie();
    void setPtVie(int newPtVie);
};


#endif //PROJET_ENTITY_H
