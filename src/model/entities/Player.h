#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H

#include "Entity.h"
#include <utility>

class Player : public Entity{
public:
    Player();

    Player(int x, int y, int _ptVie, Map* map);
    Player(const Player& p);
    bool canMove(char Direction);
    void move(int x, int y);
};


#endif //PROJET_PLAYER_H
