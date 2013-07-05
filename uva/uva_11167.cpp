#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#define INF 128
#define MAXV 50102
#define monk(i) (2+(i))
#define Inte(i) (2 + (n) + (i))
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
using namespace std;
typedef vector<int> vi;
int cap[401][401];
int flow[401][401];	//flow graph
int used[50010];
vector<int> intervalpoint;
vector<int> inter;
//denote s = 0, t = 1

struct Monkey{
	int v,s,e;
}monkey[101];

vector<vi> AdjList;

int n, m;
vi p;
int f;
int sum;
void input(){
	int v, a, b;
	memset(cap, 0, sizeof cap);
	memset(flow, 0, sizeof flow);
	intervalpoint.clear();
	inter.clear();
	sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &monkey[i].v, &monkey[i].s, &monkey[i].e);
		cap[0][monk(i)] = monkey[i].v;
		intervalpoint.pb(monkey[i].s);
		intervalpoint.pb(monkey[i].e);
	}

	sort(intervalpoint.begin(), intervalpoint.end());
	FOR(i, intervalpoint.size() - 1) {
		inter.pb(intervalpoint[i+1] - intervalpoint[i]);
		cap[Inte(i)][1] = inter[i] * m;

	}
	
	FOR(i, n){	//each monkey
		FOR(j, inter.size()){
			if(monkey[i].s <= intervalpoint[j] && monkey[i].e > intervalpoint[j]) {
				cap[monk(i)][Inte(j)] = inter[j];
			}
		}
		sum += monkey[i].v;
	} 
}

void augment(int v, int me){
	if(v == 0) {
		f = me;
		return;
	}
	else if(p[v] != -1){
		int mw = min(me, (cap[p[v]][v] - flow[p[v]][v]));
		augment(p[v], mw);
		flow[p[v]][v] += f; flow[v][p[v]] -= f;
	}
}

int edmonds_karp(){
	int mf = 0;
	while(1){
		f = 0;
		p.assign(Inte(inter.size()), -1);
		queue<int> q;
		bitset<5002> dist;
		dist[0] = 1; 
		q.push(0);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == 1) break;
			for(int i = 0; i < Inte(inter.size()); i++){
				if((cap[u][i] - flow[u][i]) > 0 && !dist[i]){
					dist[i] = 1; 
					q.push(i);
					p[i] = u;
				}
			}
		}
		augment(1, INF);
		if(f <= 0) break;
		mf += f;
	}
	return mf;
}

void par(){
	FOR(i, Inte(inter.size())){
		FOR(j, Inte(inter.size())){
			pf("%d ", cap[i][j]);
		}
		pf("\n");
	}
}

int main(){
	freopen("input","r",stdin);
	int cnum = 1;
	int bounds[1000];
	while(scanf("%d %d", &n, &m) == 2 && n != 0){
		input();
		int retval = edmonds_karp();
		if(retval != sum) pf("Case %d: No\n", cnum++);
		else{
			pf("Case %d: Yes\n", cnum++);
			int outCC = 0;
			memset(used, 0, sizeof used);
			FOR(i, n){
				int bound = 0;
				FOR(j, inter.size()){
					if(flow[monk(i)][Inte(j)] > 0){
						int s = intervalpoint[j];
						while(used[s] >= m) s++;
						FOR(t, flow[monk(i)][Inte(j)]){
							used[s]++;
							bounds[bound++] = s++;
							if(bound > 1 && bounds[bound - 1] == bounds[bound - 2]) bound -= 2;
							bounds[bound++] = s;
						}
					}
				}
				pf("%d", bound/2);
				for(int j = 0; j < bound -1; j+=2) pf(" (%d,%d)",bounds[j],bounds[j+1]); 
				pf("\n");
			}
		}
	}
	return 0;
}