#include "handle.h"

//Win Conditions
int dia1(COORD current, int matrix[BoardSize][BoardSize], bool turn) {
	int count = 0;
	int Col = (current.X - StartPoint.X) / 4;
	int Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Row >= 0) && (Col <= BoardSize - 1) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row--;
		Col++;
	}
	Col = (current.X - StartPoint.X) / 4;
	Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Col >= 0) && (Row <= BoardSize - 1) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row++;
		Col--;
	}
	count -= 1;
	if (count >= 5) {
		if (turn == true) return 1;
		else return -1;
	}
	else return 0;
}

int dia2(COORD current, int matrix[BoardSize][BoardSize], bool turn) {
	int count = 0;
	int Col = (current.X - StartPoint.X) / 4;
	int Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Row >= 0) && (Col >= 0) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row--;
		Col--;
	}
	Col = (current.X - StartPoint.X) / 4;
	Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Col <= BoardSize -1) && (Row <= BoardSize - 1) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row++;
		Col++;
	}
	count -= 1;
	if (count >= 5) {
		if (turn == true) return 1;
		else return -1;
	}
	else return 0;
}

int vertical(COORD current, int matrix[BoardSize][BoardSize], bool turn) {
	int count = 0;
	int Col = (current.X - StartPoint.X) / 4;
	int Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Row >= 0) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row--;
	}
	Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Row <= BoardSize - 1) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Row++;
	}
	count -= 1;
	if (count >= 5) {
		if (turn == true) return 1;
		else return -1;
	}
	else return 0;
}

int horizontal(COORD current, int matrix[BoardSize][BoardSize], bool turn) {
	int count = 0;
	int Col = (current.X - StartPoint.X) / 4;
	int Row = (current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2);
	while ((Col >= 0) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Col--;
	}
	Col = (current.X - StartPoint.X) / 4;
	while ((Col <= BoardSize - 1) && (matrix[Row][Col] == ((turn == true) ? 1 : -1))) {
		count++;
		Col++;
	}
	count -= 1;
	if (count >= 5) {
		if (turn == true) return 1;
		else return -1;
	}
	else return 0;
}

//Win-Draw Check
int WinCheck(COORD current, int matrix[BoardSize][BoardSize], bool turn) {
	int result = 0;
	result = dia1(current, matrix, turn);
	if (result != 0) return result;
	result = dia2(current, matrix, turn);
	if (result != 0) return result;
	result = vertical(current, matrix, turn);
	if (result != 0) return result;
	result = horizontal(current, matrix, turn);
	if (result != 0) return result;
}

bool IsDraw(int matrix[BoardSize][BoardSize]) {
	int space = 0;
	for (int i = 0; i < BoardSize; i++) {
		for (int h = 0; h < BoardSize; h++) {
			if (matrix[i][h] == 0) space++;
		}
	}
	if (space==0) return true;
	return false;
}
