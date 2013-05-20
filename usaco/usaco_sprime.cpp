/*
ID: phamduc1
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdio>


using namespace std;
int n;
int ptable[8][100];
int cprime(int t){
	if(t == 1) return 0;
	if(t == 2) return 1;
	int k = sqrt(t);
	for(int i = 2; i <= k; i++){
		if(t % i == 0) return 0;
	}
	
	return 1;
}

int gensprime(int t){
	if(t == 1){
		int c = 0;
		for(int i = 2; i <=9; i++){
			if(cprime(i)) ptable[0][c++] = i; 
		}
		return c;
	}
	
	int x = gensprime(t - 1);
	int count = 0;
	for(int i = 0; i < x; i++){
		for(int j = 1; j <= 9; j+=2){
			if(cprime(ptable[t-2][i] * 10 + j)) ptable[t-1][count++] =  ptable[t-2][i] * 10 + j;
		}
	}
	return count;
}

int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	
	cin >> n;
	memset(ptable, 0, sizeof(ptable));
	if(n == 1){
		cout << "2\n3\n5\n7\n";
		return 0;
	}
	
	int c = gensprime(n);
	for(int i = 0; i < c; i++){
		cout << ptable[n-1][i] << endl;
	}
	return 0;
}
