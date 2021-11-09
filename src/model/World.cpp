#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World() {
    std::cout << "World constructor called\n";
    player = new Player(pair(5,5), 10, this->map);
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
    std::cout << "World destructor called\n";
    delete player;
}

Map* World::get_map() {
    return map;
}
