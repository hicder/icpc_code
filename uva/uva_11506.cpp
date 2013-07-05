#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000
using namespace std;
typedef vector<int> vi;
int m, w;
int res[120][120];
vi p;
int s, t;
int f;
int Vin(int id){
	return 2 * (id) - 1;
}

int Vout(int id){
	return 2 * (id);
}

void input(){
	int id,idto,  cost;
	memset(res, 0, sizeof res);
	FOR(i, m-2){
		cin >> id >> cost;
		res[Vin(id)][Vout(id)] = cost;
	}

	FOR(i, w){
		cin >> id >> idto >> cost;
		res[Vout(id)][Vin(idto)] = cost;
		res[Vout(idto)][Vin(id)] = cost;
	}
	res[1][2] = INF;

	s = 1; t = m;
	res[Vin(t)][Vout(t)] = INF;
}

void augment(int v, int me){
//	cout << "at: "<<v<<endl;
	if(v == Vin(s) || v == Vout(s)) {f = me; return;}
	else if(p[v] != -1){
		int mw = min(me, res[p[v]][v]);
//		cout << "mw: "<<mw<<endl;
		augment(p[v], mw);
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int ek(){
	int mf = 0;
	while(1){
		f = 0;
		p.assign(120, -1);
		queue<int> q;
		bitset<120>dist; dist[s] = 1; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == Vin(t))  break;
			for(int i = 1; i <= 2 * m; i++){
				if(res[u][i] > 0 && !dist[i]) {
					q.push(i); dist[i] = 1; p[i] = u;
				}
			}
		}
		augment(Vin(t), INF);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}

void par(){
	for(int i = 1; i <= 2*m; i++){
		for(int j = 1; j <= 2*m; j++){
			pf("%d ", res[i][j]);
		}
		pfn;
	}
}

int main(){
//	freopen("input","r",stdin);
	while(scanf("%d %d", &m, &w) && m != 0){
		input();
		cout << ek() <<endl;
	}
	return 0;
}