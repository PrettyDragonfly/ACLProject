#ifndef PROJET_FLOOR_H
#define PROJET_FLOOR_H


#include "Tile.h"

class Floor : public Tile{
public:
    bool is_walkable() override;
};


#endif //PROJET_FLOOR_H
