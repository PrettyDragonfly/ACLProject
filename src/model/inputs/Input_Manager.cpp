//
// Created by thifl on 17/10/2021.
//

#include <iostream>
#include <cstdlib>
#include "Input_Manager.h"

/**
 * Fonction qui va digerer les inputs
 * A remplacer par la gestion des evenements SDL en temps utile
 **/
void Input_Manager::process_input(){
    get_input();
    Entity* player = g->get_player();
    player->canMove(std::toupper(input));
    /**switch(std::toupper(input)){
        case 'Z':
            //replace with canMove(Direction)
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
        case 'X':
            exit(EXIT_SUCCESS);
        default:
            std::cout << "Input inutile\n";
    }**/
}

void Input_Manager::get_input() {
    std::cout << "Enter input (ZQSD to move, X to quit) : ";
    std::cin >> input;
}

Input_Manager::~Input_Manager() = default;

Input_Manager::Input_Manager() = default;

void Input_Manager::set_game(Game *pGame) {
    g = pGame;
}
