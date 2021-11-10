#ifndef PROJET_MAP_H
#define PROJET_MAP_H

#include <ostream>
#include "Tile.h"
#include <ostream>

class Map {
    int size = 10;
    Tile*** map;
public:
    //Constructors
    Map();
    Map(int file_number);
    Map(const Map& m);

    //Destructor
    ~Map();

    //Getter
    Tile* get_tile(int x, int y);

    //Setters

    //Functions members
    //Map& operator=(const Map & m);
    void verify();
    void show();

    //friends
    friend std::ostream & operator<<(std::ostream &os, Map& map);
};


#endif //PROJET_MAP_H
