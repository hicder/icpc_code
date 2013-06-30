#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
long long xi[105], yi[105], ri[105];
int k, m;
int ni;
int d[105][105];
int cdis(int i, int j){
	long long dx = xi[i] - xi[j];
	long long dy = yi[i] - yi[j];
	if((dx*dx + dy*dy) <= (k*m + ri[i] + ri[j])*(k*m + ri[i] + ri[j])) return 1;
	else return 0;
}

void input(){
	memset(xi, 0, sizeof xi);
	memset(yi, 0, sizeof yi);
	memset(ri, 0, sizeof ri);
	memset(d, 0, sizeof d);
	cin >> xi[0] >> yi[0] >> ri[0] >> xi[1] >> yi[1] >> ri[1] >> ni;
	for(int i = 0; i < ni; i++){
		cin >> xi[i+2] >> yi[i+2] >> ri[i+2];
	}
	for(int i = 0; i < ni+2; i++){
		for(int j = 0; j < ni+2; j++){
			d[i][j] = cdis(i,j);
		}
	}
}

void par(){
	for(int i = 0; i < ni+2; i++){
		for(int j = 0; j < ni+2; j++){
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
//	freopen("input", "r", stdin);
	while(cin >> k >> m){
		input();
		for(int k = 0; k < ni+2; k++){
			for(int i = 0; i < ni+2; i++){
				for(int j = 0; j < ni+2; j++){
					d[i][j] |= (d[i][k] & d[k][j]);
				}
			}
		}
//		par();
		if(d[0][1]) cout << "Larry and Ryan will escape!"<<endl;
		else cout << "Larry and Ryan will be eaten to death."<<endl;
	}
	return 0;
}