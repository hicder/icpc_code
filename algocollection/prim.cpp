#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<priority_queue>
#include<map>
#define MAX_INT 10000000;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, ii> pii;
typedef priority_queue<ii> pqii;
vector<vii> AdjList;                //u -> (weight, v)
map<pii> visited;

int nvertices = 10;
int nedges = 10;
int mst = 0;
vi taken;
pqii q;

void initialize(){
    AdjList.resize(nvertices);
    for (int i = 0; i < nvertices; i++) {
        taken.push_back(0);
    }
}


void process(int vx){
	taken[vx] = 1;
	for(int i = 0; i < AdjList[vx].size(); i++){
		if(!taken[AdjList[vx][i].second]) q.push(ii(-AdjList[vx][i].first, -AdjList[vx][i].second));
	}
}

void prim(int start){
	taken[start] = 1;
	process(start);
	while(!q.empty()){
		ii temp = q.top(); q.pop();
		int w = -temp.first;
		int v = -temp.second;
		if(!taken[v]){
			mst+= w;
			process(v);
		} 
	}
	printf("The length of the MST is: %d\n",mst);
}

void input(){
	//similar to other graph files
}

int main(){
	input();
	prim();
	return 0;
}
