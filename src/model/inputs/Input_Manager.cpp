//
// Created by thifl on 17/10/2021.
//

#include <iostream>
#include "Input_Manager.h"

/**
 * Fonction qui va digerer les inputs
 * A remplacer par la gestion des evenements SDL en temps utile
 **/
void Input_Manager::process_input(){
    get_input();
    Entity* player = g->get_player();
    switch(std::toupper(input)){
        case 'Z':
            player->move(0,-1);
            break;
        case 'Q':
            player->move(-1, 0);
            break;
        case 'S':
            player->move(0, 1);
            break;
        case 'D':
            player->move(1, 0);
            break;
        default:
            std::cout << "Input inutile\n";
    }
}

void Input_Manager::get_input() {
    std::cout << "Enter input : ";
    std::cin >> input;
}

Input_Manager::~Input_Manager() {}

Input_Manager::Input_Manager() {
}

void Input_Manager::set_game(Game *pGame) {
    g = pGame;
}
