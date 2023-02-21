#include <iostream>
using namespace std;

#pragma once
class Board
{
private:

	// TODO: change matrix to 31x31 dimensions.
	char matrix[11][11] = {};


public:

	const int SIZE = sizeof(matrix[0]);

	// constructor
	Board();

	// methods:

	// initialize player's point on board
	bool initPlayer(char num, int row, int col);

	// checks if victory-island can be placed - there is no player in that area
	bool isEmptyArea(int row, int col, int height, int width);

	// initialize winning-mat on board
	bool initWinningMat(int row, int col, int height, int width);

	// place player's point on board after moving
	bool placePlayer(char num, int curRow, int curCol, int row, int col);

	// checks if one of the players won
	bool isOnWinningMat(int row, int col);

	// print matrix
	void printBoard();
};

