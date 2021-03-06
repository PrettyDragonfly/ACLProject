#ifndef PROJET_MAP_H
#define PROJET_MAP_H

#include <ostream>
#include "Tile.h"
#include <ostream>

class Map {
    int size = 20;
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
    int get_size();

    //Setters

    //Functions members
    //Map& operator=(const Map & m);
    void verify();
    void show();

    void setTile(int x, int y, char tile);
    //friends
    friend std::ostream & operator<<(std::ostream &os, Map& map);
};


#endif //PROJET_MAP_H
