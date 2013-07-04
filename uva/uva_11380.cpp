#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <bitset>
#define INF 1000000000
#define MAXV 40
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

typedef struct{
	int x, y, c;
}Edge;

int mf,f;
vector<Edge> ed;
vector<int> adlist[100000];
char maze[40][40];
int width, height, P;
vector<int> p;
bitset<1000000> visit;
//set 0 as s, 1 as t
int Vin(int r, int c){
	return 2 + (r * width + c) * 2;
}

int Vout(int r, int c){
	return 2 + (r * width + c)*2 + 1;
}

void add(int _x, int _y, int _c){
	Edge e;
	e.x = _x; e.y = _y; e.c = _c;
	adlist[_x].push_back(ed.size());
	ed.push_back(e);
	Edge e1;
	e1.x = _y; e1.y = _x; e1.c = 0;
	adlist[_y].push_back(ed.size());
	ed.push_back(e1);
}
/*
void augment(int v, int me){
	cout << "at "<<v << " " << me << endl;
	if(v == 0) {
		cout << "final "<<me << endl;
		f = me; return;
	}
	else if(p[v] != -1){
		int i,j;
		for(i = 0; i < (int)adlist[p[v]].size(); i++){
			if(ed[adlist[p[v]][i]].y == v && ed[adlist[p[v]][i]].c > 0) break;
		}
		int mw = min(me, ed[adlist[p[v]][i]].c);
		augment(p[v], mw);
		ed[adlist[p[v]][i]].c -= f; 
		ed[adlist[p[v]][i]^1].c += f;
	}
}
*/
/*
void bfs(){
	//bitset<100000> visit;
	bitset<100000> people;
	while(1){
		bitset<100000> visit;
		f = 0;
		visit[0] = 1;
		queue<int> q; q.push(0);
		p.assign(100000, -1);
		while(!q.empty()){
			int u = q.front(); q.pop();
			cout << "from "<<u<<endl;
			if(u == 1)  break;
			for(int i = 0; i < (int)adlist[u].size(); i++){
				int idx = adlist[u][i];	
				if(u == 0 && people[ed[idx].y]) continue;
				if(ed[idx].c > 0 && !visit[ed[idx].y]){
					visit[ed[idx].y] = 1; q.push(ed[idx].y); p[ed[idx].y] = u;
					if(u == 0) {
						people[ed[idx].y] = 1;
						cout << "parent of "<<ed[idx].y << " is "<<u << endl;

					}
				}
			}
		}
		augment(1, INF);
		if(f == 0) break;
		mf += f;
	}
}
*/
int dfs(int v){
	if(visit[v]) {
		return 0;
	}
	visit[v]  = 1;
	if(v == 1) return 1;
	for(int i = 0; i < (int)adlist[v].size(); i++){
		int eidx = adlist[v][i];
		if(ed[eidx].c > 0 && dfs(ed[eidx].y)){
			ed[eidx].c -- ;
			ed[eidx ^ 1].c ++;
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("input","r",stdin);
	while(scanf("%d %d %d",&height, &width, &P) == 3){
		memset(maze, 0 , sizeof maze);
		ed.clear();
		for(int i = 0; i < height * width * 2 + 10; i++) adlist[i].clear();
		p.clear();
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				scanf("%c", &maze[i][j]);
				if(maze[i][j] == '\n') scanf("%c", &maze[i][j]);
			}
		}
		int r1, c1;
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				for(int dir = 0; dir < 4; dir++){	//dir: 0 up, 1 down, 2 left, 3 right
					r1 = i + "0211"[dir] - '1';
					c1 = j + "1102"[dir] - '1';
					if(r1 < 0 || c1 < 0 || r1 >= height || c1 >= width) continue;
					if(maze[i][j] == '~' || maze[r1][c1] == '~') continue;
					add(Vout(i,j), Vin(r1, c1), INF);
				}

				if(maze[i][j] == '*'){	//people, connect s to these points
//					add(Vin(i,j), Vout(i,j), 1);
					add(0, Vout(i,j), 1);
				}
				else if(maze[i][j] == '.'){		//small ice
					add(Vin(i,j), Vout(i,j),1);
				}
				else if(maze[i][j] == '@'){		//big ice
					add(Vin(i,j), Vout(i,j), INF);
				}
				else if(maze[i][j] == '#'){		//life saver
					add(Vin(i,j), Vout(i,j), INF);
					add(Vout(i,j), 1, P);
				}
			}
		}
		int f = 0;
		visit.reset();
		while(dfs(0)) {
			visit.reset();
			f++;
		}
		cout << f << endl;	
	}
	return 0;
}