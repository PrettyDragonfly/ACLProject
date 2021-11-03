#include "World.h"
#include "entities/Player.h"

World::World(){
    player = new Player();
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

Map World::get_map() {
    return map;
}
