#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define WHITE 1
#define BLACK 2
#define UNCOLOR 0
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;



int nvertices, nedges;
vi visit;
int color[100000];
vvi AdjList;
bool ret;
queue<int> q;

void input(){
	cin >> nedges;
	int u, v;
	AdjList.clear();
	AdjList.resize(nvertices);
	visit.resize(nvertices);
	memset(color,0,sizeof(color));
	for(int i = 0; i < nvertices; i++){
		visit[i] = 0;
	}
	for(int i = 0; i < nedges;i++){
		cin >> u >> v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
}

void traverse(){
	q.push(0);
	visit[0] = 1;
	color[0] = WHITE;
	
	while(!q.empty()){
		int u = q.front(); q.pop();
		int v;
		for(int i = 0; i <(int) AdjList[u].size();i++){
			v = AdjList[u][i];
			if(color[v] == UNCOLOR){
				if(color[u] == WHITE) color[v] = BLACK;
				else color[v] = WHITE;
				visit[v] = 1;
				q.push(v);
			}
			else{
				if(color[v] == color[u]){
					ret = false;
					return;
				}
			}
		}
	}
}


int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	while(1){
		ret = true;
		cin >> nvertices;
		if(!nvertices) return 0;
		while(!q.empty()) q.pop();
		input();
		traverse();
		if(!ret) cout << "NOT BICOLORABLE.\n";
		else cout << "BICOLORABLE.\n";
		
	}
	
	return 0;
}
