#include <iostream>
#include "Game.h"
#include "entities/Player.h"

void Game::play() {
    while(!gameover){
        im->process_input();
        world.update();
        std::cout << world.get_player();
    }
}

Game::Game() {
    im = new Input_Manager();
    im->set_game(this);
    world = World();
}

Entity * Game::get_player() {
    return world.get_player();
}

Game::~Game() {
    delete im;
}