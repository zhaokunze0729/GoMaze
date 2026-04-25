#include <iostream>
#include "GameWindow.h"
#include "getch_linux.h"

int main()
{
	GameWindow* gameWindow = new GameWindow();
	std::cout << "                                               Game Will Start\n";
	std::cout << "Press Enter to start";
	char startGame = _getch();
	while (startGame != '\n' && startGame != '\r') {
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
		if (gameWindow->isGameOver()) {
			gameWindow->clear();
			std::cout << "Game Over!" << std::endl;
			break;
		}
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
