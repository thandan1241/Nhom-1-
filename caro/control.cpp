#include "control.h"

//Actions on Checkboard
void MoveUp(COORD &x) {
	x.Y -= 2;
	GotoXY(x.X, x.Y);
}

void MoveDown(COORD& x) {
	x.Y += 2;
	GotoXY(x.X, x.Y);
}

void MoveLeft(COORD& x) {
	x.X -= 4;
	GotoXY(x.X, x.Y);
}

void MoveRight(COORD& x) {
	x.X += 4;
	GotoXY(x.X, x.Y);
}

void CheckBoard(const COORD& position, int matrix[BoardSize][BoardSize], bool turn) {
	matrix[(position.Y == StartPoint.Y) ? 0 : ((position.Y - StartPoint.Y)/2)][(position.X - StartPoint.X) / 4] = (turn == true) ? 1 : -1;
		if (turn == true)  cout << "x";
		else cout << "o";
}