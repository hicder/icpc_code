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
#define INF 1000000000
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

vi list;
int n, dp[10005];

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d", &n) && n){
		int x; list.clear(); MS(dp);
		FOR(i, n){
			cin >> x; list.pb(x);
		}

		FOR(i, list.size()){
			if(i == 0) dp[0] = list[0];
			else{
				if(dp[i - 1] > 0) dp[i] = list[i] + dp[i-1];
				else{
					dp[i] = list[i];
				}
			}
		}
		int max = -INF;
		FOR(i, list.size()){
			if(dp[i] > max) max = dp[i];
		}
		if(max > 0) cout << "The maximum winning streak is "<<max<<"."<<endl;
		else cout << "Losing streak."<<endl;
	}
	return 0;
}