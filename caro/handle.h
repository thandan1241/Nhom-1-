#pragma once
#include <iostream>
#include <Windows.h>
#include "View.h"
using namespace std;

//Func
//Win Conditions
int dia1(COORD current, int matrix[BoardSize][BoardSize], bool turn);

int dia2(COORD current, int matrix[BoardSize][BoardSize], bool turn);

int vertical(COORD current, int matrix[BoardSize][BoardSize], bool turn);

int horizontal(COORD current, int matrix[BoardSize][BoardSize], bool turn);
//Win-Draw Check
int WinCheck(COORD current, int matrix[BoardSize][BoardSize], bool turn);

bool IsDraw(int matrix[BoardSize][BoardSize]);