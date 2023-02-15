#include "Player.h"

// constructor
Player::Player(char num, int row, int col) {
	cNumber = num;

	if (row < 0 || col < 0)
	{
		cout << "Out of border." << endl;
		return;
	}

	nStartPointRow = row;
	nStartPointCol = col;
	nCurrentPointRow = row;
	nCurrentPointCol = col;
}

// methods

void Player::moveUp() {
	int num = nCurrentPointRow;
	if (num-- < 0)
	{
		cout << "Out of border." << endl;
	}
	else
	{
		nCurrentPointRow--;
	}
}

void Player::moveDown() {
	nCurrentPointRow++;
}

void Player::moveLeft() {
	int num = nCurrentPointCol;
	if (num-- < 0)
	{
		cout << "Out of border." << endl;
	}
	else
	{
		nCurrentPointCol--;
	}
}

void Player::moveRight() {
	nCurrentPointCol++;
}


