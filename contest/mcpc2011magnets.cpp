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
int al[26];

int main(){
	freopen("input", "r", stdin);
	string line;
	while(1){
		MS(al);
		getline(cin, line);
		if(line == "END") break;
		bool n = false;
		FOR(i, line.length()){
			if(line[i] >= 'A' && line['i'] <= 'Z'){
				al[line[i]-'A']++;
				if(al[line[i]-'A'] > 1){
					n = true;
					break;
				}
			}
		}
		if(n) continue;
		cout << line << endl;
	}
	return 0;
}