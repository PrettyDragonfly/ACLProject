#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"

class World {
    Map* map;
    Entity* player;
    //Entity* enemy;    //pour plus tard
public:
    //TODO define a virtual destructor
    World();
    ~World();
    void update();
    Entity* get_player() const;
    Map* get_map() const;
};


#endif //PROJET_WORLD_H
