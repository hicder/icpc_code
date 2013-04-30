#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stdio.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vi>AdjList;
vi ninto;
vi translation;          //translate to zero-based nodes
int nvertices, nedges;
int done;
bool dfs_num[100000];
bool isTree;
void initialize(){
    AdjList.clear();
    AdjList.resize(100000);
    translation.clear();
    ninto.clear();
    for (int i = 0; i < 100000; i++) {
        ninto.push_back(0);
        translation.push_back(-1);
        dfs_num[i] = UNVISITED;
    }
    nvertices = 0;
    nedges = 0;
}

void input(){
    int u, v;
    while (1) {
        cin >> u >> v;
        if (u == -1 || v == -1) {
            done = true;
            return;
        }
        if (u == 0 || v == 0) {
            return;
        }
        if (translation[u] == -1) {
            translation[u] = nvertices++;
        }
        if (translation[v] == -1) {
            translation[v] = nvertices++;
        }
        AdjList[translation[u]].push_back(translation[v]);
        ninto[translation[v]]++;
        nedges++;
    }
}

void dfs(int start){
    dfs_num[start] = VISITED;
    for (int i = 0; i < AdjList[start].size(); i++) {
        if (!isTree) {
            return;
        }
        if (!dfs_num[AdjList[start][i]]) {
            dfs(AdjList[start][i]);
        }
        else{
            isTree = false;
            return;
        }
    }
}

int main(){
    int ncase = 0;
    done = false;
    while (!done) {
        bool local_done = false;
        ncase++;
        initialize();
        nvertices = 0;
        input();
        if (done) {
            return 0;
        }
        if (nvertices == 0) {
            printf("Case %d is a tree\n",ncase);
            continue;
        }
        for (int i = 0; i < nvertices; i++) {
            if (ninto[i] == 0) {
                isTree = true;
                dfs(i);
                if (isTree) {
                    printf("Case %d is a tree\n",ncase);
                    local_done = true;
                    break;
                }
            }
        }
        if (local_done) {
            continue;
        }
        printf("Case %d is not a tree\n",ncase);
    }
    
    return 0;
}