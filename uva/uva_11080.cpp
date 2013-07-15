#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <map>
#define INF 1000000000
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
#define MS(x) memset((x), 0, sizeof((x)))
using namespace std;
typedef vector<int> vi;

vi AdjM[201];
int t,V,E, visit[201];
vi color;
bool imp = false;
bool exist(int u, int v){
	FOR(i, AdjM[u].size()) if(AdjM[u][i] == v) return true;
	return false;
}

int bfs(int s){
	visit[s] = 1;
	queue<int> q;
	q.push(s);
	color[s] = 0;
	int colcount[2] = {0,0};
	colcount[0]++;
	while(!q.empty()){
		int u = q.front(); q.pop();
		FOR(i, AdjM[u].size()){
			int v = AdjM[u][i];
			if(color[v] == INF){
				color[v] = 1 - color[u];
				colcount[color[v]]++;
				q.push(v);
			}
			else{
				if(color[v] == color[u]){
					imp = true;
					return -1;
				}
			}
		}
	}

	return (colcount[0] && colcount[1])?min(colcount[0], colcount[1]):max(colcount[0],colcount[1]);
}

int main(){
	freopen("input","r",stdin);
	cin >> t;

	while(t--){
		cin >> V >> E;
		imp = false;
		memset(visit, 0, sizeof visit);
		int u,v;
		FOR(i,V) AdjM[i].clear();
		FOR(i,E){
			cin >> u >> v;
			if(!exist(u,v)){
				AdjM[u].pb(v);
				AdjM[v].pb(u);
			}
		}
		color.assign(V, INF);
		int ans = 0;
		FOR(i, V){
			if (color[i] == INF) {
				ans+= bfs(i);
			}
			if(imp) break;
		}
		int nb = 0, nw = 0;
		if(imp) cout << -1 << endl;
		else{
			cout << ans << endl;
		}
	}

	return 0;
}