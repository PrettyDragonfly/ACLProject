#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"

class World {
    Map* map;
    Entity* player;
public:
    World();
    ~World();
    void update();
    Entity* get_player();
    Map* get_map();
};


#endif //PROJET_WORLD_H
