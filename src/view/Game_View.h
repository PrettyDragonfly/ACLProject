//
// Created by thifl on 10/11/2021.
//

#ifndef PROJET_GAME_VIEW_H
#define PROJET_GAME_VIEW_H


#include "../model/Game.h"

//Forward declaration to avoid recursive includes
class Game;

class Game_View {

public:
    void show(const Game& game);
};


#endif //PROJET_GAME_VIEW_H
