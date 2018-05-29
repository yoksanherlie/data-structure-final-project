#include <iostream>
#include <vector>
#ifndef MAZE_H
#define MAZE_H

using namespace std;

struct Node {
	int x;
	int y;
};

class Maze {
	public:
		void printMaze();
		void generateMaze();
		bool isWalkable(int, int);
		bool isWalkablePlayer(int, int);
		void removeVisited();
		int getSize();
		void setVisited(int, int);
		Maze();
		Maze(int size);

	private:
		int grid[20][20];
		int size;
		vector<Node> walls;
		void addWalls(int x, int y);
		void initGrid();
		bool inMaze(int x, int y);
};

#endif // MAZE_H
