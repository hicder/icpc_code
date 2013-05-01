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
vector<pair<int, ii> > EdgeList;    //(weight, a, b)
vector<vii> AdjList;                //u -> (weight, v)
map<pii> visited;
vi parent;
vi piset;
int nvertices = 10;
int nedges = 10;
void initSet(int N){for (int i = 0; i < N; i++) {pset.push_back(i);}}

int findSet(int a){
    if (piset[a] == a) {
        return a;
    }
    else{
        pset[a] = findSet(piset[a]);
        return pset[a];
    }
}
bool isSameSet(int a, int b){return findSet(a) == findSet(b);}
void setUnion(int a, int b){pset[findSet(a)] = findSet(b);}
void initialize(){
    EdgeList.resize(nedges);
    AdjList.resize(nvertices);
    for (int i = 0; i < nvertices; i++) {
        parent.push_back(i);
    }
}


vii prim(int start){
    vii ret;
    priority_queue<ii> q;
    q.push_back(make_pair(0, start));
    while (!q.empty() && ret.size() < nvertices) {
        ii temp = q.top(); q.pop();
        ret.push_back(temp);
        for (int i = 0; i < AdjList[temp.second]; i++) {
            
            if (!visited[AdjList[temp.second][i]]) {
                parent[AdjList[temp.second][i].second] = ii.second;
                q.push_back(AdjList[temp.second][i]);
            }
        }
    }
    return ret;
}

void input(){
    
}

int main(){
	return 0;
}
