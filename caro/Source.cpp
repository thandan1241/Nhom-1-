#include <iostream>
#include "View.h"
#include <conio.h>
#include "control.h"
#include "handle.h"
using namespace std;


int main() {
	int result = 0;
	int array[BoardSize][BoardSize] = {};
	bool Turn = true; //true= X.turn false= O.turn
	char Input;
	COORD current = StartPoint;
	DrawBoard(BoardSize, CaroTopLeft);
	GotoXY(current.X, current.Y);
	while (1 == 1) {
		Input = toupper(_getch());
		if ((Input == 'W') && (current.Y != StartPoint.Y)) MoveUp(current);
		if ((Input == 'S') && (current.Y != StartPoint.Y+2*(BoardSize-1))) MoveDown(current);
		if ((Input == 'A') && (current.X != StartPoint.X)) MoveLeft(current);
		if ((Input == 'D') && (current.X != StartPoint.X+4*(BoardSize-1))) MoveRight(current);
		if ((Input == 13) && (array [(current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2)][(current.X - StartPoint.X) / 4] == 0)) {
			CheckBoard(current, array, Turn);
			result = WinCheck(current, array, Turn);
			if (result != 0) {
				GotoXY(30, 26);
				if (Turn == true) cout << "x Win";
				else cout << "o Win";
				break;
			}
			if (IsDraw(array) == true) {
				GotoXY(30, 26);
				cout << " Draw";
				break;
			}
			if (Turn == true) Turn = false;
			else Turn = true;
		}
		//if (Input == 32) break;
	}
	return 0;
}