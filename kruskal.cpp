#include<algorithm>
#include<map>
#include<pair>
#include<utility>
#include<string>
#include<iostream>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int nvertices, nedges;
vector< pair<int, ii> > EdgeList;   /*(weight, a, b)*/

vi piset;
vector<vii> AdjList;

void initSet(int N){
    for (int i = 0; i < N; i++) {
        pset.push_back(i);
    }
}

int findSet(int a){
    if (piset[a] == a) {
        return a;
    }
    else{
        pset[a] = findSet(piset[a]);
        return pset[a];
    }
}

bool isSameSet(int a, int b){
    return findSet(a) == findSet(b);
}

void setUnion(int a, int b){
    pset[findSet(a)] = findSet(b);
}

void initialize(){
    EdgeList.resize(nedges);
    AdjList.resize(nvertices);
}


void input(){
    cin >> nvertices >> nedges;
    initialize();
    int u, v, w;
    for (int i = 0; i < nedges; i++) {
        cin >> u >> v >> w;
        EdgeList[0] = make_pair(w, ii(u,v));
    }
}

int kruskal(){
    int ret = 0;
    sort(EdgeList.begin(), EdgeList.end());
    initSet(nvertices);
    for (int i = 0; i < EdgeList.size(); i++) {
        pair<int, ii> t = EdgeList[i];
        if (isSameSet(t.second.first, t.second.second)) {
            ret+= t.first;
            setUnion(t.second.first, t.second.second);
        }
    }
    return ret;
}

int main(){
    input();
    int a = kruskal();
    cout << a << endl;
    return 0;
}