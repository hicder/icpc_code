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
int n,s,p;




int main(){
	freopen("input", "r",stdin);
	cin >> n;
	while(n--){
		EdgeList.clear();
		MS(cx), MS(cy);
		cin >> s >> p;
		FOR(i, p){
			cin >> cx[i] >> cy[i];
		}

		FOR(i, p){
			for(int j = i + 1; j < p; j++){
				EdgeList.pb(make_pair(dis(i,j), make_pair(i,j)));
			}
		}
		vector< pair<int, ii> > nList;   /*(weight, a, b)*/

		sort(EdgeList.begin(), EdgeList.end());
		initSet(p);
		int nset = 0;
		FOR(i, EdgeList.size()){
			pair<int, ii> k = EdgeList[i];
			if(!isSameSet(k.second.first, k.second.second)){
				nList.pb(k);
				setUnion(k.second.first, k.second.second);
				nset++;
			}
			if(nset == (p-s)){
				break;
			}
		}
		pair<int, ii> k = nList[nList.size()-1];
		pf("%.2f\n", sqrt(dis(k.second.first, k.second.second)));
	}

	return 0;
}