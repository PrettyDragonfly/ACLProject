#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H

#include "Entity.h"
#include <utility>

class Player : public Entity{
private :
    int lifePts =7;
public:
    Player();

    Player(int x, int y, int _ptVie, Map* map);
    Player(const Player& p);
    bool canMove(char Direction);
    void move(int x, int y);
    int getLifePts();
    void setLifePts(int life);
};


#endif //PROJET_PLAYER_H
