#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <map>
#define INF 128
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define pf printf
#define MS(x) memset((x), 0, sizeof((x)))
using namespace std;
typedef vector<int> vi;
int t;
string temp;
int AdjMatrix[26][26], let;
vi ts;
int ex[26];
int out[26];
bool de = false;
bool check(int i){
	FOR(j, 26){
		if(AdjMatrix[j][i] && ex[j]) {
			return false;
		}
	}
	return true;
}

void dfs(int level){
	if(level == let){
		de = true;
		FOR(i, ts.size() - 1){
			pf("%c ", (char)(ts[i] + 'A'));
		}
		pf("%c\n", (char)(ts[ts.size() - 1] + 'A'));
		return;
	}
	FOR(i,26){
		if(ex[i] && check(i)){
			ts.pb(i);
			ex[i] = 0;
			dfs(level + 1);
			ts.pop_back();
			ex[i] = 1;
		}
	}
}

int main(){
//	freopen("input","r",stdin);
	cin >> t;
	getline(cin, temp);

	while(t--){
		de = false;
		MS(AdjMatrix);
		MS(ex);
		MS(out);
		ts.clear();
		let = 0;
		getline(cin, temp);
		getline(cin, temp);
		FOR(i,temp.size()){
			if(temp[i] == ' ') continue;
			else if(temp[i] == '\n') break;
			ex[temp[i] - 'A'] = 1;
			let++;
		}
		getline(cin,temp);
		int u, v;
		for(int i = 0; i < temp.size(); i+= 4){
			u = temp[i];
			v = temp[i+2];
			AdjMatrix[ u -'A'][ v - 'A'] = 1;
		}
		dfs(0);
		if(!de) cout << "NO"<<endl;
		if(t != 0) cout << endl;
	}
	return 0;
}