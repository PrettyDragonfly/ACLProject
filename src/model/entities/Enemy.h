//
// Created by Camille on 09/11/2021.
//
#ifndef PROJETACL_ENEMY_H
#define PROJETACL_ENEMY_H

#include "Entity.h"
#include <utility>

class Enemy : Entity{
public:
    Enemy(pair<int, int> _pos, int _ptVie, Map* map);
    /**Fonction that follows the player**/
    void Follow(Player* player);
    void RandomMove();
};

#endif //PROJETACL_ENEMY_H
