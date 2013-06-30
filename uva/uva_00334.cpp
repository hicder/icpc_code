#include <iostream>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

map<string, int> t;
map<int, string> f;
int d[400][400];
int nc, nm, ne;
int names;
void input(){
	memset(d, 0, sizeof(d));
	t.clear();
	f.clear();
	names = 0;
	for(int i = 0; i < nc; i++){
		cin >> ne;
		string temp, prev;
		prev = "NOTDEFINED";
		for(int j = 0; j < ne; j++){
			cin >> temp;
			if(t.find(temp) == t.end()){
				t[temp] = names++;
				f[names - 1] = temp;
			}
			if(prev == "NOTDEFINED"){
				prev = temp;
				continue;
			}
			else{
				d[t[prev]][t[temp]] = 1;
				prev = temp;
			}
		}
	}

	cin >> nm;
	for(int i = 0; i < nm; i++){
		string from, to;
		cin >> from >> to;
		if(t.find(from) == t.end()) t[from] = names++, f[names-1] = from;
		if(t.find(to) == t.end()) t[to] = names++, f[names - 1] = to;
		d[t[from]][t[to]] = 1;
	}
}

void exe(){
	for(int k = 0; k < names; k++){
		for(int i = 0; i < names; i++){
			for(int j = 0; j < names; j++){
				d[i][j] |= (d[i][k] & d[k][j]);
			}
		}
	}
}

int main(){
//	freopen("input", "r", stdin);
	cin >> nc;
	int caseno = 0;
	while(nc){
		if(nc == 0) break;
		input();
		exe();
		int nsol = 0;
		for(int i = 0; i < names; i++){
			for(int j = i + 1; j < names; j++){
				if(!d[i][j] && !d[j][i]){
					nsol++;
				}
			}
		}
		printf("Case %d, ", ++caseno);
		if(!nsol)cout << "no concurrent events.";
		else printf("%d concurrent events:\n", nsol);
		nsol = 0;
		for(int i = 0; i < names; i++){
			for(int j = i + 1; j < names; j++){
				if(!d[i][j] && !d[j][i]){
					nsol++;
					if(nsol <2) printf("(%s,%s) ", f[i].c_str(), f[j].c_str());
					else if (nsol == 2) printf("(%s,%s) ", f[i].c_str(), f[j].c_str());
				}
			}
		}
		cout << endl;
		cin >> nc;
	}
	return 0;
}