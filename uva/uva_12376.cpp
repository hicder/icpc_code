#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t,n,m,maxf;
vi AdjList[105];
int val[105];
bitset<105> visit;
void input(){
	memset(val, 0, sizeof val);
	int w,u,v;
	cin >> n >> m;
	FOR(i,105) AdjList[i].clear();
	FOR(i,n){
		cin >> w;
		val[i] = w;
	}
	FOR(i,m){
		cin >> u >> v;
		AdjList[u].pb(v);
	}
}

int go(){
	int retval = 0;
	queue<int> q;
	visit.reset();
	q.push(0); visit[0] = 1;
	int prev = 0;
	maxf = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		int maxu = 0;
		FOR(i, AdjList[u].size()){
			int v  =AdjList[u][i];
			if(!visit[v]){
				if(val[v] > val[maxu]) maxu = v;
			}
		}
		if(!maxu) break;
		visit[maxu] = 1;
		q.push(maxu);
		maxf += val[maxu];
		prev = maxu;
	}
	return prev;
}

int main(){
//	freopen("input","r",stdin);
	cin >> t;
	int ca = 1, lastu;
	while(t--){
		input();
		lastu = go();
		pf("Case %d: %d %d\n",ca++,maxf, lastu);
	}
	return 0;
}