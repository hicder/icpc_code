/*
ID: phamduc1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

typedef vector<int> vi;
vector<vi> tri;

int dp[1001][1001];
int nrow;
/*
int dfs(int i, int j){
	if( i < 0 || j >= nrow || i >= (int)tri[j].size()) return 0;
	int rl = dfs(i, j+1);
	int rr = dfs(i+1, j+1);
	int max = rl>rr?rl:rr;
	return tri[j][i] + max;
}
*/
int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int t;
	cin >> nrow;
	int row = 0;
	tri.resize(nrow);
	memset(dp,0, sizeof(dp));
	while(cin >> t){
		tri[row].push_back(t);
		if((int)tri[row].size() == row + 1) row++;
	}
	
	for(int i = nrow - 1; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			dp[i][j] =  tri[i][j] + (dp[i+1][j] > dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1]);
		}
	}
//	int a = dfs(0,0);
	cout << dp[0][0] << endl;
	
	return 0;
}
