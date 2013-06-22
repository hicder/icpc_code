#include <iostream>
#define min(a,b) (a)<(b)?(a):(b)
#define MAXINT 100000
using namespace std;

int AdjMatrix[200][200];
int dist[200][200];
int nvertices;
void init(){
	for(int i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++){
			dist[i][j] = MAXINT;
			AdjMatrix[i][j] = 0;
		}
	}
}
void input(){
	//similar to other graph files
}

int main(){
	for(int k = 0; k < nvertices; k++){
		for(int i = 0; i < nvertices; i++){
			for(int j = 0; j < nvertices; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	//print the shortest part to stdout
	return 0;
}
