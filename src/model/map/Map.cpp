#include <iostream>
#include "Map.h"
#include "Floor.h"
#include "Breakable_Wall.h"
#include "Unbreakable_Wall.h"
#include "../../ressources/FileReader.h"

/**
 * @brief Map constructor with no specified file then simple map
 */
Map::Map() {
    map = new Tile**[size];
    for (int i = 0; i < size; i++) {
        map[i] = new Tile *[size];
    }
    readFile(this, "easy.txt");
    verify();
}

/**
 * @brief Open file number file_number and reads and create the map from it
 * @param file_number
 */
Map::Map(int file_number){
    //TODO SPRINT 2
}

Map::~Map() {
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
Tile* Map::get_tile(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size){
        return map[x][y];
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, Map& map) {
    for(int j = 0; j < map.size; j++){
        for(int i = 0; i<map.size; i++){
            map.map[j][i]->show();
        }
        std::cout << "\n";
    }
    return os;
}

Map::Map(const Map & m) {
    size = m.size;
}

void Map::verify() {
    for(int i = 0; i< size; i++){
        for (int j = 0; j < size ; j++){
            if (map[i][j] == nullptr)
                std::cout << "NULLPTR " << i << " " << j << std::endl;
        }
    }
}

void Map::show() {
    std::cout << *this;
}

int Map::get_size() {
    return size;
}

void Map::setTile(int x, int y, char tile) {
    switch(tile) {
        case '0':
            map[x][y] = new Floor(x,y);
            break;
        case '1':
            map[x][y] = new Breakable_Wall(x,y);
            break;
        case '2':
            map[x][y] = new Unbreakable_Wall(x,y);
            break;
        default:
            break;
    }
}