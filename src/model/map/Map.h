//
// Created by thifl on 17/10/2021.
//

#ifndef PROJET_MAP_H
#define PROJET_MAP_H


#include "Tile.h"
#include <ostream>

class Map {
    static const int size = 10;
    Tile* map[size][size];
public:
    Map();
    Map(int file_number);
    ~Map();
    Tile* get_tile(int x, int y);

    friend std::ostream & operator<<(std::ostream &os, const Map map);
};


#endif //PROJET_MAP_H
