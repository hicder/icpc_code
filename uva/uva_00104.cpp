#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
	
float table[21][21][21];
int n;
float p[21][21][21];

void input(){
	memset(table, 0, sizeof(table));
	memset(p, 0, sizeof(p));
	for (int i = 0; i < n;i++)
	{
		table[i][i][1] = 1.0;
		for (int j = 0; j < n; j++)
		{
			for(int w = 2; w <= n; w++) table[i][j][w] = 0;
			if(i != j) 
				cin >> table[i][j][1];

		}
	}
}

void find(int i, int j, int w){
	if(w == 0){
		cout <<(i + 1);
		return;
	}
	find(i, p[i][j][w], w-1);
	cout << " " << (j + 1);
}

void solve(){
	int found = 0;
	int index = -1;
	for(int w = 2; w <= n; w++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					if(table[i][j][w] < table[i][k][w-1]* table[k][j][1]){
						table[i][j][w] = table[i][k][w-1] * table[k][j][1];
						p[i][j][w] = k;
					}
				}

				if(table[i][i][w] > 1.01){
					index = i;
					found = 1;
					break;
				}
			}
			if(found) {
				find(index, index, w);
				cout << endl;
				break;
			}
		}
		if(found) break;
	}
	if(!found) printf("no arbitrage sequence exists\n");
}

int main(){
//	freopen("input", "r", stdin);
	while(cin >> n){
		input();
		solve();
	}
	return 0;
}