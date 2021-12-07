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

    //Setters
    void set_gameover(bool b);

    //Getters
    Entity * get_player() const;
    Entity * get_enemy() const;
    Map* get_map() const;
    World* get_world();
    Bomb** get_tab_bomb() const;
    Entity** get_ent_tab() const;

    Map* getMap();
    void show() const;
    void init();
    void clean();
};

#endif //PROJET_GAME_H
