//
// Created by Camille on 15/11/2021.
//
#include "Bomb.h"

Bomb::Bomb(int x, int y, Map* map) : Entity(x, y, 0, map) {

}

Bomb::Bomb(const Bomb &b) : Entity(b){

}

int Bomb::getTime() {
    return timeBeforeExplose;
}

void Bomb::setTime(int newTime) {
    timeBeforeExplose = newTime;
}

int Bomb::getSize() {
    return size;
}

void Bomb::setSize(int newSize) {
    size = newSize;
}

bool Bomb::canMove(char input) {
    return true;
}