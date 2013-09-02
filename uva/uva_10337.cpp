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
int n, x;
int wsp[11][1001];
int memo[11][1001];


int main(){
	freopen("input", "r", stdin);
	cin >> n;
	while(n--){
		MS(wsp);

		cin >> x;
		for(int i = 9; i >= 0; i--){
			FOR(j, x/100){
				cin >> wsp[i][j];
			}
		}
		FOR(i, 10){
			FOR(j, x/100){
				memo[i][j] = INF;
			}
		}		
		memo[0][0] = 0;
		for(int j = 1; j <= x/100; j++){
			memo[0][j] = min(20 + memo[1][j-1] - wsp[1][j-1], 30 + memo[0][j-1] - wsp[0][j-1]);
			for(int i = 1; i <= j && i < 10; i++){
				if(i < 9){
					memo[i][j] = min(60 + memo[i-1][j-1] - wsp[i-1][j-1], min(30 + memo[i][j-1] - wsp[i][j-1], 20 + memo[i+1][j-1] - wsp[i+1][j-1]));
				}
				else if (i == 9){
					memo[9][j] = min(60 + memo[8][j-1] - wsp[8][j-1], 30 + memo[9][j-1] - wsp[9][j-1]);
				}
			}
		}
		pf("%d\n\n", memo[0][x/100]);
	}
	return 0;
}