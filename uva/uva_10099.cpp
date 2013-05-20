#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 1000000
#define MIN_INT -1000000
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vector<vii> AdjList;

int d[101][101];
int visit[101];
int n, r;
int start, end;
int npass;
void init(){
	memset(d,MIN_INT,sizeof(d));
	memset(visit, 0, sizeof(visit));
}

void input(){
	int u, v, w;
	AdjList.clear();
	AdjList.resize(n+1);
	for(int i = 0; i < r; i++){
		cin >> u >> v >> w;
		AdjList[u].push_back(ii(v,w));
		AdjList[v].push_back(ii(u,w));
	}
	cin >> start >> end >> npass;
	d[end][end] = MAX_INT;
}

void exe(int a){
	if(a != end) visit[a] = 1;
	else{
		return;
	}
	int max_dis = 0;
	for(int i = 0; i< (int)AdjList[a].size(); i++){
		int n = AdjList[a][i].first;
		int temp = 0;
		if(!visit[n]){
			exe(n);
		}
		temp = min(d[n][end],AdjList[a][i].second);
		d[a][n] = min(AdjList[a][i].second,temp);
		if(d[a][n] > max_dis) max_dis=d[a][n];
	}
	d[a][end] = max_dis;
}

int main(){
	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	int c = 0;
	cin >> n >> r;
	while(n){
		if(n == 0) break;
		c++;
		printf("Scenario #%d\n",c);
		init();
		input();
		exe(start);
		int ret = d[start][end];
		int a = 0; if (npass % (ret-1)) a = 1;
		int t = npass / (ret - 1) + a;
		cout<<"Minimum Number of Trips = "<<t<<"\n";
		cin >> n >> r;
		cout << "\n";
	}
	fclose(stdout);
	return 0;
}
