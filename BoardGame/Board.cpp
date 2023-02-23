#include "Board.h"

// constructor
Board::Board() {
	// initialize top border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[0][i] = '#';
	}

	// initialize left border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[i][0] = '#';
	}

	// initialize bottom border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[sizeof(matrix[i]) - 1][i] = '#';
	}

	// initialize right border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[i][sizeof(matrix[i]) - 1] = '#';
	}

	// initialize center of board game
	for (int i = 1; i < sizeof(matrix[i]) - 1; i++)
	{
		for (int j = 1; j < sizeof(matrix[j]) - 1; j++)
		{
			matrix[i][j] = ' ';
		}
	}

}

// methods:

// initialize player's point on board
bool Board::initPlayer(char num, int row, int col) {
	if (row < 1 || row > (SIZE - 2) || col < 1 || col > (SIZE - 2))
	{
		cout << "Out of bounds." << endl;
		return false;
	}
	else if (matrix[row][col] != ' ')
	{
		cout << "Other player is already placed at this point." << endl;
		return false;
	}
	else
	{
		matrix[row][col] = num;
		cout << "player placed on board successfully." << endl;
		return true;
	}
	return false;
}

// checks if victory-island can be placed - there is no player in that area
bool Board::isEmptyArea(int row, int col, int height, int width) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (matrix[row + i][col + j] != ' ' && matrix[row + i][col + j] != '#' && matrix[row + i][col + j] != '*')
			{
				cout << "Victory-Island can not be placed where player is already placed." << endl;
				return false;
			}
		}
	}
	return true;
}

// initialize victory-island on board
bool Board::initVictoryIsland(int row, int col, int height, int width) {

	bool empty = isEmptyArea(row, col, height, width);

	if (row < 1 || row > (SIZE - 2) || col < 1 || col > (SIZE - 2)
		|| (row + height) > (SIZE - 1) || (col + width) > (SIZE - 1) || !empty)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (matrix[row + i][col + j] != '#')
				{
					matrix[row + i][col + j] = '*';
				}
			}
		}
		return true;
	}
	return false;
}

//  checks if other player is already at the given point
bool Board::isOtherPlayerPoint(int row, int col) {
	if (matrix[row][col] != '*' && matrix[row][col] != ' ' && matrix[row][col] != '#')
	{
		return true;
	}
	return false;
}

// initialize player's point on board
bool Board::placePlayer(char num, int curRow, int curCol, int row, int col) {
	if (row < 1 || row > (SIZE - 2) || col < 1 || col > (SIZE - 2))
	{
		cout << "Out of bounds." << endl;
		return false;
	}
	else if (isAtVictoryIsland(curRow, curCol))
	{
		matrix[curRow][curCol] = num;
		matrix[row][col] = ' ';
		printBoard();
		cout << "\nPlayer "<< num << " found the victory-island and won this round!" << endl;
		return true;
	}
	else
	{
		matrix[curRow][curCol] = num;
		matrix[row][col] = ' ';
		cout << endl;
		return false;
	}
	return false;
}

// checks if one of the players won
bool Board::isAtVictoryIsland(int row, int col) {
	if (matrix[row][col] == '*')
	{
		return true;
	}
	return false;
}

void Board::clearBoard() {
	// initialize top border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[0][i] = '#';
	}

	// initialize left border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[i][0] = '#';
	}

	// initialize bottom border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[sizeof(matrix[i]) - 1][i] = '#';
	}

	// initialize right border of board game
	for (int i = 0; i < sizeof(matrix[i]); i++)
	{
		matrix[i][sizeof(matrix[i]) - 1] = '#';
	}

	// initialize center of board game
	for (int i = 1; i < sizeof(matrix[i]) - 1; i++)
	{
		for (int j = 1; j < sizeof(matrix[j]) - 1; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

// print matrix
void Board::printBoard() {
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;  // Newline for new row
	}

	cout << endl;
}


