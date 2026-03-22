#pragma once
#include "Player.h"
#include "Map.h"
#include "End.h"
#include "Chest.h"
#include "Trap.h"
#include <Windows.h>
class GameWindow
{
public:
	GameWindow();
	void clear();
	int isWinner();
	int isGameOver();
	void move(Player* player, char c);
	void redraw();
	void print();
	int nameIsTrue(char name);
	void killMaximize(HWND hwnd);

	Player* player;
	End* end;
	Chest* chest;
	Trap* trap;
};

