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

char m[101][101];
int visit[101][101];

int t, n;
void input(){
	cin >> n;
	memset(m,0,sizeof m);
	memset(visit,0,sizeof visit);
	FOR(i,n){
		FOR(j,n){
			cin >> m[i][j];
			if(m[i][j] == '\n') cin >> m[i][j];
		}
	}
}

void dfs(int r, int c, int dir){
	visit[r][c] = 1;
	int r1 = r + "0121"[dir] - '1';
	int c1 = c + "1210"[dir] - '1';	
	if(r1 < 0 || r1 >= n || c1 < 0 || c1 >= n || m[r1][c1] == '.' || visit[r1][c1]) return;
	else dfs(r1,c1, dir);
}

int main(){
	freopen("input","r",stdin);
	cin >> t;
	int ca = 1;
	while(t--){
		int nship = 0;
		input();
		FOR(i,n){
			FOR(j,n){
				if(m[i][j] == 'x' && !visit[i][j]){
					FOR(dir,4){
						dfs(i,j,dir);
					}
					nship ++;
				}
			}
		}

		pf("Case %d: %d\n",ca++, nship);
	}
	return 0;
}