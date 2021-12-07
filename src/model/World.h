#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "map/Map.h"
#include "entities/Entity.h"
#include "entities/Enemy.h"
#include "entities/Bomb.h"

class World {
    Map* map;
    Entity* player;
    Enemy* enemy;
    Bomb** tab_bomb;
    Entity **tab_entite;

public:
    //TODO define a virtual destructor
    World();
    ~World();
    void update();
    Entity* get_player() const;
    Enemy* get_enemy() const;
    Map* get_map() const;

    //Fonctions de tableau d'entites
    Entity** get_tab_entite() const;
    void free_entite(Entity** e);
    Entity** init_entite(Entity** tab);
    void add_entite(int x, int y, int life, int value);
    void add_entite(Entity* b);
    void check_entite();
    void print(Entity** tab);
    bool tab_entite_vide();

    //Fonctions d'explosion de bombes
    void free_tab(Bomb** b);
    Bomb**init_tab(Bomb** tab);
    Bomb** get_tab_bomb() const;
    void printTab(Bomb** tab);
    bool tab_vide();
    void add_bomb(int x, int y, int time, int size);
    void add_bomb(Bomb* b);
    void explode(int indice);
    void check_bomb();
    void pose_bomb(char c);
};


#endif //PROJET_WORLD_H
