#include <iostream>
#include "Maze.cpp"
#include "Player.cpp"
#include "windows.h"

using namespace std;

void detectKey(Player &player, Maze m) {
    if (GetKeyState(VK_DOWN) & 0x8000) {
        player.move(3, m);
    } else if (GetKeyState(VK_RIGHT) & 0x8000) {
        player.move(1, m);
    } else if (GetKeyState(VK_UP) & 0x8000) {
        player.move(2, m);
    } else if (GetKeyState(VK_LEFT) & 0x8000) {
        player.move(0, m);
    }
}

int main() {
	Maze m(20);
	m.generateMaze();
	m.printMaze();

	bool playing = true;

	Player player(2, 1);

	while (playing) {
        detectKey(player, m);
        player.printPlayer();
        Sleep(100);
	}

	return 0;
}
