#include <iostream>
#include "Player.h"

Player::Player(int x, int y, int _ptVie, Map* map) : Entity(x, y, _ptVie, map) {

}

Player::Player(const Player &p) : Entity(p){

}