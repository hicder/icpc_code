#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000
using namespace std;
int h, d, f;
float u;
int main(){
//	freopen("input","r",stdin);
	while(scanf("%d%f%d%d", &h, &u, &d, &f) && h){
		double ff = 0, dis = 0;
		ff = f/100.0 * u;
		int day = 0;
		while( dis <= h && dis >= 0){
			day++;
			dis = dis + u;
			if(dis < 0 || dis > h) {
				break;
			}
			dis = dis - d;
			u -= ff;
			if(u < 0) u = 0;
		}

		if(dis > h) pf("success on day %d\n", day);
		else pf("failure on day %d\n", day);
	}
	return 0;
}