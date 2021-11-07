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
    //bool isBreakable(Tile tile);
    pair<int, int> setPosition(pair<int, int> pos);
    pair<int, int> getPosition();
};

#endif //PROJET_TILE_H
