#ifndef PROJET_PLAYER_H
#define PROJET_PLAYER_H


#include "Entity.h"

class Player : public Entity{
public:
    int get_y_position() override;
    int get_x_position() override;
};


#endif //PROJET_PLAYER_H
