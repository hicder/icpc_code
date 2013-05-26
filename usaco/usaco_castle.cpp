/*
ID: phamduc1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <vector>

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define MAXINT 1000000
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int nvertices, nedges;


vi piset;
int map[51][51];
int n[51][51], s[51][51],e[51][51],w[51][51];
int visit[51][51];
int width, height;
int ncomp = 0;
int maxsize= 0;
int maxremovesize = 0;
int wallx = 0;
int wally = 0;
int walldir = 0;
void initSet(int N){
    for (int i = 0; i < N; i++) {
        piset.push_back(-1);
    }
}

int findSet(int a){
    if (piset[a] < 0) {
        return a;
    }
    else{
        piset[a] = findSet(piset[a]);
        return piset[a];
    }
}

bool isSameSet(int a, int b){
    return findSet(a) == findSet(b);
}

void setUnion(int a, int b){
	int aroot = findSet(a);
	int broot = findSet(b);
	int sum = piset[aroot] + piset[broot];
	if(piset[aroot] >= piset[broot]){			//let's say aroot = -3, broot = -5, we choose broot
		piset[aroot] = broot;
		piset[broot] = sum;
	}
    else{
		piset[broot] = aroot;
		piset[aroot] = sum;
	}
	
	
}

void input(){
	cin >> width >> height;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cin >> map[j][i];
			w[j][i] = map[j][i] & 0x1;
			n[j][i] = map[j][i] & 0x2;
			e[j][i] = map[j][i] & 0x4;
			s[j][i] = map[j][i] & 0x8;
		}
	}
}

bool canTravel(int x, int y, int dir){
	if(dir == NORTH){
		if(y == 0 || n[x][y]||visit[x][y-1]) return false;
		else return true;
	}
	else if(dir == SOUTH){
		if(y ==  height - 1 || s[x][y] || visit[x][y+1]) return false;
		else return true;
	}
	else if(dir == EAST){
		if(x == width - 1 || e[x][y] || visit[x+1][y]) return false;
		else return true;
	}
	else{
		if(x == 0 || w[x][y] || visit[x-1][y]) return false;
		else return true;
	}
	return false;
}

int glinear(int x, int y, int dir){
	if(dir ==  NORTH) return x + (y-1) * width;
	else if (dir == SOUTH) return x + (y+1) * width;
	else if (dir == EAST) return x + 1 + y * width;
	else if (dir == WEST) return x - 1 + y * width;
	else return x + y * width;
}

void godir(int x, int y, int dir);
void dfs(int x, int y);

int removewall(int x, int y, int dir){
	if((dir == NORTH && y == 0) || (dir == SOUTH && y == height - 1) || (dir == EAST && x == width - 1) || (dir == WEST && x ==0)){
		return MAXINT;
	}
	if(isSameSet(glinear(x,y,5),glinear(x,y,dir))) return MAXINT;

	
	return piset[findSet(glinear(x,y,5))] + piset[findSet(glinear(x,y,dir))];
}

void checkunionsize(){
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){ 
			if(piset[glinear(i,j,5)]<maxsize) maxsize = piset[glinear(i,j,5)];
			for(int k = 0; k < 4; k++){
//				cout << i << " " <<j << " " << k<<endl;
				int temp = removewall(i,j,k);
				if(temp < maxremovesize) {
					maxremovesize = temp;
					wallx = i;
					wally = j;
					walldir = k;
				}
				else if(temp == maxremovesize && i < wallx){
					wallx = i;
					wally = j;
					walldir = k;
				}
				else if(temp == maxremovesize && i == wallx && j > wally){
					wallx = i;
					wally = j;
					walldir = k;
				}
				else if(temp == maxremovesize && i == wallx && j == wally && walldir == EAST && k == NORTH){
					wallx = i;
					wally = j;
					walldir = k;
				}
			}
		}
	}
}

void printmap(){
	for(int j = 0; j < height; j++){
		cout << "|";
		for(int i = 0; i < width; i++){
			if(s[i][j]) cout << "__";
			else cout << "  ";
			if(e[i][j]) cout << "|";
			else cout << " ";
		}
		cout << endl;
	}
}

int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	memset(map, 0, sizeof(map));
	memset(n,0,sizeof(n));
	memset(e,0,sizeof(e));
	memset(s,0,sizeof(s));
	memset(w,0,sizeof(w));
	memset(visit,0,sizeof(visit));
	input();
//	printmap();
	initSet(width*height);

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			if(!visit[i][j]){
//				cout << "starting at: "<< i << " " << j <<endl;
				ncomp++;
				dfs(i,j);
			}
		}
	}
	checkunionsize();
	cout << ncomp << endl << (-maxsize)<<endl<<(-maxremovesize)<<endl;
	cout << (wally+1) << " " <<(wallx+1);
	if(walldir == NORTH) cout << " N"<<endl;
	else if(walldir == SOUTH) cout << " S"<<endl;
	else if(walldir == EAST) cout << " E"<<endl;
	else cout << " W"<<endl;
	return 0;
}

void godir(int x, int y, int dir){
	if(dir == NORTH) dfs(x,y-1);
	else if (dir == SOUTH) dfs(x,y+1);
	else if (dir == EAST) dfs(x+1,y);
	else if(dir == WEST) dfs(x-1,y);
}

void dfs(int x, int y){
	if(x < 0 || y < 0 || x >= width || y >= height) return;
//	cout << "currently at: "<<x << " " << y << endl;
	visit[x][y] = 1;
	for(int dir = 0; dir < 4; dir++){
		if(canTravel(x,y,dir)){
			if(!isSameSet(glinear(x,y,dir),glinear(x,y,5))){
				setUnion(glinear(x,y,dir),glinear(x,y,5));
			}
			godir(x,y,dir);
		}
	}
}
