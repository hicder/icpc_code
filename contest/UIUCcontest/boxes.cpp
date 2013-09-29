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
int need[1000006];
int sq[1005][1005];
int m, n, s;

vi x;
vi y;



int main(){
	freopen("input", "r", stdin);
	while(scanf("%d%d%d", &m, &n, &s) && m){
			MS(need); MS(sq);
			int a, b;
			x.clear();
			y.clear();
			FOR(i, s){
				cin >> a >> b;
				x.pb(b-1);
				y.pb(a-1);
				sq[b-1][a-1] = INF;
			}
			int count = 0;
			for(int j = 0; j < m; j++){
				FOR(i, n){
					if(sq[i][j] != INF){
						FOR(k, x.size()){
							sq[i][j] = max(sq[i][j], INF - max(abs(i - x[k]), abs(j - y[k])));
						}
					}
					if(!need[sq[i][j]]){
						count++;
						need[sq[i][j]] = 1;
					}
					cout << sq[i][j] << " ";
				}
				cout << endl;
			}
			cout << count << endl;
	}

	
}