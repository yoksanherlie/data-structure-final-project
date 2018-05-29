#include "Enemy.h"

/*
    Add struct Walk object to the BFS array
    if the coordniate is not visited and is a passage (walkable)
*/
void Enemy::addArray(int x, int y, int wc, int back, Maze &m) {
    if (m.isWalkable(x, y)) {
        m.setVisited(x, y);
        Walk tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.walkCount = wc;
        tmp.back = back;
        this->bfsArray.push_back(tmp);
    }
}

/*
    This function is to calculate the shortest path
    between the player and the enemy position.
    This function use Breadth-First-Search alogrithm
    to calculate the shortest path because the cost of
    all the nodes to the nodes adjacent to it is 1.
*/
void Enemy::bfs(int playerX, int playerY, Maze &m) {
    this->bfsArray.clear();
    m.removeVisited();
    Walk tmp = { 0, this->x, this->y, -1 };
    this->bfsArray.push_back(tmp);

    int i = 0;
    while (i < this->bfsArray.size()) {
        if (this->bfsArray[i].x == playerX && this->bfsArray[i].y == playerY) {
            this->walkQueue.clear();
            Node target;
            while (this->bfsArray[i].walkCount != 0) {
                target.x = this->bfsArray[i].x;
                target.y = this->bfsArray[i].y;
                this->walkQueue.push_back(target); // Add node to the walk queue for the enemy to walk

                i = this->bfsArray[i].back;
            }

            break;
        }

        /*
            Always check if the adjacent node is in the maze
            Check for four direction (up, right, down, left)
        */


        if (this->bfsArray[i].x + 1 < m.getSize()) {
            this->addArray( this->bfsArray[i].x+1, this->bfsArray[i].y, this->bfsArray[i].walkCount + 1, i, m);
        }
        if (this->bfsArray[i].x - 1 >= 0) {
            this->addArray( this->bfsArray[i].x-1, this->bfsArray[i].y, this->bfsArray[i].walkCount + 1, i, m);
        }
        if (this->bfsArray[i].y + 1 < m.getSize()) {
            this->addArray( this->bfsArray[i].x, this->bfsArray[i].y+1, this->bfsArray[i].walkCount + 1, i, m);
        }
        if (this->bfsArray[i].y - 1 >= 0) {
            this->addArray( this->bfsArray[i].x, this->bfsArray[i].y-1, this->bfsArray[i].walkCount + 1, i, m);
        }

		i++;
    }

    this->bfsArray.clear();
}

void Enemy::move() {
    // Set enemy print color to yellow
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

    // leave trailing
    gotoxy(this->x, this->y);
    cout << ".";

	if (this->walkQueue.size() != 0) {
        this->x = this->walkQueue.back().x;
        this->y = this->walkQueue.back().y;
        this->walkQueue.pop_back();
	}

	gotoxy(this->x, this->y);
	cout << "$";
}
