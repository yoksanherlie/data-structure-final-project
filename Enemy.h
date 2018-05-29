#include <iostream>
#include <vector>

struct Walk {
    int walkCount;
    int x;
    int y;
    int back;
};

class Enemy : public Mover {

public:
    using Mover::Mover;
    void addArray(int, int, int, int, Maze &m);
    void bfs(int, int, Maze &m);
    void move();

protected:
    vector<Node> walkQueue;
    vector<Walk> bfsArray;
};
