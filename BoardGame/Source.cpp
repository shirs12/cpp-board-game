#include<iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

/*
* matrix 30x30
* 2 players
* rectangle somewhere in the matrix to reach.
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

	while (row <= 0 || col <= 0 || row >= board.SIZE - 1 || col >= board.SIZE - 1)
	{
		cout << "Out of bounds. Please try again" << endl;
		cout << "enter row: ";
		cin >> row;
		cout << "enter colomn: ";
		cin >> col;
		cout << endl;
	}

	Player player(cNum, row, col);
	
	return player;
}

// input victory-island from user
void inputVictoryIsland(Board& board) {
	int row = -1;
	int col = -1;
	int height = -1;
	int width = -1;

	bool isInBorder = board.initVictoryIsland(row, col, height, width);

	while (!isInBorder)
	{
		cout << "Enter Victory-Island's top-left corner point\nenter row: ";
		cin >> row;
		cout << "enter colomn: ";
		cin >> col;
		cout << endl;

		// input dimentions from user - victory-island
		cout << "Enter Victory-Island's dimentions\nenter height: ";
		cin >> height;
		cout << "enter width: ";
		cin >> width;
		cout << endl;

		isInBorder = board.initVictoryIsland(row, col, height, width);

		if (!isInBorder)
		{
			cout << "Out of bounds. Please try again\n" << endl;
		}
	}
	cout << "Victory-Island placed on board successfully." << endl;
	board.initVictoryIsland(row, col, height, width);
}

// switch-case for the user's input direction
void switchDirection(int num, Player& player) {
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
}

// move player on board
bool movePlayer(int& num, Player& player, Board& board) {
	int curRow = player.nCurrentPointRow;
	int curCol = player.nCurrentPointCol;

	int otherNum = 0;
	bool isAlreadyPlaced = false;

	switchDirection(num, player);

	isAlreadyPlaced = board.isOtherPlayerPoint(player.nCurrentPointRow, player.nCurrentPointCol);

	while (isAlreadyPlaced)
	{
		player.nCurrentPointRow = curRow;
		player.nCurrentPointCol = curCol;

		board.printBoard();

		cout << "Other player is already at that point."
			"\nTry a different direction (1-up, 2-down, 3-right, 4-left):" << endl;
		cin >> otherNum;

		switchDirection(otherNum, player);

		isAlreadyPlaced = board.isOtherPlayerPoint(player.nCurrentPointRow, player.nCurrentPointCol);
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

	bool isPointEmpty = false;

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

			// input row and col from user - second player
			cout << "\nSecond player starting point" << endl;

			Player secondPlayer = inputPlayerPoint('2', board);
			isPointEmpty = board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);

			// if second player entered the same input as first player
			while (!isPointEmpty)
			{
				cout << "Please try again" << endl;
				secondPlayer = inputPlayerPoint('2', board);
				isPointEmpty = board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);
			}

			board.printBoard();

			inputVictoryIsland(board);

#pragma endregion

			board.printBoard();

			cout << "Player 1" << endl;

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
						cout << "Player 2" << endl;
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
						cout << "Player 1" << endl;
					}
				}

				switchTurns(firstTurnFlag, secondTurnFlag);
			}
		}

		// restarting game
		board.clearBoard();

		firstTurnFlag = true;
		secondTurnFlag = false;
		firstWinningFlag = false;
		secondWinningFlag = false;
	}
	
	cout << "You chose to exit the game..." << endl;

}

