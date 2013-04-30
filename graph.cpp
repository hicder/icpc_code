#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>
#DEFINE DFS_WHITE 0
#DEFINE DFS_BLACK 1
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> AdjList;		//Adjacency list will be a vector of pairs of integer, in the form of (a, weight)
int nvertices, nedges;

vi bfs_num;
vi dfs_num;

void initialize(){
    AdjList.resize(nvertices);
    dfs_num.resize(nvertices);
    for (int i = 0; i < nvertices; i++) {
        dfs_num[i] = DFS_WHITE;
    }
}

void bfs(int start){
    vi s;
    s[start] = 0;
    queue qnodes;
    qnodes.push(start);
    while (!qnodes.empty()) {
        int u = qnodes.front();qnodes.pop();
        bfs_num[u] = DFS_BLACK;
        for (int i = 0; i < AdjList[u].size(); i++) {
            ii v = AdjList[u][i];
            if (!bfs_num[v.first]) {
                s[v.first] = s[u] + 1;  //distance from the start
                qnodes.push(v.first);
            }
        }
        
    }
}

void dfs(int u){
    dfs_num[u] = DFS_BLACK;
    for (int i = 0; i < AdjList[u].size(); i++) {
        ii v = AdjList[u][i];
        if (!dfs_num[v.first]) {
            dfs(v.first);
        }
    }
}

/*****************
Let's say here's the input:
nvertices nedges
##next nedges lines are those edges, which are undirected
******************/

void input(){
    cin >> nvertices >> nedges;
    initialize();
    int u, v;
    for (int i = 0;  i< nedges; i++) {
        cin >> u >> v;
        vi k(v, 1);
        AdjList[u].push(k);
        //ignore the next two lines if doing directed graph
        vi k2(u, 1);
        AdjList[v].push(k2);
    }
}


int main(){
    input();
    for (int i = 0; i < nvertices; i++) {
        if (!bfs_num[i]) {
            bfs(i);
        }
    }
}
