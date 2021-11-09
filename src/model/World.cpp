#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World(){
<<<<<<< HEAD
    player = new Player(pair(0,0), 3);
=======
    map = new Map();
    player = new Entity(pair(5,5), 10, this->map);
>>>>>>> test_flo_1
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
Entity* World::get_player() {
    return player;
}

World::~World() {
    delete player;
}

Map& World::get_map() {
    return map;
}
