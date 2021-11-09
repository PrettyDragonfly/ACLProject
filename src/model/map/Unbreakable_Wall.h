

#ifndef PROJET_UNBREAKABLE_WALL_H
#define PROJET_UNBREAKABLE_WALL_H


#include "Tile.h"
#include<utility>

class Unbreakable_Wall : public Tile{

public :
    bool is_breakable() override;

};


#endif //PROJET_UNBREAKABLE_WALL_H
