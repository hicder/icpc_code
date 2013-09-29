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
int n;
string line;
vector<string> sentences;
bool checkcapital(char a){
	if(a >= 65 && a <= 90) return true;
	else return false;
}

bool checkmark(char a){
	if(a == 46 || a == 63) return true;
	else return false;
}
int main(){
	freopen("input", "r", stdin);
	getline(cin, line);
	string sentence;
	FOR(i, line.length()){
		if(checkcapital(line[i])){
			sentence = "";
			sentence += line[i];
			continue;
		}
		if(checkmark(line[i])){
			sentence += line[i];
			sentences.pb(sentence);
			sentence = "";
			continue;
		}
		sentence += line[i];
	}
	FOR(i, sentences.size()){
		string s = sentences[i];
		if(s.length() > 6 && s.substr(0, 7) == "What is" && s[s.length() - 1] == '?'){
			string t = s.substr(7, s.length() - 7 - 1);
			t = "Forty-two is" + t + ".";
			cout << t << endl;
		}
	}
}