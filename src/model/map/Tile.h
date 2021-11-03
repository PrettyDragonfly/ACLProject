#ifndef PROJET_TILE_H
#define PROJET_TILE_H


class Tile {
public:
    ~Tile();
    virtual bool is_walkable() = 0;
};

#endif //PROJET_TILE_H
