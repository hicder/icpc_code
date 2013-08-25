#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <sstream>
#include <cstring>
#include <string>
#define INF 1000000000
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define pf printf
#define MS(a) memset((a), 0, sizeof((a)))
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int map[1005][1005], r, c, brow, rin, nbomb, bin, sr, sc, dr, dc;
vi visit;

int bfs(int startrow, int startcol){
	visit[startrow * c + startcol] = 1;
	queue<int> qr, qc, qdis;
	qr.push(startrow); qc.push(startcol); qdis.push(0);
	while(!qr.empty()){
		int currentrow = qr.front(); qr.pop();
		int currentcol = qc.front(); qc.pop();
		int distance = qdis.front(); qdis.pop();
		if(currentrow == dr && currentcol == dc) return distance;
		FOR(dir, 4){
			int nextrow = currentrow + "0121"[dir] - '1';
			int nextcol = currentcol + "1210"[dir] - '1';
			if(nextrow >= 0 && nextrow < r && nextcol >= 0 && nextcol < c && !visit[nextrow * c + nextcol] && !map[nextrow][nextcol]){
				visit[nextrow * c + nextcol] = 1;
//				cout << "from: (" << currentrow << ","<<currentcol<<") to ("<<nextrow << "," << nextcol<<")"<< endl;
				qr.push(nextrow);
				qc.push(nextcol);
				qdis.push(distance + 1);
			}
		}
	}
	return 0;
}

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d%d", &r, &c) && r){
		MS(map); cin >> brow;
		FOR(i, brow){
			cin >> rin >> nbomb;
			FOR(j, nbomb){
				cin >> bin; map[rin][bin] = 1;
			}
		}
		cin >> sr >> sc >> dr >> dc;
		visit.assign(r * c, 0);
		pf("%d\n", bfs(sr, sc));
	}
	return 0;
}