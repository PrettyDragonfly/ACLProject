#ifndef PROJET_GAME_H
#define PROJET_GAME_H

#include "World.h"
#include "entities/Player.h"
#include "inputs/Input_Manager.h"
#include "../view/Game_View.h"

//Forward declaration
class Input_Manager;
class Game_View;

class Game {
    Input_Manager* im;
    World world;
    Game_View* gv;
    bool gameover = false;
public:
    Game();
    ~Game();
    void play();
    Entity * get_player();

    Map* getMap();
    void show() const;
};

#endif //PROJET_GAME_H
