#include "Player.h"
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Player::Player(int x, int y) {
    this->prevX = x;
    this->prevY = y;
    this->x = x;
    this->y = y;
}

void Player::move(int dir, Maze m) {
    this->prevX = this->x;
    this->prevY = this->y;

    int dirX = 0;
    int dirY = 0;

    switch (dir) {
        case 0:
            dirX = -1;
            break;
        case 1:
            dirX = 1;
            break;
        case 2:
            dirY = -1;
            break;
        case 3:
            dirY = 1;
            break;
    }

    int nextX = this->x + dirX;
    int nextY = this->y + dirY;

    if (m.grid[nextX][nextY] == 1) {
        this->x = nextX;
        this->y = nextY;
    }
}

void Player::printPlayer() {
    // clean prev
	if (this->x != this->prevX || this->y != this->prevY) {
        gotoxy(this->prevX, this->prevY);
        cout << " ";
	}

	gotoxy(this->x, this->y);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	cout << "@";
}
