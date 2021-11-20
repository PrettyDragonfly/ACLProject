#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World() {
    //std::cout << "World constructor called\n";
    map = new Map();
    player = new Player(1, 1, 10, this->map);
    tab_bomb = new Entity*[50];
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

Entity** World::get_tab_bomb() const{
    return tab_bomb;
}
