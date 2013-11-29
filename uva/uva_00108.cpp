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

int a[101][101];
int sum[101][101];
int best_sum[101][101];
int n;

void pv(int a[][101]){
	FOR(i,n){
		FOR(j, n){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	freopen("input", "r", stdin);
	cin >> n;
	FOR(i, n){
		FOR(j,n){
			cin >> a[i][j];
			sum[i][j] = -INF;
		}
	}
	
	sum[0][0] = a[0][0];

	for(int i = 1; i < n; i++){
		sum[0][i] = sum[0][i-1] + a[0][i];
		sum[i][0] = sum[i-1][0] + a[i][0];
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			sum[i][j] = sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] + a[i][j];
		}
	}
	int max, localsum;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			max = sum[i][j];
			for(int l = -1; l <= i; l++){
				for(int m = -1; m <= j; m++){
					localsum = sum[i][j];
					if(l >= 0) localsum -= sum[l][j];
					if(m >= 0) localsum -= sum[i][m];
					if(l >=0 && m >= 0) localsum += sum[l][m];
					if(localsum > max) max = localsum;
				}
			}
			best_sum[i][j] = max;
		}
	}
	max = -INF;
	FOR(i, n){
		FOR(j, n){
			if(best_sum[i][j] > max) max = best_sum[i][j];
		}
	}
	cout << max << endl;
	return 0;
}
