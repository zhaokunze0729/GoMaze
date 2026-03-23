#include "Trap.h"
#include "data.h"
#include "Map.h"

Trap::Trap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map->map[i][j] == ID_T) {
				this->x = i;
				this->y = j;
				return;
			}
		}
	}
}

int Trap::getX() {
	return this->x;
}

int Trap::getY() {
	return this->y;
}

int Trap::isPlayerDie() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map->map[i][j] == ID_P) {
				return 0;
			}
		}
	}
	return 1;
}