//
// Created by thifl on 17/10/2021.
//

#ifndef PROJET_BREAKABLE_WALL_H
#define PROJET_BREAKABLE_WALL_H


#include "Tile.h"

class Breakable_Wall : public Tile{
public:
    bool is_walkable() override;
};


#endif //PROJET_BREAKABLE_WALL_H
