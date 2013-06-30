#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#define min(a,b) (a)<(b)?(a):(b)
#define MAXX 1e8
using namespace std;

int npp, nv, ne;
map<string, int> t;
map<int, string> f;

int d[51][51];
int d1[51][51];
int d2[51][51];
int main(){
//	freopen("input", "r", stdin);
	int nn = 1;
	while(1){
		npp = 0;
		nv = 0;
		ne = 0;
		t.clear();
		f.clear();
		memset(d, 0, sizeof(d));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		cin >> nv >> ne;
		if(!nv && !ne) break;
		string from ,to;
		for(int i = 0 ; i < ne; i++){
			cin >> from >> to;
			if(t.find(from) == t.end()) t[from] = npp++, f[npp-1] = from;
			if(t.find(to) == t.end()) t[to] = npp++, f[npp-1] = to;
			d[t[from]][t[to]] = 1;
			d[t[to]][t[from]] = 1;
		}
		memcpy(d1, d, sizeof(d));
		for(int i = 0; i < nv; i++){
			for(int j = 0; j < nv; j++){
				if(d[i][j] == 0) d2[i][j] = MAXX;
				else {
					d2[i][j] = d[i][j];
				}
			}
			d2[i][i] = 0;
			d1[i][i] = 1;
		}
		for(int k = 0; k < nv; k++){
			for(int i = 0; i < nv; i++){
				for(int j = 0; j < nv; j++){
					d1[i][j] |= (d1[i][k] & d1[k][j]);
					d2[i][j] = min(d2[i][j], (d2[i][k] + d2[k][j]));
				}
			}
		}

		bool dis = false;
		for(int i = 0; i < nv; i++){
			for(int j = 0; j < nv; j++){
				if(d1[i][j] == 0){
					dis = true;
					break;
				}
			}
			if(dis) break;
		}
		cout << "Network "<<nn++ << ": ";
		if(dis){
			cout <<"DISCONNECTED"<<endl<<endl;
		}
		else{
			int md = -1;
			for(int i = 0; i < nv; i++){
				for(int j = 0; j < nv; j++){
					if(d2[i][j] > md) md = d2[i][j];
				}
			}
			cout << md << endl<<endl;
		}

	}
	return 0;
}