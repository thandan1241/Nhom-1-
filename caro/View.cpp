#include "View.h"


/*void Outray(int matrix[BoardSize][BoardSize]) {
	for (int i = 0; i < BoardSize; i++) {
		for (int h = 0; h < BoardSize; h++) {
			cout << matrix[i][h] << " ";
		}
		cout << "\n";
	}
}*/ //Testing tool

//Drawing
void GotoXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void DrawBoard(int size,COORD StartingCoord) {
	COORD currentpos = { StartingCoord.X,StartingCoord.Y };
	int totalborder = size + 1;
	for (int i = 0; i < totalborder; i++) {
		if(i!=0) currentpos.Y += 2;
		currentpos.X = StartingCoord.X;
		for (int h = 0; h < totalborder-1; h++) {
			
			GotoXY(currentpos.X, currentpos.Y);
			if ((i == 0) && (h == 0)) cout << TopLeft << Horizontal << Horizontal << Horizontal << UpCross;
			else if ((i == totalborder - 1) && (h == 0)) cout << BotLeft << Horizontal << Horizontal << Horizontal << DownCross;
			else if ((i == 0) && (h == totalborder - 2)) cout << UpCross << Horizontal << Horizontal << Horizontal << TopRight;
			else if ((i == totalborder - 1) && (h == totalborder - 2)) cout << DownCross << Horizontal << Horizontal << Horizontal << BotRight;
			else if (h == 0) cout << LeftCross << Horizontal << Horizontal << Horizontal << Cross;
			else if (h == totalborder-2) cout << Cross << Horizontal << Horizontal << Horizontal << RightCross;
			else if (i == 0) cout << UpCross << Horizontal << Horizontal << Horizontal << UpCross;
			else if (i == totalborder-1)  cout << DownCross << Horizontal << Horizontal << Horizontal << DownCross;
			else cout << Cross << Horizontal << Horizontal << Horizontal << Cross;
			currentpos.X += 4;
		}
		currentpos.X = StartingCoord.X;
		if (i != totalborder - 1) {
			for (int h = 0; h < totalborder - 1; h++) {
				GotoXY(currentpos.X, currentpos.Y + 1);
				cout << Vertical << "   " << Vertical;
				currentpos.X += 4;
			}
		}
		
	}

	
	
}