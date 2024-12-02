#pragma once
#include <Windows.h>
#include <iostream>

//Const
const COORD CaroTopLeft = { 0,0 };
const COORD StartPoint = { CaroTopLeft.X + 2,CaroTopLeft.Y + 1 };
const int BoardSize = 12;
//ASCII characters for board-drawing
#define Vertical (char)186
#define Horizontal (char)205
#define Cross (char)206
#define UpCross (char)203
#define LeftCross (char)204
#define RightCross (char)185
#define DownCross (char)202
#define TopLeft (char)201
#define BotLeft (char)200
#define TopRight (char)187
#define BotRight (char)188
using namespace std;

//Func

//void Outray(int matrix[BoardSize][BoardSize]); Testing func

//Drawing
void GotoXY(int x, int y);

void DrawBoard(int size,COORD StartingCoord);

void hidecursor();


