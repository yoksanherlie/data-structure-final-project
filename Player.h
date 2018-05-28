#include <iostream>
#include <vector>

using namespace std;

class Player {
	public:
	    void move(int dir, Maze);
	    void printPlayer();
	    int getX();
	    int getY();
		Player(int x, int y);

	private:
	    int prevX;
	    int prevY;
	    int x;
	    int y;
};
