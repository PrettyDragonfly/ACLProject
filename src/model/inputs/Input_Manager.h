#ifndef PROJET_INPUT_MANAGER_H
#define PROJET_INPUT_MANAGER_H

#include "../Game.h"
#include <SDL2/SDL.h>

//Forward declaration
class Game;

class Input_Manager {
    Game* g{};
    char input{};
public:
    Input_Manager();
    Input_Manager(Game* pGame);
    ~Input_Manager();

    void process_input(Game& game, SDL_Event* event);
    void get_input();
    void set_game(Game* pGame);
    void move_perso(Game& game);
};

#endif //PROJET_INPUT_MANAGER_H
