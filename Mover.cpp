#include "Mover.h"
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Mover::Mover(int x, int y) {
    this->prevX = x;
    this->prevY = y;
    this->x = x;
    this->y = y;
}

int Mover::getX() {
    return this->x;
}

int Mover::getY() {
    return this->y;
}

void Mover::move(int dir, Maze m) {
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

    if (m.isWalkablePlayer(nextX, nextY)) {
        this->x = nextX;
        this->y = nextY;
    }
}

void Mover::printMover() {
    // clean prev
	if (this->x != this->prevX || this->y != this->prevY) {
        gotoxy(this->prevX, this->prevY);
        cout << " ";
	}

	gotoxy(this->x, this->y);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	cout << char(1);
}
