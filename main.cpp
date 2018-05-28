#include <iostream>
#include "Maze.cpp"
#include "Player.cpp"
#include "Enemy.cpp"
#include "windows.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
void detectKey(Player &player, Maze m) {
	int x = 2;
	int y = 1;
    if (GetKeyState(VK_DOWN) & 0x8000) {
        player.move(3, m);
		y++;  
    } else if (GetKeyState(VK_RIGHT) & 0x8000) {
        player.move(1, m);
        x++;
    } else if (GetKeyState(VK_UP) & 0x8000) {
        player.move(2, m);
        y--;
    } else if (GetKeyState(VK_LEFT) & 0x8000) {
        player.move(0, m);
        x--;
    }
}

char tmp_map[18][32];

char map[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########### ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|          ###########        |",
	"|                             |",
	"|                             |",
	"+#############################+"
	};

void showmap(){
	for (int i  = 0; i < 18; i++){
		printf("%s\n",map[i]);
	}
}

void Gotoxy(short x, short y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdout, coord);
}


struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;
void AddArray( int x, int y, int wc , int back){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}
void findPath( int sx, int sy, int x, int y){
	memcpy(tmp_map,map,sizeof(map));
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x && BFSArray[i].y == y ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i);
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i);
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i);
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i);

		/*
			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );

			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		*/
		i++;
	}

	BFSArray.clear();
}

int main() {
//	Maze m(20);
//	m.generateMaze();
//	m.printMaze();
	bool playing = true;
	int old_x;
	int old_y;
	int x = 15;
	int y = 16;
	int ex = 1;
	int ey = 1;
	showmap();
	Player player(x,y);	
	Enemy enemy (10,15);
	findPath(ex,ey,x,y);
	
	while (playing){
		Gotoxy(x,y);cout<<" ";
		old_x = x;
		old_y = y;	
//        detectKey(player, m);
//       	player.printPlayer();
       	
       	if ( GetAsyncKeyState( VK_UP ) ){
			if( map[y-1][x] == '.' ){ y--;} else
			if( map[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[y+1][x] == '.' ){ y++;} else
			if( map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[y][x-1] == '.' ){ x--;} else
			if( map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[y][x+1] == '.' ){ x++;} else
			if( map[y][x+1] == ' ' ) x++;
		}
        if( old_x == x || old_y == y ){
			findPath( ex,ey,x,y);
		}
		
		gotoxy( x,y ); cout << "@";

		map[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";
		if(walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
		Gotoxy(ex,ey);cout<<"E";
		if( ex == x && ey == y ){
			break;
		}
        Sleep(100);
	}

	return 0;
}
