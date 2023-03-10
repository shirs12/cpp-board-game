#include "Player.h"

// constructor
Player::Player() {

}

Player::Player(char num, int row, int col) {
	countWin = 0;
	cNumber = num;

	if (row < 0 || col < 0)
	{
		cout << "Out of bounds." << endl;
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
		cout << "Out of bounds." << endl;
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
		cout << "Out of bounds." << endl;
	}
	else
	{
		nCurrentPointCol--;
	}
}

void Player::moveRight() {
	nCurrentPointCol++;
}

void Player::addWin() {
	countWin++;
}

int Player::getWin() {
	return countWin;
}

