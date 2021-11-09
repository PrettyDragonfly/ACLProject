#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H

#include "Entity.h"
#include <utility>

class Player : public Entity{
public:
    Player(pair<int, int> _pos, int _ptVie, Map* map);
    Player(const Player& p);
};


#endif //PROJET_PLAYER_H
