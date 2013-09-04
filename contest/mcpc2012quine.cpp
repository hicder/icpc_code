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

string currstring;
bool valid(char c){
	if((c >= 65 && c <= 90) || c == 32) return true;
	else return false;
}

bool checkquine(string s){
	if(s[0] != '\"') return false;
	if(s[1] == ' ') return false;
	string t = "";
	int i = 0;
	for (i = 1; i < s.length(); i++){
		if(s[i] == '\"') break;
		else{
			if(valid(s[i])) t = t + s[i];
		}
	}
	if(t.length() != s.length() - 3 - t.length()) {
		return false;
	}
	int count = 0;
	for(int j = i + 2; j < s.length(); j++){
		if(t[count++] != s[j]) return false;
	}
	currstring = t;
	return true;
}

int main(){
	freopen("input", "r", stdin);
	string line;
	getline(cin, line);
	while(line != "END"){
		currstring = "";
		if(checkquine(line)) cout << "Quine("<<currstring<<")"<<endl;
		else cout << "not a quine"<<endl;
		getline(cin, line);
	}
	return 0;
}