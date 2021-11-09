#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World(){
    map = new Map();
    player = new Entity(pair(5,5), 10, this->map);
    //enemy = new Entity(pair(7,8),5,this->map);
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

/**Entity* World::get_enemy() {
    return enemy;
}**/
