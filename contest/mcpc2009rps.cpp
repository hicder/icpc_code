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
string line1, line2;
int winner(char pl1, char pl2){
	if(pl1 == 'R' && pl2 == 'S') return 0;
	else if(pl1 == 'S' && pl2 == 'R') return 1;
	else if(pl1 == 'S' && pl2 == 'P') return 0;
	else if(pl1 == 'P' && pl2 == 'S') return 1;
	else if(pl1 == 'R' && pl2 == 'P') return 1;
	else if(pl1 == 'P' && pl2 == 'R') return 0;

	return -1;
}
int main(){
	freopen("input", "r", stdin);
	while(1){
		getline(cin, line1);
		getline(cin, line2);
		if(line1 == "E") break;
		int p[2];MS(p);
		FOR(i, line1.length()){
			if(line1[i] == line2[i]) continue;
			else{
				p[winner(line1[i], line2[i])]++;
			}
		}
		cout << "P1: "<< p[0] << endl << "P2: "<<p[1] << endl;
	}
	return 0;
}