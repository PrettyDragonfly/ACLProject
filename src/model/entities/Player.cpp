#include <iostream>
#include "Player.h"

Player::Player(int x, int y, int _ptVie, Map* map) : Entity(x, y, _ptVie, map) {
    set_value(1);
    //std::cout << "Player constructor called\n";
}

Player::Player(const Player &p) : Entity(p){
    set_value(1);
    //std::cout << "Player copy constructor called\n";
}