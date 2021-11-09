#include <iostream>
#include "Player.h"

Player::Player(pair<int, int> _pos, int _ptVie, Map* map) : Entity(_pos, _ptVie, map) {
    std::cout << "Player constructor called\n";
}

Player::Player(const Player &p) : Entity(p){
    std::cout << "Player copy constructor called\n";
}

bool Player::canMove(char Direction) {
    pair<int, int> pos = get_position();
    Tile* tile = nullptr;
    switch (Direction) {
        case 'Z':
            tile = get_map()->get_tile(pos.first,pos.second-1);
            //std::cout << "pass gettile4444\n";
            break;
        case 'S':
            tile = get_map()->get_tile(pos.first,pos.second+1);
            break;
        case 'Q':
            tile = get_map()->get_tile(pos.first-1, pos.second);
            break;
        case 'D':
            tile = get_map()->get_tile(pos.first+1, pos.second);
            break;
        default:
            cout << "Input inutile\n";
    }
    if (tile != nullptr && tile->is_walkable()) {
        std::cout << "move\n";
        std::cout << pos.first << " " << pos.second << std::endl;
        move(tile->getPosition());
    }
    else if(tile != nullptr && !tile->is_walkable()){
        std::cout << "Mouvement impossible (vous foncez dans un mur)\n";
    }
}

void Player::move(pair<int, int> pos_) {
    set_position(pos_);
}
