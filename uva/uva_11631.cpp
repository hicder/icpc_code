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

void initSet(int N){pset.clear(); FOR(i, N) pset.pb(i);}
int findSet(int a){
    if (pset[a] == a) {return a;}
    else{ pset[a] = findSet(pset[a]); return pset[a];}}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void setUnion(int a, int b){ pset[findSet(a)] = findSet(b);}

int m, n, x, y, z;

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d%d", &m, &n) && (m || n)){
		EdgeList.clear();
		int sum = 0;
		FOR(i,n){
			cin >> x >> y >> z;
			sum += z;
			EdgeList.pb(make_pair(z, make_pair(x,y)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		initSet(m);
		int ret = 0;
		FOR(i, EdgeList.size()){
			pair<int, ii> k = EdgeList[i];
        	if (!isSameSet(k.second.first, k.second.second)) {
        		ret += k.first;
            	setUnion(k.second.first, k.second.second);
        	}
		}
		pf("%d\n", sum - ret);
	}
	return 0;
}