#include <iostream>
#include <cstdio>
#include <cstdlib>
#define pf printf
using namespace std;

typedef long long ll;

ll a, b;
int n;

void di(ll x, ll y){
	ll z = x - y;
	if(z < 0) pf("<\n");
	else if (z > 0) pf(">\n");
	else pf("=\n");
}

int main(){
	cin >> n;
	while(n--){
		cin >> a >> b;
		di(a,b);
	}

	return 0;
}