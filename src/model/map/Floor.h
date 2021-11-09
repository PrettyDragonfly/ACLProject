#ifndef PROJET_FLOOR_H
#define PROJET_FLOOR_H


#include "Tile.h"
#include <ostream>
#include<utility>

class Floor : public Tile{
public:
    void show() override;
    bool is_walkable() override;
    friend std::ostream& operator<<(std::ostream& os, const Floor& f);
};


#endif //PROJET_FLOOR_H
