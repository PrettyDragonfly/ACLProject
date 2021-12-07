//
// Created by Camille on 09/11/2021.
//
#include "Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(int x, int y, int _ptVie, Map* map) : Entity( x, y, _ptVie, map) {
        set_value(2);
}

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

int Enemy::getStepCounter(){
    return stepCounter;
}

void Enemy::setStepCounter(int counter){
    stepCounter = counter;
}

void Enemy::RandomMove() {
    int randomNumber;
    int nbStepMax;
    srand((unsigned int)time(0));
    nbStepMax = rand() %10 +1;
    setStepCounter(getStepCounter()+1);
    //If move is impossible, turn
    if ((getStepCounter() >= nbStepMax) || (!canMove(Direction))) {
        randomNumber = rand() %4 +0;
        setStepCounter(0);
        std::cout << "Random number: " << randomNumber << std::endl;
        switch (randomNumber) {
            case 0:
                Direction = 'Z';
                break;
            case 1:
                Direction = 'D';
                break;
            case 2:
                Direction = 'S';
                break;
            case 3:
                Direction = 'Q';
                break;
            default:
                std::cout << "Erreur dans le choix de la nouvelle direction de l'ennemi" << std::endl;
        }
    }
}