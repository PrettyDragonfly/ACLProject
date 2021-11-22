//
// Created by thifl on 17/10/2021.
//

#ifndef PROJET_BREAKABLE_WALL_H
#define PROJET_BREAKABLE_WALL_H

#include "Tile.h"
#include "../entities/Bomb.h"
#include "Map.h"
#include <ostream>
#include<utility>

class Breakable_Wall : public Tile{
public:
    bool is_walkable() override;
    explicit Breakable_Wall(int x, int y);
    void show() override;
    void Break(Breakable_Wall* wall, Bomb* bomb, Map* map);
    friend std::ostream& operator<<(std::ostream& os, Breakable_Wall uw);
};


#endif //PROJET_BREAKABLE_WALL_H
