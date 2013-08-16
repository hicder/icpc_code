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

int t, n, tv;			//tv is threshold value
int cx[1005], cy[1005];

vector< pair<int, ii> > EdgeList;   /*(weight, a, b)*/

vi pset;

void initSet(int N){ pset.clear(); FOR(i, N) pset.pb(i);}
int findSet(int a){
    if (pset[a] == a) {return a;}
    else{ pset[a] = findSet(pset[a]); return pset[a];}}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void setUnion(int a, int b){ pset[findSet(a)] = findSet(b);}
int dis(int i, int j){
	return sqr(cx[i] - cx[j]) + sqr(cy[i] - cy[j]);
}

double rn(double a){
	return floor(a + 0.5);
}

int main(){
//	freopen("input", "r", stdin);
	cin >> t;
	int ca = 1;
	while(t--){
		cin >> n >> tv;
		MS(cx); MS(cy);
		FOR(i,n){
			cin >> cx[i] >> cy[i];
		}
		initSet(n);
		EdgeList.clear();
		FOR(i, n){
			for(int j = i + 1; j < n; j++){
				int dist = dis(i,j);
				EdgeList.pb(make_pair(dist, make_pair(i,j)));
			}
		}

		sort(EdgeList.begin(), EdgeList.end());
		vector< pair<int, ii> > resEdges;
		for (int i = 0; i < EdgeList.size(); i++) {
        	pair<int, ii> k = EdgeList[i];
        	if (!isSameSet(k.second.first, k.second.second)) {
            	resEdges.pb(k);
            	setUnion(k.second.first, k.second.second);
        	}
    	}
    	int nrail = 0, nroads = 0, nstates = 0;
    	double raillength = 0.0, roadlength = 0.0;
    	FOR(i, resEdges.size()){
    		pair<int, ii> k = resEdges[i];
    		if(k.first > sqr(tv)) {
    			nrail++;
    			raillength += sqrt(k.first);
    		}
    		else{
    			roadlength += sqrt(k.first);
    		}
    	}
    	nroads = resEdges.size() - nrail;
    	nstates = nrail + 1;
    	pf("Case #%d: %d %d %d\n",ca++, nstates, (int)rn(roadlength), (int)rn(raillength));
	}
	return 0;
}