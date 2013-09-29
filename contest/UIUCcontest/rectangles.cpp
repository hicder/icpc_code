#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <map> 
#include <stack>

#define INF 1000005
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define pf printf
#define MS(a) memset((a), 0, sizeof((a)))
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;

vector <pair < pair<int,int> , pair<int,int> > > cods;
int DP[1005];
bool check(int i, int j){
	if(cods[i].first.first < cods[j].second.first && cods[i].first.second < cods[j].second.second) return true;
	else return false;
}
int main(){
	freopen("input", "r",stdin);
	while(scanf("%d", &n) && n){
		int x1, x2, y1, y2;
		cods.clear();
		FOR(i, n){
			cin >> x1 >>  y1 >> x2 >> y2;
			cods.pb(make_pair(make_pair(x2,y2), make_pair(x1,y1)));
		}
		memset(DP, 1, sizeof(DP));
		sort(cods.begin(), cods.end());

		FOR(i, n){
			cerr << cods[i].second.first << " " << cods[i].second.second << " " << cods[i].first.first << " " << cods[i].first.second << endl;
		}
		for(int i = n - 1; i >=0 ; i--){
			DP[i] = 1;
			for(int j = i + 1; j < n; j++){
				if(check(i,j)) DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		int maxlen = 0;
		FOR(i, n){
			if(DP[i] > maxlen) maxlen = DP[i];
		}
		cout << maxlen << endl;
	}
}