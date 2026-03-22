#include "GameWindow.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "data.h"
#include <vector>

GameWindow::GameWindow()
{
	this->redraw();
	this->player = new Player();
	this->end = new End();
	this->chest = new Chest();
	this->trap = new Trap();
	
}
void GameWindow::clear()
{
	system("cls");
}
int GameWindow::isWinner() {
	if (this->end->isDie()) return 1;
	else return 0;
}
void GameWindow::redraw() {
	srand((unsigned)time(NULL));
	std::vector<std::pair<int, int>> pposs;
	std::vector<std::pair<int, int>> eposs;
	std::vector<std::pair<int, int>> cposs;
	std::vector<std::pair<int, int>> tposs;
	int cnt = 0;
	int cnt2 = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (map->map[i][j]) {
			case 'a':
				break;
			case 'b':
				int rd = rand() % 5;
				if (rd == 0) {
					map->map[i][j] = 'n';
					break;
				}
				if (rd == 1) {
					pposs.push_back({ i, j });
					break;
				}
				if (rd == 2) {
					eposs.push_back({ i, j });
					break;
				}
				if (rd == 3) {
					int x = i, y = j;
					bool canPush = false;
					for (int i = 0; i < 1; i++) {
						if (map->map[x - 1][y] != 'a' && map->map[x - 2][y] != 'a') {
							canPush = true;
						}
						else {
							canPush = false;
							break;
						}
						if (map->map[x + 1][y] != 'a' && map->map[x + 2][y] != 'a') {
							canPush = true;
						}
						else {
							canPush = false;
							break;
						}
						if (map->map[x][y - 1] != 'a' && map->map[x][y - 2] != 'a') {
							canPush = true;
						}
						else {
							canPush = false;
							break;
						}
						if (map->map[x][y + 1] != 'a' && map->map[x][y + 2] != 'a') {
							canPush = true;
						}
						else {
							canPush = false;
							break;
						}

					}
					if (canPush) {
						cposs.push_back({ i, j });
					}
					else {
						map->map[i][j] = 'n';
					}
					break;
				}
				if (rd == 4) {
					tposs.push_back({ i, j });
					break;
				}
			}
		}
	}
	int rd1 = rand() % pposs.size();
	int rd2 = rand() % eposs.size();
	int rd3 = rand() % cposs.size();
	int rd4 = rand() % tposs.size();
	map->map[pposs.at(rd1).first][pposs.at(rd1).second] = 'p';
	map->map[eposs.at(rd2).first][eposs.at(rd2).second] = 'e';
	map->map[cposs.at(rd3).first][cposs.at(rd3).second] = 'c';
	map->map[tposs.at(rd4).first][tposs.at(rd4).second] = 't';
	char p = map->map[pposs.at(rd1).first][pposs.at(rd1).second];
	char e = map->map[eposs.at(rd2).first][eposs.at(rd2).second];
	char c = map->map[cposs.at(rd3).first][cposs.at(rd3).second];
	char t = map->map[tposs.at(rd4).first][tposs.at(rd4).second];
	for (int i = 0; i < pposs.size(); i++) {
		if (map->map[pposs.at(i).first][pposs.at(i).second] != p) {
			map->map[pposs.at(i).first][pposs.at(i).second] = 'n';
		}
	}
	for (int i = 0; i < eposs.size(); i++) {
		if (map->map[eposs.at(i).first][eposs.at(i).second] != e) {
			map->map[eposs.at(i).first][eposs.at(i).second] = 'n';
		}
	}
	for (int i = 0; i < cposs.size(); i++) {
		if (map->map[cposs.at(i).first][cposs.at(i).second] != c) {
			map->map[cposs.at(i).first][cposs.at(i).second] = 'n';
		}
	}
	for (int i = 0; i < tposs.size(); i++) {
		if (map->map[tposs.at(i).first][tposs.at(i).second] != t) {
			map->map[tposs.at(i).first][tposs.at(i).second] = 'n';
		}
	}
}

void GameWindow::print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (map->map[i][j]) {
			case 'a':
				std::cout << "a";
				break;
			case 'p':
				std::cout << player->name;
				break;
			case 'e':
				std::cout << "e";
				break;
			case 'c':
				std::cout << "c";
				break;
			case 't':
				std::cout << "t";
				break;
			default:
				std::cout << " ";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void GameWindow::move(Player* player, char c) {
	int x = player->getX();
	int y = player->getY();
	int cmd = c;
	if (cmd == 'w' || cmd == 'W') {  // 向上：x 减少
		if (map->map[x - 1][y] == 'n') {
			player->setX(x - 1);
		}
		if (map->map[x - 1][y] == 't') {
			map->map[x][y] = 'n';
		}
		if (map->map[x - 1][y] == 'c') {
			if (map->map[x - 2][y] == 'n') {
				chest->setX(x - 2);
				player->setX(x - 1);
			}
			if (map->map[x - 2][y] == 'e') {
				player->setX(x - 1);
				map->map[x - 2][y] = 'n';
			}
		}
	}
	if (cmd == 's' || cmd == 'S') {  // 向下：x 增加
		if (map->map[x + 1][y] == 'n') {
			player->setX(x + 1);
		}
		if (map->map[x + 1][y] == 't') {
			map->map[x][y] = 'n';
		}
		if (map->map[x + 1][y] == 'c') {
			if (map->map[x + 2][y] == 'n') {
				chest->setX(x + 2);
				player->setX(x + 1);
			}
			if (map->map[x + 2][y] == 'e') {
				player->setX(x + 1);
				map->map[x + 2][y] = 'n';
			}
		}
	}
	if (cmd == 'a' || cmd == 'A') {  // 向左：y 减少
		if (map->map[x][y - 1] == 'n') {
			player->setY(y - 1);
		}
		if (map->map[x][y - 1] == 't') {
			map->map[x][y] = 'n';
		}
		if (map->map[x][y - 1] == 'c') {
			if (map->map[x][y - 2] == 'n') {
				chest->setY(y - 2);
				player->setY(y - 1);
			}
			if (map->map[x][y - 2] == 'e') {
				player->setY(y - 1);
				map->map[x][y - 2] = 'n';
			}
		}
	}
	if (cmd == 'd' || cmd == 'D') {  // 向右：y 增加
		if (map->map[x][y + 1] == 'n') {
			player->setY(y + 1);
		}
		if (map->map[x][y + 1] == 't') {
			map->map[x][y] = 'n';
		}
		if (map->map[x][y + 1] == 'c') {
			if (map->map[x][y + 2] == 'n') {
				chest->setY(y + 2);
				player->setY(y + 1);
			}
			if (map->map[x][y + 2] == 'e') {
				player->setY(y + 1);
				map->map[x][y + 2] = 'n';
			}
		}
	}
}

int GameWindow::nameIsTrue(char name) {
	if (name == 'a' || name == 'e' || name == 'c' || name == 't' ||  name == '\r' || name == '\n') return 0;
	return 1;
}

void GameWindow::killMaximize(HWND hwnd) {

}

int GameWindow::isGameOver() {
	if (this->trap->isPlayerDie()) return 1;
	else return 0;
}
