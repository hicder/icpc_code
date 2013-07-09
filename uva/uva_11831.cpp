#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#define INF 128
#define MAXV 50102
#define monk(i) (2+(i))
#define Inte(i) (2 + (n) + (i))
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
#define _N 0
#define	_S 1
#define _L 2
#define _O 3
using namespace std;
char bd[110][110];
char seq[50001];
int n,m,s;
int sx, sy;
int currentdir,curx, cury;
void changecurrentdir(char cmd){
	if(cmd == 'D'){
		currentdir = "2310"[currentdir] - '0';
	}
	else if(cmd == 'E'){
		currentdir = "3201"[currentdir] - '0';
	}
}

int nsticker;

void move(int level){
//	cout <<"at level"<<level << endl;
	int _x, _y;
	if(level == s) return;
	if(seq[level] == 'D' || seq[level] == 'E') {
		changecurrentdir(seq[level]);
		move(level + 1);
	}
	else{
		_x = curx + "1120"[currentdir] - '1';
		_y = cury + "0211"[currentdir] - '1';
		if(_x < 0 || _x >= m || _y < 0 || _y >= n || bd[_y][_x] == '#') move(level + 1);
		else{
			if(bd[_y][_x] == '*'){
				nsticker++;
				bd[_y][_x] = '.';
			}
			curx = _x;
			cury = _y;
			move(level + 1);
		}
	}
}

int main(){
//	freopen("input","r",stdin);
	while(scanf("%d%d%d",&n,&m,&s) && s && m && n){
		nsticker = 0;
		memset(bd,0,sizeof bd);
		memset(seq, 0, sizeof seq);
		FOR(i,n){
			FOR(j,m){
				cin >> bd[i][j];
				if(bd[i][j] == '\n') cin >> bd[i][j];
				if(bd[i][j] == 'N' || bd[i][j] == 'S' || bd[i][j] == 'L' || bd[i][j] == 'O')
					sx = j, sy = i;
			}
		}
		//set current direction
		if(bd[sy][sx] == 'N') currentdir = 0;
		else if(bd[sy][sx] == 'S') currentdir = 1;
		else if(bd[sy][sx] == 'L') currentdir = 2;
		else currentdir = 3;

		FOR(i,s){
			cin >> seq[i];
			if(seq[i] == '\n') cin >> seq[i];
		}
		curx = sx;
		cury = sy;
		move(0);
		cout << nsticker << endl;
	}
	return 0;
}