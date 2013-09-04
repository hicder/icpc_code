#include <iostream>
#include <cmath>

using namespace std;

int dp[100001];

void init(){
	for(int i = 0; i < 10; i++){
		dp[i] = i;
	}
	for(int i = 10; i < 100001; i++){
		dp[i] = -1;
	}
}

int pdigit(int n){
	int ret = 1;
	while ( n > 0){
		int x = n % 10;
		ret = ret * x;
		n = n/10;
		if(ret == 0) return 0;
	}
	return ret;
}

void calc(int n){
	
	if(n < 10) {
		cout << n << endl;
		return;
	}
	cout << n << " ";
	if(dp[n] == -1){
		int x = pdigit(n);
		dp[n] = x;
		calc(x);
	}else{
		calc(dp[n]);
	}
}

int main(){
	freopen("input", "r", stdin);
	init();
	int n;
	cin >> n;
	while(n != 0){
		calc(n);
		cin >> n;
	}
	return 0;
}
