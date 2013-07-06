#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define INF 1000000000
#define pf printf
#define FOR(i,n) for(int i = 0; i < (n); i++)
using namespace std;
char bd[105][105];
int num[105][105];
int n, m;

int row(int i, int j, int dir){
	return i + "00012221"[dir] - '1';
}

int col(int i, int j, int dir){
	return j + "01222100"[dir] - '1';
}

int main(){
	int ca = 1;
	while(scanf("%d%d", &n, &m) && n && m){
		memset(bd, 0, sizeof bd);
		memset(num, 0, sizeof num);
		FOR(i,n) FOR(j,m){
			scanf("%c", &bd[i][j]);
			if(bd[i][j] == '\n') scanf("%c", &bd[i][j]);
		}

		FOR(i,n) {
			FOR(j,m) {
				if(bd[i][j] == '*') {num[i][j] = INF; continue;}
				FOR(dir, 8){
					int r = row(i,j,dir);
					int c = col(i,j,dir);
					if(r < 0 || r >= n || c < 0 || c >= m) continue;
					if(bd[r][c] == '*') num[i][j]++;
				}
			}
		}
		if(ca != 1) pf("\n");
		pf("Field #%d:\n", ca++);
		FOR(i,n) {
			FOR(j,m){
				if(num[i][j] == INF) cout << "*";
				else cout << num[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}