#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int npy(unsigned long long n){
	int ret = 0;
	unsigned long long nsquared = n * n;
	for(unsigned long long i = 1; i < n; i++){
		if(nsquared % i == 0){
			unsigned long long t = nsquared / i;
			if((t + i) % 2 == 0 && (t-i)/2 > n) {
				ret ++ ;
			}
		}
	}
	
	return ret;
}

int main(){
	unsigned long long n;
	cin >> n;
	while(n != 0){
		cout << npy(n) << endl;
		cin >> n;
	}
}
