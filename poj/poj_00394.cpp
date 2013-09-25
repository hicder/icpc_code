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


long long DP[5005];

int main(){
	freopen("input", "r", stdin);
	string line;
	getline(cin, line);
	while(line != "0"){
		MS(DP);
		DP[0] = 1;
		if(line[1] == '0') DP[1] = 1;
		else if((line[0] - '0') * 10 + (line[1] - '0') <= 26) DP[1] = 2;
		else DP[1] = 1;
		for(int i = 2; i < line.length();i ++){
			DP[i] = DP[i-1];
			if(line[i] == '0'){
				DP[i] = DP[i-2];
				continue;
			}
			if(((line[i-1] - '0') * 10 + (line[i] - '0')) <= 26 && line[i-1] != '0') DP[i] += DP[i-2];
		}
		cout << DP[line.length()-1] << endl;
		getline(cin, line);
	}
	return 0;
}