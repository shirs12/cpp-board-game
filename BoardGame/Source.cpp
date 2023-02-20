#include<iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

/*
* matrix 30x30
* 2 players
* winning rectangle somewhere in the matrix.
*/

// input row and col from user
Player inputPlayerPoint(char cNum, Board& board) {
	int row = -1;
	int col = -1;

	cout << "enter row: ";
	cin >> row;
	cout << "enter colomn: ";
	cin >> col;
	cout << endl;

	while (row <= 0 || col <= 0 || row >= board.SIZE || col >= board.SIZE)
	{
		cout << "Out of border. Please try again" << endl;
		cout << "enter row: ";
		cin >> row;
		cout << "\nenter colomn: ";
		cin >> col;
		cout << endl;
	}

	Player player(cNum, row, col);
	
	return player;
}

// input winning mat from user
void inputWinningMat(Board& board) {
	int row = -1;
	int col = -1;
	int height = -1;
	int width = -1;

	while (row <= 0 || col <= 0 || height <= 0 || width <= 0)
	{
		cout << "Winning mat's top-left corner point\nenter row: ";
		cin >> row;
		cout << "\nenter colomn: ";
		cin >> col;
		cout << endl;

		// input dimentions from user - winning mat
		cout << "\nWinning mat's dimentions\nenter height: ";
		cin >> height;
		cout << "\nenter width: ";
		cin >> width;
		cout << endl;

		if (row <= 0 || col <= 0 || height <= 0 || width <= 0)
		{
			cout << "Out of border. Please try again" << endl;
		}
	}

	board.initWinningMat(row, col, height, width);
}

// move player on board
bool movePlayer(int& num, Player& player, Board& board) {
	int curRow = player.nCurrentPointRow;
	int curCol = player.nCurrentPointCol;

	switch (num)
	{
	case(1):
		player.moveUp();
		break;

	case(2):
		player.moveDown();
		break;

	case(3):
		player.moveRight();
		break;

	case(4):
		player.moveLeft();
		break;

	default:
		break;
	}

	return board.placePlayer(player.cNumber, player.nCurrentPointRow, player.nCurrentPointCol, curRow, curCol);
}

// switch players turns flags
void switchTurns(bool& flag1, bool& flag2) {
	flag1 = !flag1;
	flag2 = !flag2;
}

int main() {

#pragma region Variables Declaration
	int choice = 0;

	Board board;

	int firstPlayerRow;
	int firstPlayerCol;

	int secondPlayerRow;
	int secondPlayerCol;

	int playerMoveChoice;

	bool firstTurnFlag = true;
	bool secondTurnFlag = false;

	bool firstWinningFlag = false;
	bool secondWinningFlag = false;

#pragma endregion

#pragma region User Input - Initial Board & Players

	cout << "Welcome!\n" << endl;

	while (choice != 2)
	{
		cout << "Menu:"
			"\n1. start the game"
			"\n2. Exit"
			"\n\nEnter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice > 2 || choice < 1)
		{
			cout << "Wrong choice." << endl;
		}
		else if (choice == 1)
		{
			cout << "You chose to play!\n" << endl;

			cout << "The game board is empty, you need to fill it up" << endl;
			board.printBoard();

			// input row and col from user - first player
			cout << "First player starting point" << endl;

			Player firstPlayer = inputPlayerPoint('1', board);
			board.initPlayer(firstPlayer.cNumber, firstPlayer.nCurrentPointRow, firstPlayer.nCurrentPointCol);

			board.printBoard();

			// input row and col from user - second plyer
			cout << "\nSecond player starting point" << endl;

			Player secondPlayer = inputPlayerPoint('2', board);
			board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);

			board.printBoard();

			inputWinningMat(board);

#pragma endregion

			board.printBoard();

			while (!firstWinningFlag && !secondWinningFlag)
			{
				cout << "Please enter your step: \n"
					"1 - Up\n"
					"2 - Down\n"
					"3 - Right\n"
					"4 - Left\n"
					<< endl;
				cin >> playerMoveChoice;

				if (firstTurnFlag && !secondTurnFlag && !firstWinningFlag && !secondWinningFlag)
				{
					firstPlayerRow = firstPlayer.nCurrentPointRow;
					firstPlayerCol = firstPlayer.nCurrentPointCol;

					firstWinningFlag = movePlayer(playerMoveChoice, firstPlayer, board);

					if (firstWinningFlag)
					{
						cout << "game over\n" << endl;
					}
					else
					{
						board.printBoard();
					}
				}
				else if (secondTurnFlag && !firstTurnFlag && !firstWinningFlag && !secondWinningFlag)
				{
					secondPlayerRow = secondPlayer.nCurrentPointRow;
					secondPlayerCol = secondPlayer.nCurrentPointCol;

					secondWinningFlag = movePlayer(playerMoveChoice, secondPlayer, board);

					if (secondWinningFlag)
					{
						cout << "game over\n" << endl;
					}
					else
					{
						board.printBoard();
					}
				}

				switchTurns(firstTurnFlag, secondTurnFlag);

			}
		}
	}
	
	cout << "You chose to exit the game..." << endl;

}

