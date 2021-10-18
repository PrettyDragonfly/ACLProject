//
// Created by thifl on 17/10/2021.
//
#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H
using namespace std;

abstract class Entity {
    private pair<int, int> pos;
    private int ptVie;

    public Entity(pair pos, int ptVie) {
        this.pos.first = pos.first;
        this.pos.second = pos.second;
        this.ptVie = ptVie;
    }
};


#endif //PROJET_ENTITY_H
