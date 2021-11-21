//
// Created by thifl on 17/10/2021.
//

#include <iostream>
#include "Input_Manager.h"

/**
 * Fonction qui va digerer les inputs
 * A remplacer par la gestion des evenements SDL en temps utile
 **/
void Input_Manager::process_input(Game& game, SDL_Event* event){
    /**
    get_input();
    if (std::toupper(input) == 'X')
        exit(0);
    //std::cout << "pass gettile\n";
    Entity* player = g->get_player();
    //std::cout << &player;
    player->canMove(std::toupper(input));
     **/
    //events
    while( SDL_PollEvent( event ) )
    {
        //Fermeture de la fenêtre
        if( event->type == SDL_QUIT )
        {
            //Close
            game.set_gameover(true);
        }
    }
    move_perso(game);
}

void Input_Manager::get_input() {
    //TODO Faire en sorte que l'input soit vérifié + empécher qu'on puisse rentrer autre chose qu'un char
    std::cout << "Enter input (ZQSD to move, X to quit) : ";
    std::cin >> input;
}

Input_Manager::~Input_Manager() = default;

Input_Manager::Input_Manager() = default;

void Input_Manager::set_game(Game *pGame) {
    g = pGame;
}

void Input_Manager::move_perso(Game &game) {
    const Uint8* keystates;
    SDL_PumpEvents();
    Entity* player = game.get_player();
    keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_W] || keystates[SDL_SCANCODE_UP]){
        player->canMove('Z');
    }
    if(keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_LEFT]){
        player->canMove('Q');
    }
    if(keystates[SDL_SCANCODE_S] || keystates[SDL_SCANCODE_DOWN]){
        player->canMove('S');
    }
    if(keystates[SDL_SCANCODE_D] || keystates[SDL_SCANCODE_RIGHT]){
        player->canMove('D');
    }
}
