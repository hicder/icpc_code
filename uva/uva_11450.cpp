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


int m, c, memo[201][25], n, price[25][25];

int shp(int money, int ngarment){
	if(money < 0) return -2;
	if(ngarment == c) return m - money;
	if(memo[money][ngarment] != -1) return memo[money][ngarment];
	int ans = -1;
	for(int i = 1; i <= price[ngarment][0]; i++){
		ans = max(ans, shp(money - price[ngarment][i], ngarment + 1));
	}
	return memo[money][ngarment] = ans;
}

int main(){
	freopen("input", "r", stdin);
	cin >> n;
	while(n --){
		cin >> m >> c;
		MS(price);
		FOR(i, c){
			cin >> price[i][0];
			FOR(j, price[i][0]){
				cin >> price[i][j+1];
			}
		}

		memset(memo, -1, sizeof memo);
		int retval = shp(m, 0);
		if(retval >= 0) pf("%d\n", retval);
		else pf("no solution\n");
	}
	return 0;
}