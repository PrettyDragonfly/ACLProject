#include <iostream>
#include "Game.h"
#include "entities/Player.h"

void Game::play() {
    std::cout << world.get_player();
    while(!gameover){
        im->process_input();
        world.update();
        std::cout << world.get_player();
        world.get_map()->show();
        if (world.get_player()->get_health() <= 0)
            gameover = true;
    }
}

Game::Game() {
    im = new Input_Manager();
    im->set_game(this);
}

Entity * Game::get_player() {
    return world.get_player();
}

Game::~Game() {
    delete im;
}

