#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#define min(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
using namespace std;
typedef vector<int> vi;

int res[38][38], f, mf, total;
bool done = false;
vi p;

void input(){
	total = 0;
	memset(res, 0, sizeof res);
	for(int i = 0; i< 10; i++){
		res[i + 27][37] = 1;
	}
	string m;

	while(getline(cin, m)){
		if(m.length() == 0) break;
		int u = m[0] - 'A' + 1;
		int nus = m[1] - '0';
		total += nus;
		res[0][u] = nus;
		int i = 3;
		while(m[i] != ';'){
			int v = m[i] - '0' + 27;
			res[u][v] = INF;
			i++;
		}
	}
}

void augment(int v, int mine){
	if(v == 0){
		f = mine;
		return;
	}
	else if(p[v] != -1){
		augment(p[v],min(mine,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void exe(){
	while(1){
		f = 0;
		bitset<38> v;
		v[0] = 1;
		queue<int> q; q.push(0);
		p.assign(38, -1);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == 37) break;
			for(int i = 0; i < 38; i++){
				if(res[u][i] > 0 && v[i] == 0){
					q.push(i); v[i] = 1; p[i] = u;
				}
			}
		}

		augment(37, INF);
		if(f == 0) break;
		mf += f;
	}
}

int main(){
//	freopen("input", "r", stdin);
	while(!cin.eof()){
		mf = 0;
		total = 0;
		input();
		exe();
		if(mf != total) cout << "!"<<endl;
		else{
			for(int i = 27; i < 37; i++){
				bool g = false;
				for(int j = 1; j < 27; j++){
					if(res[i][j]){
						g = true;
						cout << (char)(j - 1 + 'A');
						break;
					}
				}
				if(!g) cout << "_";
			}
			cout << endl;
		}
	}
	return 0;
}