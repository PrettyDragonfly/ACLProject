#include "Map.h"
#include "Floor.h"
#include "Unbreakable_Wall.h"

/**
 * @brief Map constructor with no specified file then simple floor map
 *
 */
Map::Map() {
    int i,j;
    for(i = 0; i < size; i++)
        map[i][0] = new Floor();
        for(j = 1; j < size; j++)
            map[i][j] = new Floor();
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
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            delete map[i][j];
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


std::ostream &operator<<(std::ostream &os, const Map map) {
    std::string map_string;
    for (int i = 0; i < map.size; i++){
        for (int j = 0; j < map.size; j++){
            Tile* c = map.map[i][j];
            if(c->is_walkable()){
                map_string.append("O  ");
            }
            else{
                map_string.append("X  ");
            }
        }
        map_string.append("\n");
    }
    os << map_string << std::endl;
    return os;
}

