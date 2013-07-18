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

using namespace std;
typedef vector<int> vi;

int n, counter, nrootChildren, rootIndex;
vi AdjM[105], dfs_num, dfs_low, artilist, dfs_parent;

bool has(int u, int v){
	FOR(i, AdjM[u].size()) if(AdjM[u][i] == v) return true;
	return false;
}

void dfs(int s){
	dfs_num[s] = dfs_low[s] = counter++;
	FOR(i, AdjM[s].size()){
		int v = AdjM[s][i];
		if(dfs_num[v] == INF){
			dfs_parent[v] = s;
			if(s == rootIndex) nrootChildren++;
			dfs(v);

			if(dfs_low[v] >= dfs_num[s]) {
				artilist[s] = 1;
			}
			dfs_low[s] = min(dfs_low[s], dfs_low[v]);
		}
		else if(dfs_parent[s] != v){
			dfs_low[s] = min(dfs_low[s], dfs_num[v]);
		}
	}
}

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d\n", &n) && n){
		int narti = 0;
		REP(i, 1, n+1) AdjM[i].clear();
		dfs_num.assign(n+1, INF);
		dfs_low.assign(n+1, INF);
		artilist.assign(n+1, 0);
		dfs_parent.assign(n+1, INF);
		counter = narti = nrootChildren = 0;
		string line;
		int u,v;
		while(1){
			getline(cin,line);
			stringstream ss(line);
			ss >> u;
			if(!u) break;
			while(ss >> v){
				if(!has(u,v)) AdjM[u].pb(v), AdjM[v].pb(u);
			}
		}
		REP(i, 1, n+1){
			if(dfs_num[i] == INF){
				nrootChildren = 0;
				rootIndex = i;
				dfs(i);
				artilist[rootIndex] = (nrootChildren > 1);
			}
		}
		REP(i, 1, n+1) if(artilist[i]) {
			narti++;
		}
		cout << narti<< endl;
	}
	return 0;
}