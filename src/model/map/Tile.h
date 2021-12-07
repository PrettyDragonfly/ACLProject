#ifndef PROJET_TILE_H
#define PROJET_TILE_H
#include <utility>
#include <ostream>

using namespace std;

class Tile {
private :
    int x;
    int y;
public:
    //TODO define a virtual destructor
    explicit Tile(int x_, int y_);
    virtual bool is_walkable() = 0;
    virtual void show() = 0;
    virtual bool is_floor() = 0;
    virtual bool is_ubreakable_wall() = 0;
    void set_position(int x_, int y_);
    int get_x_position();
    int get_y_position();
    virtual ~Tile();
};

#endif //PROJET_TILE_H
