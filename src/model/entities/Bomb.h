//
// Created by Camille on 15/11/2021.
//

#ifndef PROJETACL_BOMB_H
#define PROJETACL_BOMB_H

#include "Entity.h"
#include <utility>

class Bomb : public Entity{
private:
    int timeBeforeExplose = 3;
    int size = 3;
public:
    Bomb();
    Bomb(int x, int y, Map* map);
    Bomb(const Bomb& b);
    int getTime();
    void setTime(int newTime);
    int getSize();
    void setSize(int newSize);
    bool canMove(char input);
};

#endif //PROJETACL_BOMB_H
