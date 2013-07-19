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
#include <map>
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
vi dfs_num, dfs_low, S, visited, scclist[26];
map<string, int> to;
map<int, string> from;

int n, m, g[30][30],counter;
int setIdx;
void SCC(int u){
	dfs_num[u] = dfs_low[u] = counter++;
	S.push_back(u);
	visited[u] = 1;
	FOR(i, n){
		if(g[u][i]){
			if(dfs_num[i] == INF){
				SCC(i);
			}

			if(visited[i]){
				dfs_low[u] = min (dfs_low[i], dfs_low[u]);
			}
		}
	}

	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			scclist[setIdx].pb(v);
			if(u == v) break;
		}
		setIdx++;
	}
}

int main(){
	freopen("input", "r", stdin);
	cin >> n >> m;
	string name1, name2;
	int ncase = 1;
	while(n || m){
		MS(g);
		dfs_num.assign(n, INF); dfs_low.assign(n, INF); visited.assign(n, 0);
		S.clear();
		int namecount = 0;
		setIdx = 0; counter = 0;
		FOR(i,n) scclist[i].clear();
		to.clear();
		from.clear();
		FOR(i, m){
			cin >> name1 >> name2;
			if(to.find(name1) == to.end()) to[name1] = namecount++, from[namecount-1] = name1;
			if(to.find(name2) == to.end()) to[name2] = namecount++, from[namecount-1] = name2;
					g[to[name1]][to[name2]] = 1;

		}
		FOR(i, n){
			if(dfs_num[i] == INF) SCC(i);
		}
		if(ncase != 1) cout << endl;
		pf("Calling circles for data set %d:\n", ncase++);
		FOR(i, setIdx){
			FOR(j, scclist[i].size()-1) cout << from[scclist[i][j]] << ", ";
			cout << from[scclist[i][scclist[i].size()-1]]<< endl;
		}
		cin >> n >> m;
	}
	return 0;
}