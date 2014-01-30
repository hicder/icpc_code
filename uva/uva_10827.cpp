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
#define max(a,b) ((a) > (b) ? (a):(b))
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
int a[152][152];
int t, n;

int main(){
	freopen("input", "r", stdin);
	cin >> t;
	while(t--){
		MS(a);
		cin >> n;
		FOR(i, n * 2){
			FOR(j, n * 2){
				if(i < n && j < n) {
					cin >> a[i][j];
					a[i + n][j] = a[i][j + n] = a[i+n][j + n] = a[i][j];
				}
				if(i > 0) a[i][j] += a[i-1][j];
				if(j > 0) a[i][j] += a[i][j-1];
				if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
			}
		}
		int max, local, godlikemax = -INF;
		FOR(i, n * 2){
			FOR(j, n * 2){
				max = a[i][j];
				for(int x = i + 1; x < i + n; x++){
					for(int y = j + 1; y < j + n; j++){
						local = a[i][j];
						if(x > (i - n - 1) && x > -1) local -= a[x][j];
						if(y > (j - n - 1) && y > -1) local -= a[i][y];

						if(local > max) max = local;
					}
				}
				if(max > godlikemax) godlikemax = max;
			}
		}
		cout << godlikemax << endl;
	}
	return 0;
}