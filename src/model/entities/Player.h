#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H

#include "Entity.h"
#include <utility>

class Player : public Entity{
    int value;
public:
    Player();

    Player(int x, int y, int _ptVie, Map* map);
    Player(const Player& p);
    bool canMove(char Direction);
    void move(int x, int y);
    void set_value(int v);

};


#endif //PROJET_PLAYER_H
