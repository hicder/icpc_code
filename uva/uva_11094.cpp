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
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf

using namespace std;
int m,n,x,y;
char b[25][25];
int visit[25][25];
int curnum = 0;
int maxreg = 0;
int sum;
char lfl;
bool withinstay;
void input(){
	memset(b,0,sizeof b);
	memset(visit,0,sizeof visit);
	curnum = 0;
	maxreg = 0;
	FOR(i,m){
		FOR(j,n){
			cin >> b[i][j];
			if(b[i][j] == '\n') cin >> b[i][j];
		}
	}
	cin >> x >> y;
	lfl = b[x][y];
}



void traverse(int r, int c){
	 sum++;
	if(r == x && c == y) withinstay = true;
	visit[r][c] = 1;
	FOR(dir,4){
		int r1 = r + "0121"[dir] - '1';
		int c1 = c + "1210"[dir] - '1';
		if(c1 < 0) c1 = n - 1;
		else if(c1 >= n) c1 = 0;

		if(r1 >= 0 && r1 < m && b[r1][c1] == lfl && !visit[r1][c1]){
			traverse(r1,c1);
		}
	}
}

int main(){
	freopen("input","r",stdin);
	while(scanf("%d%d",&m, &n) == 2){
		input();
		int maxsum = 0;
		FOR(i,m) FOR(j,n){
			if(!visit[i][j] && b[i][j] == lfl){
				withinstay = false;
				sum = 0;
				traverse(i,j);
				if(!withinstay && sum > maxsum) maxsum = sum;
			} 
		}
		pf("%d\n",maxsum);
	}
	return 0;
}