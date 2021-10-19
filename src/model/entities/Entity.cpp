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
            getElement(getPosition().first+);
            break;
    }
}

