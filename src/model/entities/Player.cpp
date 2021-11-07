#include "Player.h"

Player::Player(pair<int, int> _pos, int _ptVie) : Entity(_pos, _ptVie) {}

Player::Player() : Entity(pair(0,0), 3){

}
