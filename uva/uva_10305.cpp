#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <map>
#define INF 128
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
#define MS(x) memset((x), 0, sizeof((x)))

using namespace std;
typedef vector<int> vi;
int m, n;
int bd[110][110], l[110];
vi AdjMatrix[101];
vi ts;

void dfs(int u){
	l[u] = 0;
	FOR(i, AdjMatrix[u].size()){
		int v = AdjMatrix[u][i];
		if(l[v]) dfs(v);
	}
	ts.pb(u);
}

int main(){
//	freopen("input","r",stdin);
	while(scanf("%d%d", &n, &m) && (m||n)){
		MS(bd); MS(l);
		FOR(i, 101) AdjMatrix[i].clear();
		ts.clear();
		int u, v;
		FOR(i,n) l[i+1] = 1;
		FOR(i,m){
			cin >> u >> v;
			AdjMatrix[u].pb(v);
			l[u] = 1;
			l[v] = 1;
		}

		FOR(i, n+1){
			if(l[i]) dfs(i);
		}
		reverse(ts.begin(), ts.end());
		FOR(i, ts.size()-1) pf("%d ", ts[i]);
		pf("%d\n",ts[ts.size()-1]);
	}
}