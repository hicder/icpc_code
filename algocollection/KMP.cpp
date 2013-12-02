#include <iostream>
#include <string>
#define MLEN 1000

using namespace std;

string T, P;
int n,m;
int b[MLEN]
void preKMP(){
	// build the back table;
	int i = 0, j = -1, b[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++;j++;
		b[i] = j;
	}

}

void KMP(){
	int i = 0; j = 0;
	while(i < n){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++;j++;
		if(j == m){
			cout << "found!" << endl;
		}
	}
}

int main(){
	i = 0; j = 0;
}
/*

P =    S E V E N T Y _ S E V E N
b =   -1 0 0 0 0 0 0 0 0 1 2 3 4 5

*/