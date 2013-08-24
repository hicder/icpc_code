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
#include <string>
#include <cmath>
#include <set>
#define INF 1000000000
#define MAXV 50102
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define pf printf
#define MS(a) memset((a), 0, sizeof((a)))
#define sqr(a) ((a) * (a))

using namespace std;

int t;
string line;
vector <string> dic;	
vector<string> src, des;
vector<int> visit;

bool diff(string s, string t){
	if(s.length() != t.length()) return false;
	int nd = 0;
	FOR(i, s.length()){
		if(s[i] != t[i]) nd++;
	}
	if(nd == 1) return true;
	else return false;
}


int bfs(string s, string t){
	queue< pair<string, int> > q;
	q.push(make_pair(s, 0));
	while(!q.empty()){
		pair<string,int> start = q.front(); q.pop();
		if(start.first == t) return start.second;
		FOR(i, dic.size()){
			if(visit[i]) continue;
			else if (diff(start.first, dic[i])){
				visit[i] = 1;
				q.push(make_pair(dic[i], start.second + 1));
			}
		}
	}
	
}

int find(string s){
	FOR(i, dic.size()){
		if(dic[i] == s) return i;
	}
	return -1;
}


int main(){
	freopen("input", "r", stdin);
	cin >> t;
	getline(cin, line); getline(cin, line);
	while(t--){
		dic.clear(); src.clear(); des.clear();
		while(1){
			getline(cin, line);
			if(line == "*") break;
			dic.pb(line);
		}
		string source, dest;
		while(1){
			getline(cin, line);
			if(line == "") break;
			stringstream ss(line);
			ss >> source >> dest;
			src.pb(source); des.pb(dest);
		}
		FOR(i, src.size()){
			visit.assign(dic.size(), 0);
			visit[find(src[i])] = 1;
			int a = bfs(src[i], des[i]);
			cout << src[i] << " " << des[i] << " " << a << endl;
		}
		if(t != 0) cout << endl;
	}
	return 0;
}