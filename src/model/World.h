#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"
#include "entities/Bomb.h"

class World {
    Map* map;
    Entity* player;
    Bomb** tab_bomb;
    //Entity* enemy;    //pour plus tard
public:
    //TODO define a virtual destructor
    World();
    ~World();
    void update();
    Entity* get_player() const;
    Map* get_map() const;
    Bomb** get_tab_bomb() const;
    void printTab();
};


#endif //PROJET_WORLD_H
