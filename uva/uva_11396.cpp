#include <iostream>
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
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define pf printf
#define MS(x) memset((x), 0, sizeof((x)))
using namespace std;
typedef vector<int> vi;
int V;
vi AdjM[305];
vi color;

bool imp;

void bfs(int sv){
	color[sv] = 0;
	queue<int> q;
	q.push(sv);
	while(!q.empty()){
		int u = q.front(); q.pop();
		FOR(i, AdjM[u].size()){
			int v = AdjM[u][i];
			if(color[v] == INF){
				color[v] = 1 - color[u];
				q.push(v);
			}
			else{
				if(color[v] == color[u]){
					imp = true;
					return;
				}
			}
		}
	}
}

int main(){
	freopen("input", "r",stdin);
	while(scanf("%d", &V) && V){
		int u, v;
		REP(i,1,V+1) AdjM[i].clear();
		color.assign(V+1, INF);
		while(scanf("%d%d", &u, &v) && u){
			AdjM[u].pb(v);
			AdjM[v].pb(u);
		}
		imp = false;
		REP(i,1,V+1) {
			if(color[i] == INF) bfs(i);
			if(imp) break;
		}
		if(imp) cout << "NO"<<endl;
		else cout << "YES"<<endl;
	}
}