#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
int board[13][13];
int n;
int diagrow[13];
int nprint;
int trans(int t){
	if(t == 0) return t;
	if(t < n) return t;
	int x = t;
	while(x >= n){
		if(x < n) break;
		if(x %n == 0){
			x--;
			continue;
		}
		
		x -= (n + 1);
	}
	
	return x;
}

int cdiag(int t){
	if(diagrow[trans(t)]) return 0;
	else return 1;
}



int main(){
	memset(board,0,sizeof(board));
	memset(diagrow,0,sizeof(diagrow));
	nprint = 0;
	cin >> n;
	
	return 0;
}
