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
#include <cstring>
#include <string>
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


int e, n, t;
vi AdjM[2502], tcases, visit;
int si[2502];

int bfs(int s){
	visit[s] = 1;
	si[0] = 0;
	queue< pair<int, int> > q;	// (node, level)
	q.push(make_pair(s, 0));
	int maxlev = 0;
	while(!q.empty()){
		pair<int, int> u = q.front(); q.pop();
		if(u.second > maxlev) maxlev = u.second;
		FOR(i, AdjM[u.first].size()){
			if(!visit[AdjM[u.first][i]]){
				si[u.second + 1] ++;
				visit[AdjM[u.first][i]] = 1;
				q.push(make_pair(AdjM[u.first][i], u.second + 1));
			}
		}
	}
	return maxlev;
}

int main(){
//	freopen("input", "r", stdin);
	cin >> e;
	FOR(i, e){
		AdjM[i].clear();
		cin >> n;
		FOR(j, n){
			int w; cin >> w;
			AdjM[i].pb(w);
		}
	}
	cin >> t;
	tcases.clear();
	FOR(i, t){
		int w; cin >> w; tcases.pb(w);
	}
	FOR(i, tcases.size()){
		visit.assign(e, 0);
		MS(si);
		int maxlev = bfs(tcases[i]);
		int m = 0, d = 0;
		FOR(j, maxlev + 2){
			if(si[j] > m){
				m = si[j]; d = j;
			}
		}
		if(d == 0) pf("0\n");
		else pf("%d %d\n", m, d);
	}

	return 0;
}