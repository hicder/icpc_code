#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAXV 100
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

typedef vector<int> vi;

int V, res[MAXV][MAXV],s, t, f, mf;
vi p, dist;
void input(){
	memset(res, 0, sizeof res);
	cin >> V >> s >> t;
	for(int i = 0; i < V; i++){
		int k, v, w; cin >> k;
		for(int i = 0; i < k; i++){
			cin >> v >> w;
			res[i][v] = w;
		}
	}
}

void augment(int v, int me){
	if(v == s) {f = me; return;}
	else if(p[v] != -1){
		int mw = min(me, res[p[v]][v]);
		augment(p[v], mw);
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int main(){
	freopen("input", "r", stdin);
	input();
	mf = 0;
	while(1){
		f = 0;
		p.assign(MAXV, -1);
		queue<int> q;
		vi dist(MAXV, INF); dist[s] = 0; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == t) break;
			for(int i = 0; i < V; i++){
				if(res[u][i] > 0 && dist[i] == INF) q.push(i), dist[i] = dist[u] + 1, p[i] = u;
			}
		}
		augment(t, INF);
		if(f == 0) break;
		mf += f;
	}

	cout << "The maxflow is: " << mf << endl;
	return 0;
}