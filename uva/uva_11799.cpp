#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000
using namespace std;
vector<int> list;
int t;
int main(){
	freopen("input","r",stdin);
	cin >> t;
	string s;
	cin.ignore();
	int ca = 1;
	while(t--){
		list.clear();
		int x;
		getline(cin,s);
		stringstream a;
		a.str(s);
		while(a >> x){
			list.pb(x);
		}
		sort(list.begin(), list.end());
		pf("Case %d: %d\n",ca++,list[list.size()-1]);
	}
}