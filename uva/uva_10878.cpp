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


int main(){
	freopen("input", "r", stdin);
	string code = "";
	string line;
	getline(cin, line);
	while(!cin.eof()){
		unsigned char a = 0;
		FOR(i, line.length()){
			if(line[i] == ' ') a = a << 1;
			else if(line[i] == 'o') a = (a << 1) | 1;
		}
		if(line != "" && a) cout << a;
		getline(cin, line);
	}
	return 0;
}