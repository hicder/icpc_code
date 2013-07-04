#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAXV 110
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

typedef vector<int> vi;

int V, res[MAXV][MAXV],s, t, f;
int bw1[MAXV][MAXV];
int bw2[MAXV][MAXV];
vi p;
int ncon;
bool term = false;
void input(){
	memset(res, 0, sizeof res);
	cin >> V;
	if(!V){
		term = true;
		return;
	}
	cin >> s >> t >> ncon;
	s-- ;
	t--;
	for(int i = 0; i < ncon; i++){
		int x, y, z;
		cin >> x >> y >> z;
		res[x-1][y-1] += z;
		res[y-1][x-1] += z;
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

int exe(){
	input();
	if(term) return 0;
	int mf = 0;
	while(1){
		f = 0;
		p.assign(MAXV, -1);
		queue<int> q;
		vi dist(MAXV, INF); dist[s] = 0; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == t) break;
			for(int i = 0; i < V; i++){
				if(res[u][i] > 0 && dist[i] == INF) {
					q.push(i); dist[i] = dist[u] + 1; p[i] = u;
				}
			}
		}
		augment(t, INF);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}

int main(){
//	freopen("input", "r", stdin);
	int nnet = 1;
	while(!term){
		int ret = exe();
		if(!term){
			cout << "Network "<<nnet++<<endl;
			cout << "The bandwidth is "<<ret<<"."<<endl<<endl;
		}
	}
	return 0;
}