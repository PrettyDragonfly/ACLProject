//
// Created by Camille on 19/10/2021.
//
#include "Entity.h"
#include "../map/Map.h"

pair<int, int> Entity::getPosition() {
    return pos;
}

bool Entity::canMove(char Direction) {
    switch (Direction) {
        case 'Z':
            //a implementer dans map
            Map::get_tile(getPosition().first,getPosition().second-1);
            break;
        case 'S':
            Map::get_tile(getPosition().first,getPosition().second+1);
            break;
        case 'Q':
            Map::get_tile(getPosition().first-1, getPosition().second);
            break;
        case 'D':
            Map::get_tile(getPosition().first+1, getPosition().second);
            break;
    }
}

int Entity::getPtVie() {
    return ptVie;
}

void Entity::setPtVie(int newPtVie) {
    ptVie = newPtVie;
}

