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

map < int, char> _map;

int main(){
	freopen("input", "r", stdin);
	string line, bline, ret;
	bool done = false;
	//set up map
	_map[0] = ' ';
	FOR(i, 26){
		_map[i + 1] = (char)('A' + i);
	}
	_map[27] = '\'';
	_map[28] = ',';
	_map[29] = '-';
	_map[30] = '.';
	_map[31] = '?';
	while(1){
		bline = ""; ret = "";
		while(1){
			getline(cin, line);
			if(line == "*") break;
			else if(line == "#"){
				done = true;
				break;
			}
			else bline += line;
		}
		if(done) break;
		int nspace = 0; int num = 0; int count = 0;
		for(int i = 0; i < bline.length(); i++){
			if(bline[i] == ' ') {
				nspace++;
			}
			else if(nspace != 0){
				num = (num << 1) | (nspace % 2 ? 0 : 1);
				count ++ ;
				nspace = 0;
				if(count == 5){
			//		cout << num << endl;
					ret += _map[num];
					num = 0;
					count = 0;
				}
			}
		}
		num = num << (5 - count);	
		ret += _map[num];
		cout << ret << endl;
	}
	return 0;
}