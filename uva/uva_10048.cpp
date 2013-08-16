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
#include <cmath>
#define INF 10000000
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define pf printf
#define MS(a) memset((a), 0, sizeof((a)))
#define sqr(a) ((a) * (a))

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;


vector< pair<int, ii> > EdgeList;   /*(weight, a, b)*/
vector<ii> quelist;
vi pset, visit;
vii AdjList[101];
void initSet(int N){pset.clear(); FOR(i, N) pset.pb(i);}
int findSet(int a){
    if (pset[a] == a) {return a;}
    else{ pset[a] = findSet(pset[a]); return pset[a];}}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void setUnion(int a, int b){ pset[findSet(a)] = findSet(b);}

int c, s, q, u, v, w;

int dfs(int u, int target){
	visit[u] = 1;
	if(u == target) return 0;
	FOR(i, AdjList[u].size()){
		int v = AdjList[u][i].first;
		if(visit[v]) {
			continue;
		}
		int a = dfs(v, target);
		if(a != INF) return max(AdjList[u][i].second, a);
	}
	return INF;
}

int main(){
	freopen("input", "r", stdin);
	int ca = 1;
	while(scanf("%d%d%d", &c, &s, &q) && c){
		if(ca != 1) pf("\n");
		EdgeList.clear(); quelist.clear();
		FOR(i, c+1) AdjList[i].clear();
		FOR(i, s){
			cin >> u >> v >> w;
			EdgeList.pb(make_pair(w, make_pair(u,v)));
		}
		FOR(i, q){
			cin >> u >> v;
			quelist.pb(make_pair(u,v));
		}

		initSet(c+1);
		sort(EdgeList.begin(), EdgeList.end());
		FOR(i, EdgeList.size()){
			pair<int, ii> k = EdgeList[i];
        	if (!isSameSet(k.second.first, k.second.second)) {
        		AdjList[k.second.first].pb(make_pair(k.second.second, k.first));
        		AdjList[k.second.second].pb(make_pair(k.second.first, k.first));
            	setUnion(k.second.first, k.second.second);
        	}
		}
		pf("Case #%d\n", ca++);
		FOR(i, quelist.size()){
			visit.assign(c+1, 0);
			int val = dfs(quelist[i].first, quelist[i].second);
			if(val != INF) pf("%d\n", val);
			else{
				pf("no path\n");
			}
		}
	}
	return 0;
}