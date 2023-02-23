#include <iostream>
using namespace std;

#pragma once
class Player
{
public:
	char cNumber = '0';

	int nStartPointRow = 0;
	int nStartPointCol = 0;

	int nCurrentPointRow = 0;
	int nCurrentPointCol = 0;

	int countWin;

	// constructor
	Player();
	Player(char num, int row, int col);

	// methods
	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

	void addWin();

	int getWin();
};

