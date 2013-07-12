#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#define INF 1000000000
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
using namespace std;
typedef vector<int> vi;
int r, c, m, n,t,w;
int bd[110][110];
int neven, nodd;
vi dist;
int tp(int x, int y){
	return x + y * c;
}

int torow(int u){
	return u / c;
}

int tocol(int u){
	return u % c;
}

int rowdir(int x, int y, int dir){
	int rowindex[8] = {-n,-n,-m,m,n,n,m,-m};
	return y + rowindex[dir];
}

int coldir(int x, int y, int dir){
	int colindex[8] =  {-m,m,n,n,m,-m,-n,-n};
	return x + colindex[dir];
}

void bfs(){
	dist.assign(r * c + 1, 0);
	queue<int> q; q.push(0); dist[0] = 1;
	bitset<100000> in;
	while(!q.empty()){
		int u = q.front(); q.pop();
		int num = 0;
//		cout <<"At: "<<torow(u)<<" " << tocol(u) <<endl;
		in.reset();
		FOR(dir, 8){
			int r1 = rowdir(tocol(u), torow(u), dir);
			int c1 = coldir(tocol(u), torow(u), dir);
			if(r1 < 0 || r1 >= r || c1 < 0 || c1 >= c || bd[r1][c1] == -1) continue;
			int v = tp(c1, r1);
			if(!in[v]) num++;
			else continue;
			in[v] = 1;
//			cout << c1 << " " <<r1<<endl;
			if(dist[v] == 0 && bd[r1][c1] != -1){
				q.push(v);
				dist[v] = 1;
			}
		}
//		cout <<"possible movement "<<num <<endl;
		if(num % 2) nodd ++;
		else neven ++;
	}
}


int main(){
	freopen("input","r",stdin);
	cin >> t;
	int ca = 1;
	while(t--){
		int xwat,ywat;
		neven = 0;
		nodd = 0;
		memset(bd,0,sizeof bd);
		scanf("%d%d%d%d", &r,&c,&m,&n);
		cin >> w;
		FOR(i,w){
			cin >> ywat >> xwat;
			bd[ywat][xwat] = -1;
		}
		bfs();
		pf("Case %d: %d %d\n",ca++, neven, nodd);
	}

	return 0;
}