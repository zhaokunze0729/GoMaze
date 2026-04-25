#include "Player.h"
#include "Map.h"
#include "data.h"

Player::Player() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map->map[i][j] == ID_P) {
                this->x = i;  
                this->y = j;  
                return;
            }
        }
    }
}

int Player::getX() {
    return this->x;  
}

int Player::getY() {
    return this->y;  
}

void Player::setX(int x) {
    map->map[this->x][this->y] = ID_N;
    this->x = x;
    map->map[this->x][this->y] = ID_P;
}

void Player::setY(int y) {
    map->map[this->x][this->y] = ID_N;
    this->y = y;
    map->map[this->x][this->y] = ID_P;
}

void Player::setName(char name) {
    this->name = name;
}