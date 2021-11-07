#ifndef PROJET_TILE_H
#define PROJET_TILE_H
#include <utility>
#include <ostream>

using namespace std;

class Tile {
private :
    pair<int, int> pos;
public:
    virtual bool is_walkable() = 0;
    /**isBreakable(Tile tile);
    setPosition(pair pos);
    getPosition(pair pos);**/
};

#endif //PROJET_TILE_H
