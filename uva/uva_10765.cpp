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

int n,m,counter;
vi AdjM[10001], dfs_num, dfs_low, pv;

bool has(int u, int v){
	FOR(i, AdjM[u].size()) if(AdjM[u][i] == v) return true;
	return false;
}

void dfs(int u, int p = -1){
	dfs_low[u] = dfs_num[u] = counter++;
	pv[u] = 0;
	bool atr = false;
	FOR(i, AdjM[u].size()){
		int v = AdjM[u][i];
		if(dfs_num[v] == INF){
			dfs(v,u);
			if(dfs_low[v] >= dfs_num[u]){
				atr = true;
				pv[u]++;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]) ;
		}
		else if(v != p){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}

	if(p < 0 && pv[u] <= 1) atr = false;

	if(atr){
		if(p >= 0) pv[u]++;
	}
	else{
		pv[u] = 1;
	}
}

int main(){
	freopen("input","r",stdin);
	while(scanf("%d %d", &n, &m) && n){
		int u,v;
		counter = 0;
		FOR(i,n){
			AdjM[i].clear();
		}
		dfs_low.assign(n,INF);
		dfs_num.assign(n,INF);
		pv.assign(n,0);
		while(scanf("%d %d",&u, &v) && u!= -1){
			if(!has(u,v)) AdjM[u].pb(v), AdjM[v].pb(u);
		}
		dfs(0);
		vi list;

		FOR(i, n){
			list.pb((pv[i] << 16) + (n - i));
		}

		sort(list.begin(), list.end());
		reverse(list.begin(),list.end());
		FOR(i,m) pf("%d %d\n", n - (list[i]&0xffff), list[i] >> 16);
		pf("\n");
	}
	return 0;
}