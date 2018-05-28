#include <iostream>
#include <vector>

using namespace std;

class Enemy {
	public:
	    void move(int dir, Maze);
	    void printEnemy();
	    void AddArray(int x, int y, int wc, int back);
	    void findPath(int sx, int sy, int x, int y);
	    int getX();
	    int getY();
		Enemy(int x, int y);

	private:
	    int prevX;
	    int prevY;
	    int x;
	    int y;
};
