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
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, counter, nrootChildren, rootIndex;
vi AdjM[305], dfs_num, dfs_low, dfs_parent;
vii artilist;

bool comp(const ii &a,const ii &b){
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

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
			dfs(v);
			if(dfs_low[v] > dfs_num[s]) {
				artilist.pb(make_pair(min(s,v),max(s,v)));
			}
			dfs_low[s] = min(dfs_low[s], dfs_low[v]);
		}
		else if(dfs_parent[s] != v){
			dfs_low[s] = min(dfs_low[s], dfs_num[v]);
		}
	}
}


int main(){
	freopen("input","r",stdin);
	int ncase = 1;
	while(cin >> n){
		int u, v, deg;
		artilist.clear();
		dfs_parent.assign(n,INF);
		dfs_low.assign(n,INF);
		dfs_num.assign(n,INF);
		counter = 0;
		FOR(i,n) AdjM[i].clear();
		FOR(i,n){
			scanf("%d %*c %d %*c", &u, &deg);
			FOR(j, deg){
				scanf("%d", &v);
				if(!has(u,v))AdjM[u].pb(v), AdjM[v].pb(u);
			}
		}
		FOR(i,n){
			if(dfs_num[i] == INF){
				dfs(i);
			}
		}
		sort(artilist.begin(), artilist.end(),comp);
		pf("%d critical links\n", (int)artilist.size());
		FOR(i, artilist.size()){
			pf("%d - %d\n", artilist[i].first,artilist[i].second);
		}
		pf("\n");
		if(cin.eof()) break;
	}
	return 0;
}