#include<iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

/*
* matrix 30x30
* 2 players
* winning rectangle somewhere in the matrix.
* top-left corner of the winning rectangle -> input
* height and width of the winning rectangle -> input
* 2 start points for every player -> input
*
*/

// move player on board
void movePlayer(int num, Player player, Board board) {
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

void switchTurns(bool flag1, bool flag2) {
	flag1 = !flag1;
	flag2 = !flag2;
}

int main() {

#pragma region Variables Declaration
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

	board.printBoard();

#pragma region User Input - Initial Board & Players

	// input row and col from user - first player
	cout << "Enter first player starting point,\nenter row: " << endl;
	cin >> firstPlayerRow;
	cout << "\nenter colomn: " << endl;
	cin >> firstPlayerCol;

	Player firstPlayer('1', firstPlayerRow, firstPlayerCol);
	board.initPlayer(firstPlayer.cNumber, firstPlayer.nCurrentPointRow, firstPlayer.nCurrentPointCol);

	board.printBoard();

	// input row and col from user - second plyer
	cout << "Enter second player starting point,\nenter row: " << endl;
	cin >> secondPlayerRow;
	cout << "\nenter colomn: " << endl;
	cin >> secondPlayerCol;

	Player secondPlayer('2', secondPlayerRow, secondPlayerCol);
	board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);

	board.printBoard();

	// input row and col from user - winning mat
	cout << "Enter winning mat's top-left corner point,\nenter row: " << endl;
	cin >> winningMatRow;
	cout << "\nenter colomn: " << endl;
	cin >> winningMatCol;

	// input dimentions from user - winning mat
	cout << "Enter winning mat's dimentions,\nenter height: " << endl;
	cin >> winningMatHeight;
	cout << "\nenter width: " << endl;
	cin >> winningMatWidth;

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

