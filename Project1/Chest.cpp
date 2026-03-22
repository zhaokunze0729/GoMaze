#include "Chest.h"

#include "Map.h"
#include "data.h"

Chest::Chest() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map->map[i][j] == 'c') {
                this->x = i;  // 行
                this->y = j;  // 列
                return;
            }
        }
    }
}

int Chest::getX() {
    return this->x;  // 返回行
}

int Chest::getY() {
    return this->y;  // 返回列
}

void Chest::setX(int x) {
    map->map[this->x][this->y] = 'n';
    this->x = x;
    map->map[this->x][this->y] = 'c';
}

void Chest::setY(int y) {
    map->map[this->x][this->y] = 'n';
    this->y = y;
    map->map[this->x][this->y] = 'c';
}
