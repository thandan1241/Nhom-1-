#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "View.h"
using namespace std;

//Func
//Actions on Chessboard
void MoveUp(COORD &x);

void MoveDown(COORD& x);

void MoveLeft(COORD& x);

void MoveRight(COORD& x);

void CheckBoard(const COORD& position, int matrix[BoardSize][BoardSize], bool turn);