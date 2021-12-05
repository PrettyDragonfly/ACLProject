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

bool Player::canMove(char Direction) {
    int x_pos = get_x_position();
    int y_pos = get_y_position();
    Tile* tile = nullptr;
    switch (Direction) {
        case 'Z':
            tile = get_map()->get_tile(x_pos,y_pos-1);
            //std::cout << "pass gettile4444\n";
            break;
        case 'S':
            tile = get_map()->get_tile(x_pos,y_pos+1);
            break;
        case 'Q':
            tile = get_map()->get_tile(x_pos-1, y_pos);
            break;
        case 'D':
            tile = get_map()->get_tile(x_pos+1, y_pos);
            break;
        default:
            cout << "Input inutile\n";
    }
    if (tile != nullptr && tile->is_walkable()) {
        //std::cout << "move\n";
        //std::cout << pos.first << " " << pos.second << std::endl;
        move(tile->get_x_position(), tile->get_y_position());
        return true;
    }
    else if(tile != nullptr && !tile->is_walkable()){
        std::cout << "Mouvement impossible (vous foncez dans un mur)\n";
    }
    return false;
}

void Player::move(int x_, int y_) {
    set_position(x_, y_);
}

void Player::set_value(int v){
    value = v;
}

