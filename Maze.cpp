#include "Maze.h"

Maze::Maze() {
	this->size = 10;
}

Maze::Maze(int size) {
	this->size = size;
	this->initGrid();
}

void Maze::initGrid() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->grid[i][j] = 0;
        }
    }
}

void Maze::printMaze() {
	for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[j][i] == 0) cout << "=";
            if (this->grid[j][i] == 1) cout << " ";
        }
		cout << endl;
	}
}

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

void Maze::generateMaze() {
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

		this->walls.erase(this->walls.begin() + randomIndex);
	}
}

bool Maze::isWalkable(int x, int y) {
    return this->grid[x][y] == 1;
}

bool Maze::isWalkablePlayer(int x, int y) {
    return this->grid[x][y] == 1 || this->grid[x][y] == 2;
}

int Maze::getSize() {
    return this->size;
}

void Maze::setVisited(int x, int y) {
    this->grid[x][y] = 2;
}

void Maze::removeVisited() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[i][j] == 2) this->grid[i][j] = 1;
        }
    }
}
