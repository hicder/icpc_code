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
#define INF 1000000000
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
vi pset;

void initSet(int N){ pset.clear(); FOR(i, N) pset.pb(i);}
int findSet(int a){
    if (pset[a] == a) {return a;}
    else{ pset[a] = findSet(pset[a]); return pset[a];}}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void setUnion(int a, int b){ pset[findSet(a)] = findSet(b);}
int cx[510], cy[510];

int dis(int i, int j){
	return sqr(cx[i] - cx[j]) + sqr(cy[i] - cy[j]);
}

int t, n, m;



int main(){
	freopen("input", "r",stdin);
	cin >> t;
	while(t--){
		cin >> n >> m;
		initSet(n+1);
		EdgeList.clear();
		int u, v, w;
		FOR(i, m){
			cin >> u >> v >> w;
			EdgeList.pb(make_pair(w, make_pair(u,v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		int cost = 0;
		vector<int> MSTlist;
		FOR(i, EdgeList.size()){
			pair<int, ii> k = EdgeList[i];
			if(!isSameSet(k.second.second, k.second.first)){
				cost+= k.first;
				setUnion(k.second.second, k.second.first);
				MSTlist.pb(i);
			}			
		}
		pf("%d ", cost);
		cost = 0;
		int mincost = INF;
		FOR(i, MSTlist.size()){
			initSet(n+1);
			cost = 0;
			int nedgeincluded = 0;
			FOR(j, EdgeList.size()){
				if(j == MSTlist[i]) continue;
				pair<int, ii> k = EdgeList[j];
				if(!isSameSet(k.second.first, k.second.second)){
					cost += k.first;
					setUnion(k.second.first, k.second.second);
					nedgeincluded++;
				}
			}
			if(cost < mincost && nedgeincluded == n - 1) mincost = cost;
		}
		pf("%d\n", mincost);
	}
	return 0;
}