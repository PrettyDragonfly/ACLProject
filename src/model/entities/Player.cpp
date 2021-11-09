#include <iostream>
#include "Player.h"

Player::Player(pair<int, int> _pos, int _ptVie, Map* map) : Entity(_pos, _ptVie, map) {
    std::cout << "Player constructor called\n";
}

Player::Player(const Player &p) : Entity(p){
    std::cout << "Player copy constructor called\n";
}
