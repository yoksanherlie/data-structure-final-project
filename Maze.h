#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int x;
	int y;
};

class Maze {
	public:
		int grid[20][20];
		void printMaze();
		void generateMaze();
		Maze();
		Maze(int size);

	private:
		int size;
		vector<Node> walls;
		void addWalls(int x, int y);
		void initGrid();
		bool inMaze(int x, int y);
};
