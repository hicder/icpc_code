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
#include <cmath>
#include <map> 
#include <stack>

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

int n, r;

vii AdjM[1002];
int cost[1002];
int ancestor[1002];
int visit[1002];
void dfs(int s){
	visit[s] = 1;
	int costx = 0;
	int g = 0; int hehe = 0 ;
	FOR(i, AdjM[s].size()){
		ii e = AdjM[s][i];
		if(!visit[e.first] && ancestor[s] != e.first){
			g++;
			visit[e.first] = 1;
			ancestor[e.first] = s;
			dfs(e.first);

			costx += min(e.second, cost[e.first]);
		}
		else{
			hehe = e.second;
		}
	}
	if(g) cost[s] = costx;
	else cost[s] = hehe;
}

int main(){
//	freopen("input", "r", stdin);
	while(scanf("%d%d", &n, &r) && n){
		FOR(i, n){
			AdjM[i+1].clear();
		}
		MS(visit);
		MS(ancestor);
		memset(cost, INF, sizeof(cost));
		int u, v, w;
		FOR(i, n-1){
			cin >> u >> v >> w;
			AdjM[u].pb(make_pair(v, w));
			AdjM[v].pb(make_pair(u, w));
		}
		dfs(r);
		cout << cost[r] << endl;
	}
	return 0;
}