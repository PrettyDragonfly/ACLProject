#include <iostream>
#include "Game.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

void Game::play() {
    SDL_Event event;
    while(!gameover){
        im->process_input(*this, &event);                //On process les inputs du joueur
        world.update();                     //On met à jour le monde en fonction
        world.get_enemy()->RandomMove();
        gv->refresh(*this);
        //gv->show(*this);              //On met à jour et on affiche les vues
        if (world.get_player()->get_health() <= 0)
            gameover = true;
        SDL_Delay(200);
    }
}

Game::Game() {
    im = new Input_Manager();
    im->set_game(this);
}

Entity * Game::get_player() const{
    return world.get_player();
}

World* Game::get_world() {
    return &world;
}

Game::~Game() {
    delete im;
}

void Game::show() const {
    std::cout << world.get_player();
    world.get_map()->show();
}

void Game::init(){
    gv->init();
}

void Game::clean(){
    //TODO
}

Map *Game::get_map() const{
    return world.get_map();
}

void Game::set_gameover(bool b) {
    gameover = b;
}

Bomb** Game::get_tab_bomb() const{
    return world.get_tab_bomb();
}
