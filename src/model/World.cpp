#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World() {
    //std::cout << "World constructor called\n";
    map = new Map();
    player = new Player(1, 1, 10, this->map);
    tab_bomb = new Bomb*[50];
}

/**
 * @brief Update function for the world
 */
void World::update() {

}

/**
 * Player getter
 * @return player
 */
Entity* World::get_player() const{
    return player;
}

World::~World() {
    std::cout << "World destructor called\n";
    delete player;
}

Map* World::get_map() const{
    return map;
}

Bomb** World::get_tab_bomb() const{
    return tab_bomb;
}

void World::printTab() {
    Bomb** tab = tab_bomb;
    int taille = tab[0]->get_health(); //on met la taille ici 

    for(int i = 1; i < taille; i++) {
        int x_bombe = tab[i]->get_x_position();
        int y_bombe = tab[i]->get_y_position();
        int time = tab[i]->getTime();

        std::cout << x_bombe << y_bombe;
    }
}