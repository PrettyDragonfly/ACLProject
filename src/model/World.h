#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"
#include "entities/Bomb.h"

class World {
    Map* map;
    Entity* player;
    Bomb** tab_bomb;
public:
    //TODO define a virtual destructor
    World();
    ~World();
    void update();
    Entity* get_player() const;
    Map* get_map() const;

    //Fonctions d'explosion de bombes
    Bomb**free_tab(Bomb** b);
    Bomb**init_tab(Bomb** tab);
    Bomb** get_tab_bomb();
    void printTab(Bomb** tab);
    void add_bomb(int x, int y, int time, int size);
    void add_bomb(Bomb* b);
    void explode(int indice);
    void check_bomb();
};


#endif //PROJET_WORLD_H
