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

int t, n, m, counter, sccnum;
vi dfs_num, dfs_low, S, visited;
vi AdjM[100002];
vi ts;
int in[100002];

bool has(int u, int v){
	FOR(i, AdjM[u].size()) if(AdjM[u][i] == v) return true;
	return false;
}

void SCC(int u){
	dfs_num[u] = dfs_low[u] = counter++;
	FOR(i, AdjM[u].size()){
		int v = AdjM[u][i];
		if(dfs_num[v] == INF) SCC(v);	
	}
	ts.pb(u);
}

int main(){
//	freopen("input", "r", stdin);
	cin >> t;
	while(t--){
		cin >> n >> m;
		int u, v;
		dfs_num.assign(n+1, INF); dfs_low.assign(n+1, INF); visited.assign(n+1, 0); S.clear();
		sccnum = 0;
		counter = 0;
		MS(in);
		FOR(i, n) AdjM[i+1].clear();
		FOR(i, m){
			cin >> u >> v;
			if(!has(u,v)) {
				AdjM[u].pb(v);
			}
		}

		ts.clear();
		FOR(i, n){
			if(dfs_num[i+1] == INF) {
				SCC(i+1);
			}
		}
		reverse(ts.begin(), ts.end());
		dfs_num.assign(n+1, INF); dfs_low.assign(n+1, INF); visited.assign(n+1, 0); S.clear();
		sccnum = 0;

		FOR(i, n){
			if(dfs_num[ts[i]] == INF) {
				sccnum++;
				SCC(ts[i]);
			}
		}
		cout << sccnum << endl;
	}
	return 0;
}