#include "End.h"
#include "Map.h"
#include "data.h"

End::End() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map->map[i][j] == ID_E) {
				this->x = i;
				this->y = j;
				return;
			}
		}
	}
}
int End::isDie() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map->map[i][j] == ID_E) {
				return 0;
			}
		}
	}
	return 1;
}
int End::getX() {
	return this->x;
}
int End::getY() {
	return this->y;
}
