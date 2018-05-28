#include <iostream>

using namespace std;

class Mover {
	public:
	    void move(int dir, Maze);
	    void printMover();
	    int getX();
	    int getY();
        Mover(int x, int y);

	protected:
	    int prevX;
	    int prevY;
	    int x;
	    int y;
};

