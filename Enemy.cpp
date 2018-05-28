#include "Enemy.h"
#include <windows.h>

void Gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Enemy::Enemy(int x, int y) {
    this->prevX = x;
    this->prevY = y;
    this->x = x;
    this->y = y;
}
//
//struct walk {
//	short walk_count;
//	short x;
//	short y;
//	short back;
//};
//
//struct target {
//	short x;
//	short y;
//};
//
//vector<target> walk_queue;
//
//vector<walk> BFSArray;
//
//void Enemy::AddArray( int x, int y, int wc , int back){
//	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
//		tmp_map[y][x] = '#';
//		walk tmp;
//		tmp.x = x;
//		tmp.y = y;
//		tmp.walk_count = wc;
//		tmp.back = back;
//		BFSArray.push_back( tmp );
//	}
//}

//void Enemy::findPath( int sx, int sy, int x, int y){
//	memcpy(tmp_map,map,sizeof(map))
//	BFSArray.clear();
//	walk tmp;
//	tmp.x = sx;
//	tmp.y = sy;
//	tmp.walk_count = 0;
//	tmp.back = -1;
//	BFSArray.push_back( tmp );
//
//	int i = 0;
//	while( i < BFSArray.size() ){
//		if( BFSArray[i].x == x && BFSArray[i].y == y ){
//			walk_queue.clear();
//			target tmp2;
//			while( BFSArray[i].walk_count != 0 ){
//				tmp2.x = BFSArray[i].x;
//				tmp2.y = BFSArray[i].y;
//				walk_queue.push_back( tmp2 );
//
//				i = BFSArray[i].back;
//			}
//
//			break;
//		}
//
//		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i,m);
//		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i,m);
//		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i,m);
//		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i,m);
//
//		/*
//			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
//
//			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
//			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
//		*/
//		i++;
//	}
//
//	BFSArray.clear();
//}

//
//void Enemy::move(int dir, Maze m) {
//    this->prevX = this->x;
//    this->prevY = this->y;
//
//    int dirX = 0;
//    int dirY = 0;
//
//    switch (dir) {
//        case 0:
//            dirX = -1;
//            break;
//        case 1:
//            dirX = 1;
//            break;
//        case 2:
//            dirY = -1;
//            break;
//        case 3:
//            dirY = 1;
//            break;
//    }
//
//    int nextX = this->x + dirX;
//    int nextY = this->y + dirY;
//
//    if (m.grid[nextX][nextY] == 1) {
//        this->x = nextX;
//        this->y = nextY;
//    }
//}

//void Enemy::printEnemy() {
//    // clean prev
//	if (this->x != this->prevX || this->y != this->prevY) {
//        Gotoxy(this->prevX, this->prevY);
//        cout << " ";
//	}
//
//	Gotoxy(this->x, this->y);
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 11);
//	cout << "E";
//}
