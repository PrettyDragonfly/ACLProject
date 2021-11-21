#include <iostream>
#include "Game.h"
#include "entities/Player.h"

void Game::play() {
    //std::cout << world.get_player();
    SDL_Event event;
    while(!gameover){
        im->process_input(*this, &event);                //On process les inputs du joueur
        world.update();                     //On met à jour le monde en fonction
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

