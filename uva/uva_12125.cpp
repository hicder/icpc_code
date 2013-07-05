#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000
using namespace std;
typedef vector<int> vi;
int n, ncase, f;
float d;
vi p;
int xi[100], yi[100], ni[100], mi[100];
int Vin(int id){return 2 + 2 * id;}
int Vout(int id){return 3 + 2 * id;}
int res[240][240];
int s = 0, t;
int total = 0;
int indis(int i, int j){
	float dis = (xi[i] - xi[j])*(xi[i] - xi[j]) + (yi[i] - yi[j])*(yi[i] - yi[j]);
	if ( dis > d * d) return 0;
	else return INF;
}
int resc[240][240];
void input(){
	memset(res, 0, sizeof res);
	memset(xi, 0, sizeof xi);
	memset(yi, 0, sizeof yi);
	memset(ni, 0, sizeof ni);
	memset(mi, 0, sizeof mi);
	scanf("%d %f", &n, &d);
	total = 0;
	FOR(i,n) {
		scanf("%d %d %d %d", &xi[i], &yi[i], &ni[i], &mi[i]);
		res[Vin(i)][Vout(i)] = mi[i];
		res[0][Vin(i)] = ni[i];
	//	res[Vout(i)][Vin(t)] = INF;
		total += ni[i];
	}
	FOR(i,n) FOR(j,n) res[Vout(i)][Vin(j)] = indis(i,j);
}

void augment(int v, int me){
	if(v == s) {f = me; return;}
	else if(p[v] != -1){
		int mw = min(me, resc[p[v]][v]);
		augment(p[v], mw);
		resc[p[v]][v] -= f; resc[v][p[v]] += f;
	}
}

int ek(){
	int mf = 0;
	while(1){
		f = 0;
		p.assign(240, -1);
		queue<int> q;
		bitset<240> dist; dist[s] = 1; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
//			pf("at: %d\n",u);
			if(u == 1) break;
			for(int i = 0; i < Vin(n); i++){
				if(resc[u][i] > 0 && !dist[i] ) {
					q.push(i); dist[i] = 1; p[i] = u;
				}
			}
		}
		augment(1, INF);
		//pf("%d\n",f);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}


void par(){
	for(int i = 0; i < 2*(n + 1); i++){
		for(int j = 0; j < 2*(n + 1); j++){
			pf("%d ", resc[i][j] == INF ? -1: resc[i][j]);
		}
		pfn;
	}
}

void fix(){
	resc[Vin(t)][Vout(t)] = INF;
	resc[Vout(t)][1] = INF;
}

int main(){
//	freopen("input","r",stdin);
	cin >> ncase;
	vi list;
	while(ncase--){
		input();
		list.clear();
		FOR(i, n){
			t = i;
			memcpy(resc,res, sizeof res);
			fix();
			int ret = ek();
			if(ret == total) list.pb(t);
		}
		if(!list.empty()){
			FOR(i, (list.size() - 1))pf("%d ",list[i]);
			pf("%d\n",list[list.size() - 1]);
		}
		else pf("-1\n");
	}

	return 0;
}