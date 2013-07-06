#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pf printf
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;

vi list;

int n;

int main(){
	scanf("%d", &n);
	int ca = 1;
	while(n--){
		list.clear();
		int x;
		FOR(i, 3){
			cin >> x;
			list.pb(x);
		}
		sort(list.begin(), list.end());
		pf("Case %d: %d\n",ca++, list[1]);
	}
	return 0;
}