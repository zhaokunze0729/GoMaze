#pragma once
class Player
{
public:
	Player();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setName(char name);
	int x;
	int y;
	char name = 'p';
};

