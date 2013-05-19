/*
ID: phamduc1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool cprime(int t){
	if(t == 2) return true;
	int a = sqrt(t);
	for(int i = 2; i<=a ;i++){
		if (t % i == 0) return false;
	}
	return true;
}

bool checkpal(int t){
	int reverse = 0;
	int temp = t;
	while(temp != 0){
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp = temp/10;
	}
	
	if(t == reverse) return true;
	else return false;
}




int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int a, b;
	cin >> a >> b;
	for(int i = a; i <= b; i++){
		if( i >=100000 && i < 999999){
			i = 999999;
			continue;
		}
		if(i >= 10000000 && i < 99999999){
			i = 99999999;
		}
		if( i%2 == 0) continue;
		if(cprime(i) && checkpal(i)) cout << i << endl;
	}
}
