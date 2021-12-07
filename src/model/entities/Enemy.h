//
// Created by Camille on 09/11/2021.
//
#ifndef PROJETACL_ENEMY_H
#define PROJETACL_ENEMY_H

#include "Player.h"
#include <utility>

class Enemy : public Entity{
private:
    bool move = false;
    char Direction = 'Q';
    int stepCounter = 0;
public:
    Enemy(int x, int y, int _ptVie, Map* map);
    /**Random enemy's moves**/
    void RandomMove();
    bool isMoving();
    void setMove(bool ismoving);
    char getDirection();
    void setDirection(char dir);
    int getStepCounter();
    void setStepCounter(int counter);
    //Player* getPlayer();
};

#endif //PROJETACL_ENEMY_H
