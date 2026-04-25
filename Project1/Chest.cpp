#include "Chest.h"

#include "Map.h"
#include "data.h"

Chest::Chest() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map->map[i][j] == ID_C) {
                this->x = i;  
                this->y = j;  
                return;
            }
        }
    }
}

int Chest::getX() {
    return this->x;  
}

int Chest::getY() {
    return this->y;  
}

void Chest::setX(int x) {
    map->map[this->x][this->y] = ID_N;
    this->x = x;
    map->map[this->x][this->y] = ID_C;
}

void Chest::setY(int y) {
    map->map[this->x][this->y] = ID_N;
    this->y = y;
    map->map[this->x][this->y] = ID_C;
}
