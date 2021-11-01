#ifndef PROJET_INPUT_MANAGER_H
#define PROJET_INPUT_MANAGER_H

#include "../Game.h"

//Forward declaration
class Game;

class Input_Manager {
    Game* g;
    char input;
public:
    Input_Manager();
    Input_Manager(Game* pGame);
    ~Input_Manager();
    void process_input();
    void get_input();
    void set_game(Game* pGame);
};

#endif //PROJET_INPUT_MANAGER_H
