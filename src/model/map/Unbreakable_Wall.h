

#ifndef PROJET_UNBREAKABLE_WALL_H
#define PROJET_UNBREAKABLE_WALL_H


#include "Tile.h"
#include <ostream>
#include<utility>

class Unbreakable_Wall : public Tile{
public:
    Unbreakable_Wall();
    bool is_walkable() override;
    void show() override;
    friend std::ostream& operator<<(std::ostream& os, Unbreakable_Wall uw);
};


#endif //PROJET_UNBREAKABLE_WALL_H
