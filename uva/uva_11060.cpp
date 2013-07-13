#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <map>
#define INF 128
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
#define MS(x) memset((x), 0, sizeof((x)))

using namespace std;
typedef vector<int> vi;
int n, m;
map<string,int> to;
map<int,string> from;

int AdjMatrix[105][105];
int out[105], in[105], visit[105], taken[105], etaken[105][105];
string temp;
vi ts;
priority_queue<int> q;

void bfs(){
	int u, v;
	while(!q.empty()){
		u = q.top(); q.pop();
		u = -1 * u;
		ts.pb(u);
		FOR(i,n){
			if(AdjMatrix[u][i]){
				AdjMatrix[u][i] = 0;
				in[i]--;
				if(!in[i] && !visit[i]) {
					q.push(-1 * i);
					visit[i] = 1;
				}
			}
		}
	}
}


int main(){
	freopen("input","r",stdin);
	int ca  = 1;
	while(scanf("%d", &n) != EOF && n){
	//	cout << n << endl;
		ts.clear();
		to.clear();
		from.clear();
		MS(in);MS(out);MS(AdjMatrix);MS(visit);MS(taken);MS(etaken);
		FOR(i,n){
			cin >> temp;
			to[temp] = i;
			from[i] = temp;
		}
		cin >> m;
		string u, v;
		FOR(i,m){
			cin >> u >> v;
			AdjMatrix[to[u]][to[v]] = 1;
			if(!etaken[to[u]][to[v]]){
				in[to[v]] ++;
				out[to[u]] ++;
				etaken[to[u]][to[v]] = 1;
			}
		}
		FOR(i,n){
			if(in[i] == 0) {
				q.push(-1*i);
			}
		}
		bfs();
		pf("Case #%d: Dilbert should drink beverages in this order: ",ca++);
		FOR(i,ts.size()-1)cout << from[ts[i]]<< " ";
		cout << from[ts[ts.size()-1]]<<"."<<endl<<endl;
		getline(cin,temp); getline(cin,temp);
		if(cin.eof()) break;
	}

	return 0;
}