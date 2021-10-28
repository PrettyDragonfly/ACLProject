//
// Created by Camille on 19/10/2021.
//
#include "Entity.h"
#include "Map.h"

pair Entity::getPosition() {
    return pos;
}

bool Entity::canMove(char Direction) {
    switch (Direction) {
        case 'Z':
            //a implementer dans map
            getElement(getPosition().first,getPosition().second-1);
            break;
        case 'S':
            getElement(getPosition().first,getPosition().second+1);
            break;
        case 'Q':
            getElement(getPosition().first-1, getPosition().second);
            break;
        case 'D':
            getElement(getPosition().first+1, getPosition().second);
            break;
    }
}

int Entity::getPtVie() {
    return ptVie;
}

void Entity::setPtVie(int newPtVie) {
    ptVie = newPtVie;
}

