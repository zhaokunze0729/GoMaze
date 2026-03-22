#include "Player.h"
#include "Map.h"
#include "data.h"

Player::Player() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map->map[i][j] == 'p') {
                this->x = i;  // 行
                this->y = j;  // 列
                return;
            }
        }
    }
}

int Player::getX() {
    return this->x;  // 返回行
}

int Player::getY() {
    return this->y;  // 返回列
}

void Player::setX(int x) {
    map->map[this->x][this->y] = 'n';
    this->x = x;
    map->map[this->x][this->y] = 'p';
}

void Player::setY(int y) {
    map->map[this->x][this->y] = 'n';
    this->y = y;
    map->map[this->x][this->y] = 'p';
}

void Player::setName(char name) {
    this->name = name;
}