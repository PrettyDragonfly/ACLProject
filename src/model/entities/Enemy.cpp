//
// Created by Camille on 09/11/2021.
//
#include "Enemy.h"

Enemy::Enemy(int x, int y, int _ptVie, Map* map) : Entity( x, y, _ptVie, map) {}

void Enemy::Follow(Player* player) {}

void Enemy::RandomMove() {}