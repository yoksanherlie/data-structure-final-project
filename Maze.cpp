#include "Maze.h"

// Constructor of the maze
Maze::Maze() {
	this->size = 10;
}

Maze::Maze(int size) {
	this->size = size;
	this->initGrid();
}

/*
	Initialize all the node in the grid as a wall
*/
void Maze::initGrid() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->grid[i][j] = 0;
        }
    }
}

/*
	Print the maze.
	= is for the wall.
	Space is for the passage
*/
void Maze::printMaze() {
	for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[j][i] == 0) cout << "=";
            if (this->grid[j][i] == 1) cout << " ";
        }
		cout << endl;
	}
}

/*
	Check if the given coordinate is in the maze
*/
bool Maze::inMaze(int x, int y) {
	return x >= 0 && x <= this->size - 1 && y >= 0 && y <= this->size - 1;
}


void Maze::addWalls(int x, int y) {
	Node potential[4] = {
		{ x + 1, y },
		{ x - 1, y },
		{ x, y + 1 },
		{ x, y - 1},
	};

	for (int i = 0; i < 4; i++) {
		if (this->inMaze(potential[i].x, potential[i].y) && this->grid[potential[i].x][potential[i].y] == 0) {
			this->walls.push_back(potential[i]);
		}
	}
}


/*
	Generate the maze of the game with Randomized Prim's Algorithm
	1 is for the passage
	0 is for the wall
*/
void Maze::generateMaze() {
	// Set the starting point
	Node first = {2, 1};
	this->grid[first.x][first.y] = 1;
	this->addWalls(first.x, first.y);

	srand (time(NULL));

	while (this->walls.size() > 0) {
		int randomIndex = rand() % this->walls.size();
		Node random = this->walls[randomIndex];

		Node potential[2][2] = {
			{ {1, 0}, {-1, 0} },
			{ {0, 1}, {0, -1} }
		};

		for (int i = 0; i < 2; i++) {
			Node cell1 = { random.x - potential[i][0].x, random.y - potential[i][0].y };
			Node cell2 = { random.x - potential[i][1].x, random.y - potential[i][1].y };

			/*
				Check the cell divided by the current wall.
				If only one of the two cells divided.
					1. Make the wall a passage and mark the unvisited cell part of the maze
					2. Add the neighboring walls of the cell to the wall list
			*/
			if (this->inMaze(cell1.x, cell1.y) && inMaze(cell2.x, cell2.y)) {
				if (this->grid[cell1.x][cell1.y] == 1 && this->grid[cell2.x][cell2.y] == 0) {
					this->grid[random.x][random.y] = this->grid[cell2.x][cell2.y] = 1;
					this->addWalls(cell2.x, cell2.y);
				} else if (this->grid[cell1.x][cell1.y] == 0 && this->grid[cell2.x][cell2.y] == 1) {
					this->grid[random.x][random.y] = this->grid[cell1.x][cell1.y] = 1;
					this->addWalls(cell1.x, cell1.y);
				}
			}
		}

		// Remove the current wall from the potential wall list
		this->walls.erase(this->walls.begin() + randomIndex);
	}
}

/* 
	Used in the Breadth-First-Search Algorithm
	To check if the node in the grid is not visited and is a passage
*/
bool Maze::isWalkable(int x, int y) {
    return this->grid[x][y] == 1;
}

// Check if the node is available for the player to move
bool Maze::isWalkablePlayer(int x, int y) {
    return this->grid[x][y] == 1 || this->grid[x][y] == 2;
}

// Get the size of the maze
int Maze::getSize() {
    return this->size;
}

// Set a node in the grid to visited
void Maze::setVisited(int x, int y) {
    this->grid[x][y] = 2;
}

// Remove all visited state in the grid
void Maze::removeVisited() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[i][j] == 2) this->grid[i][j] = 1;
        }
    }
}
