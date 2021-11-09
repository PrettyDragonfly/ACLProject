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
    //std::cout << "pass gettile\n";
    Entity* player = g->get_player();
    //std::cout << &player;
    player->canMove(std::toupper(input));
}

void Input_Manager::get_input() {
    //TODO Faire en sorte que l'input soit vérifié + empécher qu'on puisse rentrer autre chose qu'un char
    std::cout << "Enter input (ZQSD to move) : ";
    std::cin >> input;
}

Input_Manager::~Input_Manager() = default;

Input_Manager::Input_Manager() = default;

void Input_Manager::set_game(Game *pGame) {
    g = pGame;
}
