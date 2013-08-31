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

long long dp[55][55];
int n, k, m;

long long ways(int xn,int xk){
	if(xn == 0 && xk == 0) return 1;
	if(xn < xk || xk <= 0) return 0;

	if(dp[xn][xk] != -1) return dp[xn][xk];
	long long r = 0;
	for(int i = 1; i <= m; i++){
		r += ways(xn - i, xk - 1);
	}
	return (dp[xn][xk] = r);
}

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d %d %d", &n, &k, &m) == 3){
		FOR(i, 55){
			FOR(j, 55){
				dp[i][j] = -1;
			}
		}
		cout << ways(n,k) << endl;
	}
	return 0;
}