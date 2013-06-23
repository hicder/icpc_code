#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINT 1000000
#define min(a,b) (a) < (b) ? (a) : (b)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int AdjMatrix[1000][1000];
int dist[1000][1000];
int max_vertice = 0;
int nvertice;
bool notdone = true;;
void input(){
	max_vertice = 0;
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			AdjMatrix[i][j] = MAXINT;
		}
	}
	
	notdone = true;
	int u, v;
	cin >> u >> v;
	while(u != 0){
//		cout << u << " " << v << endl;
		notdone = false;
		if(u > max_vertice) max_vertice = u;
		if(v > max_vertice) max_vertice = v;
		AdjMatrix[u][v] = 1;
		cin >>u >> v;
	}
	return;
}

void printmatrix(){
	for(int i = 1; i <= max_vertice; i++){
		for(int j = 1; j <= max_vertice; j++){
			if(AdjMatrix[i][j] == MAXINT) cout << 0 << " ";
			else cout << AdjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int findnvertice(){
	int ret = 0;
	for(int i = 1; i <= max_vertice; i++){
		if(AdjMatrix[max_vertice][i] != MAXINT) ret++;
	}
	return ret;
}

int main(){
	freopen("input","r",stdin);
	do{
		input();
		if(notdone) break;
//		cout << max_vertice << endl;
		for(int k = 1; k <= max_vertice; k++){
			for(int i = 1; i <= max_vertice; i++){
				for(int j = 1; j <= max_vertice; j++){
					AdjMatrix[i][j] = min(AdjMatrix[i][j], (AdjMatrix[i][k] + AdjMatrix[k][j]));
				}
			}
		}
//		printmatrix();
		nvertice = findnvertice();
		float sum = 0;
		for(int i = 1; i <= max_vertice; i++){
			for(int j = 1; j <= max_vertice; j++){
				if(AdjMatrix[i][j] != MAXINT && i != j){
					sum += AdjMatrix[i][j];
				}
			}
		}
		sum = sum / (nvertice * (nvertice - 1));
		printf("%.3f\n",sum);
		
	}while(!notdone);
}
