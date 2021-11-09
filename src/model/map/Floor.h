#ifndef PROJET_FLOOR_H
#define PROJET_FLOOR_H


#include "Tile.h"
#include<utility>

class Floor : public Tile{

public:
    bool is_breakable() override;
    bool is_walkable() override;
};


#endif //PROJET_FLOOR_H
