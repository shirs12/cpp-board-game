#include <iostream>
using namespace std;

#pragma once
class Board
{
private:

	// TODO: change matrix to 31x31 dimensions.
	char matrix[11][11] = {};

	const int SIZE = sizeof(matrix[0]);

public:

	// constructor
	Board();

	// methods:

	// initialize player's point on board
	void initPlayer(char num, int row, int col);

	// initialize winning-mat on board
	void initWinningMat(int row, int col, int height, int width);

	// place player's point on board after moving
	void placePlayer(char num, int curRow, int curCol, int row, int col);

	//checks if one of the players won
	bool isOnWinningMat(int row, int col);

	// print matrix
	void printBoard();
};

