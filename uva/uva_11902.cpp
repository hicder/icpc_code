#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <bitset>
#define INF 1000000000
#define pf printf
#define pb push_back
#define FOR(i,N) for(int i = 0; i < (N); i++)
using namespace std;
typedef vector<int> vi;
bitset<110> visit;
int b[110][110], bd[110][110];
int n, t;
void input(){
	memset(b, 0, sizeof b);
	memset(bd,0, sizeof bd);
	cin >> n;
	FOR(i,n) FOR(j,n){
		cin >> b[i][j];
	}
}


void dfs(int s, int offv){
	visit[s] = 1;
	if(s == offv) return;
	FOR(i,n){
		if(b[s][i] && !visit[i]){
			dfs(i, offv);
		}
	}
}

void par(){
	pf("+");
	FOR(i,(2*n-1)) pf("-");
	pf("+\n");
	FOR(i,n){
		pf("|");
		FOR(j,n) pf("%c|", bd[i][j]?'Y':'N');
		pf("\n");
		pf("+");
		FOR(i,(2*n-1)) pf("-");
		pf("+\n");
	}
}

int main(){
	freopen("input","r",stdin);
	cin >> t;
	int ca = 1;
	while(t--){
		input();
		visit.reset();
		dfs(0,INF);
		FOR(i,n){
			if (visit[i]) bd[i][i] = 1, bd[0][i] = 1;
		}
		for(int i = 1; i < n; i++){
			if(!bd[i][i]) continue;
			visit.reset();
			dfs(0, i);
			for(int j = 1; j < n; j++){
				if(i == j) continue;
				if(!visit[j] && bd[0][j]) bd[i][j] = 1;
			}
		}
		pf("Case %d:\n", ca++);
		par();
	}
}