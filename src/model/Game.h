#ifndef PROJET_GAME_H
#define PROJET_GAME_H

#include "World.h"
#include "entities/Player.h"
#include "inputs/Input_Manager.h"

//Forward declaration
class Input_Manager;

class Game {
    Input_Manager* im;
    World world;
    bool gameover = false;
public:
    Game();
    ~Game();
    void play();
    Entity * get_player();
};

#endif //PROJET_GAME_H
