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

int n;
int ti[1005];
vector< pair <int, int > > s;
vi x, t;
bool imp;
void schedule(int i, int dl){
	if(dl < 0){
		imp = true;
		return;
	}
	if(i == s.size()) {
		cout << dl << endl;
		return;
	}
	schedule(i + 1, min(s[i].first, dl) - s[i].second);
}

int main(){
	freopen("input", "r", stdin);
	while(scanf("%d", &n) && n){
		MS(ti);
		x.clear();
		t.clear();
		s.clear();
		imp = false;
		int a;
		FOR(i,n){
			cin >> a;
			x.pb(a);
		}
		FOR(i, n){
			cin >> a;
			t.pb(a);
		}
		FOR(i, n){
			s.pb(make_pair(t[i], x[i]));
		}

		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		schedule(0, INF);
		if(imp) cout << "impossible" << endl;
	}
}