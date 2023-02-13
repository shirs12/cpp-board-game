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

void movePlayer(int num) {
	switch (num)
	{
	case(1):

		break;

	default:
		break;
	}
}

int main() {

	Board board;

	int firstPlayerRow;
	int firstPlayerCol;

	int secondPlayerRow;
	int secondPlayerCol;

	// input the row and col from user
	Player firstPlayer('1', firstPlayerRow, firstPlayerCol);
	board.initPlayer(firstPlayer.cNumber, firstPlayer.nCurrentPointRow, firstPlayer.nCurrentPointCol);

	// input the row and col from user
	Player secondPlayer('2', firstPlayerRow, firstPlayerCol);
	board.initPlayer(secondPlayer.cNumber, secondPlayer.nCurrentPointRow, secondPlayer.nCurrentPointCol);

	board.initWinningMat()

		switch ()
		{
		case(1):

			break;

		default:
			break;
		}
}