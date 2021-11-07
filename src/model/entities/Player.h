#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H


#include "Entity.h"
#include <utility>

class Player : public Entity{
public:
    Player();
    Player(pair<int, int> _pos, int _ptVie);
};


#endif //PROJET_PLAYER_H
