#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#define INF 1000000
#define MAXV 50102
#define tas(i) (2+(i))
#define Inte(i) (2 + (t) + (i))
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
using namespace std;
typedef vector<int> vi;

struct task{
	int a,r,d;
}tasks[41];

int res[400][400];
int c,t, p,f, total;
vi ipoint;
vi inter;
vi pa;
void input(){
	memset(res,0,sizeof res);
	ipoint.clear(); inter.clear();
	cin >> p >> t;
	FOR(i,t){
		cin >> tasks[i].a >> tasks[i].r >> tasks[i].d;
		res[0][tas(i)] = tasks[i].r;
		total += tasks[i].r;
		ipoint.pb(tasks[i].a);
		ipoint.pb(tasks[i].d);
	}
	sort(ipoint.begin(), ipoint.end());
	FOR(i, ipoint.size() - 1) inter.pb(ipoint[i+1] - ipoint[i]);
		FOR(i,t){
		FOR(j, inter.size()){
			if(tasks[i].a <= ipoint[j] && tasks[i].d > ipoint[j]) res[tas(i)][Inte(j)] = inter[j];
		}
	}
	FOR(i, inter.size()){
		res[Inte(i)][1] = inter[i] * p;
	}
}
void augment(int v, int me){
	if(v == 0) {
		f = me;
		return;
	}
	else if(pa[v] != -1){
		int mw = min(me, res[pa[v]][v]);
		augment(pa[v], mw);
		res[pa[v]][v] -= f; res[v][pa[v]] += f;
	}
}

int edmonds_karp(){
	int mf = 0;
	while(1){
		f = 0;
		pa.assign(3000, -1);
		queue<int> q;
		bitset<3000> dist;
		dist[0] = 1; 
		q.push(0);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == 1) break;
			for(int i = 0; i < Inte(inter.size()); i++){
				if((res[u][i]) > 0 && !dist[i]){
					dist[i] = 1; 
					q.push(i);
					pa[i] = u;
				}
			}
		}
		augment(1, INF);
		if(f <= 0) break;
		mf += f;
	}
	return mf;
}

int main(){
//	freopen("input","r",stdin);
	cin >> c;
	while(c--){
		total = 0;
		input();
		int retval = edmonds_karp();
		if(total == retval) cout << "FEASIBLE" << endl;
		else cout << "NO WAY"<<endl;
	}
	return 0;
}