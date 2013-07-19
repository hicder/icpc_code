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

int n, m, counter, sccnum;
vi dfs_num, dfs_low, S, visited, AdjM[2002];

bool has(int u, int v){
	FOR(i, AdjM[u].size()) if(AdjM[u][i] == v) return true;
	return false;
}

void SCC(int u){
	dfs_num[u] = dfs_low[u] = counter++;
	S.push_back(u);
	visited[u] = 1;
	FOR (i, AdjM[u].size()){
		int v = AdjM[u][i];
		if(dfs_num[v] == INF){
				SCC(v);
		}

		if(visited[v]){
			dfs_low[u] = min (dfs_low[v], dfs_low[u]);
		}
	}

	if(dfs_low[u] == dfs_num[u]){
		sccnum++;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if(v == u) break;
		}
	}
}

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d%d", &n, &m) && (n || m)){
		FOR(i, n){
			AdjM[i+1].clear();
		}
		dfs_num.assign(n+1, INF); dfs_low.assign(n+1, INF); counter = 0; sccnum = 0;
		visited.assign(n+1, 0);
		int u, v,p;
		FOR(i,m){
			cin >> u >> v >> p;
			if(!has(u,v)) AdjM[u].pb(v);
			if(p==2){
				if(!has(v,u)) AdjM[v].pb(u);
			}
		}
		FOR(i, n){
			if(dfs_num[i+1] == INF) SCC(i+1);
		}

		if(sccnum == 1) cout << 1 << endl;
		else cout << 0<<endl;
	}
	return 0;
}