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
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;


vector< pair<int, ii> > EdgeList;   /*(weight, a, b)*/

vi pset;

void initSet(int N){pset.clear(); FOR(i, N) pset.pb(i);}
int findSet(int a){
    if (pset[a] == a) {return a;}
    else{ pset[a] = findSet(pset[a]); return pset[a];}}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void setUnion(int a, int b){ pset[findSet(a)] = findSet(b);}

int n, m, u, v, w;

int main(){
//	freopen("input", "r", stdin);
	while(scanf("%d%d", &n, &m) && (n || m)){
		EdgeList.clear();
		FOR(i, m){
			cin >> u >> v >> w;
			EdgeList.pb(make_pair(w, make_pair(u,v)));
		}
		initSet(n);
		vector< pair<int, ii> > E2;
		sort(EdgeList.begin(), EdgeList.end());
		FOR(i, EdgeList.size()){
			pair<int, ii> k = EdgeList[i];
        	if (!isSameSet(k.second.first, k.second.second)) {
            	setUnion(k.second.first, k.second.second);
        	}
        	else{
        		E2.pb(k);
        	}			
		}
		if(E2.size() == 0) pf("forest\n");
		else{
			sort(E2.begin(), E2.end());
			FOR(i, E2.size() - 1) pf("%d ", E2[i].first);
			pf("%d\n", E2[E2.size() - 1].first);
		}
	}
	return 0;
}