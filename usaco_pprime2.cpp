/*
ID: phamduc1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a, b;
bool cprime(int t){
	if(t == 2) return true;
	int a = sqrt(t);
	for(int i = 2; i<=a ;i++){
		if (t % i == 0) return false;
	}
	return true;
}

int checkdigit(int t){
	int c = 0;
	while(t != 0){
		c++;
		t = t/10;
	}
	
	return c;
}

void gen1(){
	if(a <= 2) cout << 2 << endl;
	if(a <=3) cout << 3 << endl;
	if (a <= 5) cout << 5 << endl;
	if (a <= 7) cout << 7 << endl;
}

void gen2(){
	if(a <= 11) cout << 11 << endl;
}

void gen3(){
	for(int d1 = 1; d1 <= 9; d1 +=2){
		for(int d2 = 0; d2 <=9; d2++){
			int pal = d1 * 100 + d2*10 + d1;
			if(pal >= a && pal <= b && cprime(pal)) cout << pal << endl;
		}
	}
}

void gen5(){
	for(int d1 = 1; d1 <= 9; d1 +=2){
		for(int d2 = 0; d2 <=9; d2++){
			for(int d3 = 0; d3 <=9; d3++){
				int pal = d1 * 10000 + d2*1000 + d3*100 + d2*10 + d1;
				if(pal >= a && pal <= b &&cprime(pal)) cout << pal << endl;
			}
		}
	}
}

void gen7(){
	for(int d1 = 1; d1 <= 9; d1 +=2){
		for(int d2 = 0; d2 <=9; d2++){
			for(int d3 = 0; d3 <=9; d3++){
				for(int d4 = 0; d4 <=9; d4++){
					int pal = d1 * 1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100+ d2*10 + d1;
					if(pal >= a && pal <= b &&cprime(pal)) cout << pal << endl;
				}
			}
		}
	}
}

int main(){
	
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	cin >> a >> b;
	int nda, ndb;
	nda = checkdigit(a);
	ndb = checkdigit(b);
	gen1();
	gen2();
	
	if(nda <= 3 && ndb >= 3) gen3();
	if(nda <= 5 && ndb >= 5) gen5();
	if(nda <= 7 && ndb >= 7) gen7();
	
	return 0;
}
