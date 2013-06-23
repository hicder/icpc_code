#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXINT 1000000
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
int t, nver, nedge;
int dist[101][101];
int start, end;

void input(){
	int u, v;
	cin >> nver >> nedge;
	for(int i = 0; i < nver; i++){
		for(int j = 0; j < nver; j++){
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = MAXINT;
		}
	}
	
	for(int i = 0; i < nedge; i++){
		cin >> u >> v;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}
	cin >> start >> end;
}

void travel(){
	for(int k = 0; k < nver; k++){
		for(int i = 0; i < nver; i++){
			for(int j = 0; j < nver; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
//	freopen("input","r", stdin);
	cin >> t;
	int c = 0;
	while(t--){
		input();
		travel();
		int maxdist = 0;
		for(int i = 0; i < nver; i++){
			if(dist[start][i] + dist[i][end] > maxdist) maxdist = dist[start][i] + dist[i][end];
		}
		printf("Case %d: %d\n",++c,maxdist);
	}
	return 0;
}
