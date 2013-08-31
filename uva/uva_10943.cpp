
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

int n, k;
long long memo[102][102];			//n, k

long long addup(int num, int level){	//num = n; level = k;
	if(memo[num][level] != -1) return memo[num][level];
	long long ans = 0;
	for(int i = 0; i <= num; i++){
		ans = ans % 1000000 + addup(i, level - 1) % 1000000;
	}
	return memo[num][level] = ans;
}

int main(){
	freopen("input", "r", stdin);
	memset(memo, -1, sizeof memo);
	for(int i = 0; i <= 100; i++){
			memo[0][i] = 1;
			memo[i][0] = 0;
	}
	for(int i = 1; i <= 100; i++) memo[i][1] = 1;
	while(scanf("%d%d", &n, &k) && (n || k)){
		cout << (addup(n,k) % 1000000) <<endl;

	}
	return 0;
}