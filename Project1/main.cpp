#include <iostream>
#include "GameWindow.h"
#include <conio.h>

int main()
{
	HWND hwnd = GetConsoleWindow();
	GameWindow* gameWindow = new GameWindow();
	gameWindow->killMaximize(hwnd); // 无用代码
	std::cout << "                                               Game Will Start\n";
	std::cout << "Press Enter to start";
	char startGame = _getch();
	while (startGame != '\r') {
		startGame = _getch();
	}
	gameWindow->clear();
	std::cout << "Please enter player name(one char): ";
	char name;
	std::cin >> name;
	int isNameTrue = gameWindow->nameIsTrue(name);
	while (isNameTrue == 0) {
		gameWindow->clear();
		std::cout << "Invalid name, please enter another one (one char): ";
		std::cin >> name;
		isNameTrue = gameWindow->nameIsTrue(name);
	}
	gameWindow->player->setName(name);
	gameWindow->clear();
	gameWindow->print();
	while (1) {
		if (gameWindow->isWinner()) {
			gameWindow->clear();
			std::cout << "You win!" << std::endl;
			break;
		}
		char cmd = _getch();
		gameWindow->move(gameWindow->player, cmd);
		gameWindow->clear();
		gameWindow->print();
	}
	return 0;
}