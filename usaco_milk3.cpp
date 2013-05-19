/*
ID: phamduc1
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>

#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

int a, b, c;
int cura, curb, curc;
int cval[21];
bool visit[21][21];
vector<int> ret;

void dfs(int aa, int bb, int cc){
	if(cc <0 || aa < 0 || bb < 0) return;
	if(visit[bb][cc] == 1) return;
//	cout << aa << " " << bb << " " << cc << endl;
	if(aa == 0) cval[cc] = 1;
	visit[bb][cc] = 1;
	int topour;
	//recursion
	// a to b:

	topour = min(aa, b - bb);
	dfs(aa - topour, bb + topour, cc);
	// b to c:
	topour = min(bb, c - cc);
	dfs(aa, bb - topour, cc + topour);
	// a to c:
	topour = min(aa, c - cc);
	dfs(aa - topour, bb , cc+ topour);
	
	//c to a:
	topour = min(a - aa, cc);
	dfs(aa + topour, bb , cc - topour);
	
	//c to b:
	topour = min(b - bb, cc);
	dfs(aa, bb + topour, cc - topour);
	
	//b to a:
	topour = min(bb, a - aa);
	dfs(aa + topour, bb - topour, cc);
}

int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	memset(visit, 0, sizeof(visit));
	memset(cval, 0, sizeof(cval));
	cin >> a >> b >> c;
	dfs(0,0, c);
	//cout << ret.size() << endl;
	int ccc = 0;
	for(int i = 0; i < 21; i++){
		if(cval[i]) ccc = i;
	}
	for(int i = 0; i < 21; i++){
		if(cval[i]) {cout << i;
		if(i != ccc) cout << " ";}
	}
	cout << endl;
	return 0;
}
