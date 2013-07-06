#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#define pb push_back
#define pf printf
#define FOR(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int cb[5000];
vector<int> list;
int n;

bool cjo(){
	for(int i = 1; i < n; i++){
		if(!cb[i]) return false;
	}
	return true;
}

int main(){
	while(cin >> n){
		int x;
		if(n == 1) {
			cin >> x;
			cout << "Jolly" << endl; 
			continue;
		}
		memset(cb, 0, sizeof cb);
		list.clear();
		FOR(i,n){
			cin >> x;
			list.pb(x);
			if(i != 0) cb[(int)abs(list[i] - list[i - 1])] = 1;
		}
		if(cjo()) cout << "Jolly"<<endl;
		else cout << "Not jolly"<<endl;
	}
	return 0;
}