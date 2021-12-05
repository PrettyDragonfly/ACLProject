#include <iostream>
#include "Player.h"

Player::Player(int x, int y, int _ptVie, Map* map) : Entity(x, y, _ptVie, map) {
    //std::cout << "Player constructor called\n";
}

Player::Player(const Player &p) : Entity(p){
    //std::cout << "Player copy constructor called\n";
}