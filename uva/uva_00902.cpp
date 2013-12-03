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

int n; string x;
map<string, int> m;
vector<string> v;
map<string, int>::iterator it;
int main(){
	freopen("input", "r", stdin);
	while(cin >> n >> x){
		m.clear();
		v.clear();
		for(int i = 0; i <= x.length() - n; i++){
			string temp = x.substr(i, n);
			m[temp]++;
		}
		int freq = 0;
		string maxstr;
		for(it = m.begin(); it != m.end(); it++){
			if(it->second > freq){
				freq = it->second;
				maxstr = it->first;
			}
		}
		cout << maxstr << endl;
	}

	return 0;
}