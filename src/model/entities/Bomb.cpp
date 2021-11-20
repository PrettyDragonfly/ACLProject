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

//rajout à verifier
void Bomb::printTab() {
    Entity** tab = world.get_tab_bomb();
    int taille = tab[0]->get_health(); //on met la taille ici 

    for(int i = 1; i < taille; i++) {
        int x_bombe = tab[i]->get_x_position();
        int y_bombe = tab[i]->get_y_position();

        std::cout << x_bombe << y_bombe;
    }
}