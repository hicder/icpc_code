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
int n, m;
string line;
string a[10];

int main(){
	freopen("input", "r", stdin);
	cin >> n;
	getline(cin, line);	// remove extra endline character
	while(n--){
		string message = "";
		getline(cin, a[0]);
		m = a[0].length() -2;
		message.resize(m);
		FOR(i,9){
			getline(cin, a[i+1]);
		}
		for(int i = 0; i < m; i++) message[i] = 0;
		for(int j = 1; j < m+1; j++){
			for(int i = 1; i < 9; i++){
				message[j - 1] |= ((a[i][j] == '/')?0:1) << (i-1);
			}
		}
		cout << message << endl;
		getline(cin, line);
	}
	return 0;
}