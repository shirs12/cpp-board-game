#include<iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

/*
* matrix 30x30
* 2 players
* winning rectangle somewhere in the matrix.
*/

// move player on board
void movePlayer(int& num, Player& player, Board& board) {
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

	board.placePlayer(player.cNumber, player.nCurrentPointRow, player.nCurrentPointCol, curRow, curCol);
}

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

	int winningMatRow;
	int winningMatCol;
	int winningMatHeight;
	int winningMatWidth;

	int playerMoveChoice;

	bool firstTurnFlag = true;
	bool secondTurnFlag = false;

	bool firstWinningFlag = false;
	bool secondWinningFlag = false;

#pragma endregion

#pragma region User Input - Initial Board & Players
	while (choice != 2)
	{
		cout << "Welcome!" << endl;
		cout << "Menu:"
			"\n1. start the game"
			"\n2. Exit"
			"\nEnter your choice: ";
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
			cout << "First player starting point\nenter row: ";
			cin >> firstPlayerRow;
			cout << "\nenter colomn: ";
			cin >> firstPlayerCol;
			cout << endl;

			Player firstPlayer('1', firstPlayerRow, firstPlayerCol);
			board.initPlayer(firstPlayer.cNumber, firstPlayer.nCurrentPointRow, firstPlayer.nCurrentPointCol);

			board.printBoard();

			// input row and col from user - second plyer
			cout << "\nSecond player starting point\nenter row: ";
			cin >> secondPlayerRow;
			cout << "\nenter colomn: ";
			cin >> secondPlayerCol;
			cout << endl;

			Player secondPlayer('2', secondPlayerRow, secondPlayerCol);
			board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);

			board.printBoard();

			// input row and col from user - winning mat
			cout << "Winning mat's top-left corner point\nenter row: ";
			cin >> winningMatRow;
			cout << "\nenter colomn: ";
			cin >> winningMatCol;
			cout << endl;

			// input dimentions from user - winning mat
			cout << "\nWinning mat's dimentions\nenter height: ";
			cin >> winningMatHeight;
			cout << "\nenter width: ";
			cin >> winningMatWidth;
			cout << endl;

			board.initWinningMat(winningMatRow, winningMatCol, winningMatHeight, winningMatWidth);

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

					movePlayer(playerMoveChoice, firstPlayer, board);

					if (board.placePlayer(firstPlayer.cNumber, firstPlayer.nCurrentPointRow, firstPlayer.nCurrentPointCol, firstPlayerRow, firstPlayerCol))
					{
						cout << "game over" << endl;
						firstWinningFlag = true;
					}
				}
				else if (secondTurnFlag && !firstTurnFlag && !firstWinningFlag && !secondWinningFlag)
				{
					secondPlayerRow = secondPlayer.nCurrentPointRow;
					secondPlayerCol = secondPlayer.nCurrentPointCol;

					movePlayer(playerMoveChoice, secondPlayer, board);

					if (board.placePlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol, secondPlayerRow, secondPlayerCol))
					{
						cout << "game over" << endl;
						secondWinningFlag = true;
					}
				}

				board.printBoard();

				switchTurns(firstTurnFlag, secondTurnFlag);

			}
		}
	}
	
	cout << "You chose to exit the game..." << endl;

}

