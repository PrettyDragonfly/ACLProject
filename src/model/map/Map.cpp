#include <iostream>
#include "Map.h"
#include "Floor.h"

/**
 * @brief Map constructor with no specified file then simple floor map
 *
 */
Map::Map() {
    std::cout << "Map monstructor called\n";
    map = new Tile**[size];
    for (int i = 0; i < size; i++) {
        map[i] = new Tile*[size];
        for (int j = 1; j < size; j++) {
            map[i][j] = new Floor();
        }
    }
}

/**
 * @brief Open file number file_number and reads and create the map from it
 * @param file_number
 */
Map::Map(int file_number){
    //TODO SPRINT 2
}

Map::~Map() {
    std::cout << "Map destructor called\n";
    int i,j;
    for(i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            delete map[i][j];
        }
        delete map[i];
    }
    delete map;
}

/**
 * Return the tile from coords (x, y)
 * @param x
 * @param y
 * @return the tile from map(x,y)
 */
Tile *Map::get_tile(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size){
        return map[x][y];
    }
}

std::ostream &operator<<(std::ostream &os, Map& map) {
    for(int i = 0; i < map.size; i++){
        for(int j = 0; j<map.size; j++){
            continue;
        }
    }
    return os;
}

