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

int AdjMatrix[50001];
int visit[50001];
int passval[50001];
int cycle[50001];
int parent[50001];
int t,n;
void input(){
	memset(AdjMatrix,0,sizeof AdjMatrix);
	memset(visit,0,sizeof visit);	
	memset(passval,0,sizeof passval);
	memset(cycle,0, sizeof cycle);
//	memset(parent,0,sizeof parent);
	int u, v;
	cin >> n;
	FOR(i,n){
		cin >> u >> v;
		AdjMatrix[u] = v;
		parent[v] = u;
	}
}
int dfs(int u){
	int val;
	if(visit[u] == 2) {
	//	cout << "quick return"<<endl;
		return passval[u];
	}
	visit[u] = 1;
	if(!visit[AdjMatrix[u]]) {
		val = 1 + dfs(AdjMatrix[u]);
		if(cycle[AdjMatrix[u]] && u != cycle[AdjMatrix[u]] && cycle[AdjMatrix[u]] != AdjMatrix[u]) cycle[u] = cycle[AdjMatrix[u]];
		if(u == cycle[AdjMatrix[u]]) cycle[u] = u;
		passval[u] = val;
		visit[u] = 2;
		return passval[u];
	}
	else if(visit[AdjMatrix[u]] == 1) {
		//cycle detection
		passval[u] = 1;
		visit[u] = 2;
		int ver = AdjMatrix[u];
		cycle[u] = AdjMatrix[u];
		return passval[u];
	}
	else{
		if(!cycle[AdjMatrix[u]]) passval[u] = 1 + passval[AdjMatrix[u]];
		else{
			passval[u] = 1 + passval[cycle[AdjMatrix[u]]];			
		}
		visit[u] = 2;
		return passval[u];
	}
}

int pass(){
	visit[0] = 1;
	int maxi = 0;
	int maxval = 0;
	FOR(i,n){
	//	cout <<"from top: "<<(i+1)<<endl;
		int val = dfs(i+1);
		if(val > maxval){
			maxval = val;
			maxi = i+1;
		}
	}
	return maxi;
}



int main(){
//	freopen("input","r",stdin);
	cin >> t;
	int ca = 1;
	while(t--){
		input();
		int x = pass();
		pf("Case %d: %d\n",ca++, x);
	}
	return 0;
}