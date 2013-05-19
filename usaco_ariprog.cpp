/*
ID: phamduc1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;

short tab[125001];

int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	int n, m;
	cin >> n >> m;
	bool hasinput = false;
	int mstep = (2 * m * m)/(n-1);
	memset(tab,0,sizeof(tab));
	for(int i = 0; i <= m; i++){
		for(int j = i; j <=m; j++){
			int t = i*i + j*j;
			tab[t] = 1;
		}
	}
	for(int j = 1; j <= mstep; j++){
		for(int i = 0; i <= m * m; i++){
			if(!tab[i]) continue;
			bool a = true;
			for(int k = 1; k < n; k++){
				if(i + j * k > 2 * m * m) {
					a = false;
					break;
				}
				if(!tab[i + j * k]) {
					a = false;
					break;
				}
			}
			
			if(a) {
				cout << i << " " << j << endl;
				hasinput = true;
			}
			
		}
	}
	if(!hasinput) cout << "NONE"<<endl; 
	
	return 0;
}
