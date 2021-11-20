#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"

class World {
    Map* map;
    Entity* player;
    Entity** tab_bomb;
public:
    //TODO define a virtual destructor
    World();
    ~World();
    void update();
    Entity* get_player() const;
    Map* get_map() const;
    Entity** get_tab_bomb() const;
};


#endif //PROJET_WORLD_H
