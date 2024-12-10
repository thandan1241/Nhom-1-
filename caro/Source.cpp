#include <iostream>
#include "View.h"
#include <conio.h>
#include "control.h"
#include "handle.h"
using namespace std;

void PlayAgainMenu() {
    GotoXY(31, 27);
    cout << "Do you want to play again? (Y/N): ";
}

int main() {
    int result = 0;
    int array[BoardSize][BoardSize] = {};
    bool Turn = true; // true = X's turn, false = O's turn
    char Input;
    COORD current = StartPoint;

    do {
        DrawBoard(BoardSize, CaroTopLeft); // V? bàn c?
        GotoXY(current.X, current.Y); // Di chuy?n con tr? ??n v? trí b?t ??u

        while (true) {
            Input = toupper(_getch()); // ??c ký t? t? bàn phím
            if ((Input == 'W') && (current.Y != StartPoint.Y)) MoveUp(current);
            if ((Input == 'S') && (current.Y != StartPoint.Y + 2 * (BoardSize - 1))) MoveDown(current);
            if ((Input == 'A') && (current.X != StartPoint.X)) MoveLeft(current);
            if ((Input == 'D') && (current.X != StartPoint.X + 4 * (BoardSize - 1))) MoveRight(current);
            if ((Input == 13) && (array[(current.Y == StartPoint.Y) ? 0 : ((current.Y - StartPoint.Y) / 2)][(current.X - StartPoint.X) / 4] == 0)) {
                CheckBoard(current, array, Turn);
                result = WinCheck(current, array, Turn);
                if (result != 0) {
                    GotoXY(30, 26);
                    cout << (Turn ? "X Wins!" : "O Wins!"); // Hi?n th? ng??i th?ng
                    break; // Thoát vòng l?p ?? h?i ch?i l?i
                }
                if (IsDraw(array)) {
                    GotoXY(30, 26);
                    cout << "Draw!"; // Hi?n th? hòa
                    break; // Thoát vòng l?p ?? h?i ch?i l?i
                }
                Turn = !Turn; // Chuy?n l??t
            }
        }

        // H?i ng??i ch?i có mu?n ch?i l?i không
        PlayAgainMenu();
        char playAgain;
        cin >> playAgain; // ??c ??u vào t? ng??i ch?i
        if (toupper(playAgain) == 'Y') {
            system("cls"); // Xóa màn hình
            fill(&array[0][0], &array[0][0] + sizeof(array) / sizeof(int), 0); // ??t l?i bàn c?
            Turn = true; // ??t l?i l??t
            current = StartPoint; // ??t l?i v? trí con tr?
        }
        else {
            cout << "Thanks for playing!" << endl; // C?m ?n ng??i ch?i
            break; // Thoát kh?i vòng l?p chính
        }
    } while (true);

    return 0; // K?t thúc ch??ng trình
}