//
// Created by Camille on 09/11/2021.
//
#include "Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(int x, int y, int _ptVie, Map* map) : Entity( x, y, _ptVie, map) {}

bool Enemy::isMoving() {
    return move;
}

void Enemy::setMove(bool ismoving) {
    move = ismoving;
}

char Enemy::getDirection() {
    return Direction;
}

void Enemy::setDirection(char dir) {
    Direction = dir;
}

void Enemy::RandomMove() {
    int randomNumber;
    srand((unsigned int)time(0));
    //If move is impossible, turn
    if (!canMove(Direction)) {
        randomNumber = rand() %4 +0;
        switch (randomNumber) {
            case 0:
                Direction = 'Z';
                break;
            case 1:
                Direction = 'S';
                break;
            case 2:
                Direction = 'Q';
                break;
            case 3:
                Direction = 'D';
                break;
            default:
                std::cout << "Erreur dans le choix de la nouvelle direction de l'ennemi" << std::endl;
        }
    }
}