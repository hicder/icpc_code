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
int n, b, h, w;
int p[20], a[20][13];

int main(){
//	freopen("input","r",stdin);
	while(scanf("%d%d%d%d", &n, &b, &h, &w) == 4){
		memset(p, 0, sizeof p);
		memset(a, 0, sizeof a);
		FOR(i, h){
			cin >> p[i];
			FOR(j,w){
				cin >> a[i][j];
			}
		}
		bool found = false;
		int minh = 0, minw = 0;
		FOR(i,h){
			if(n * p[i] > b) continue;
			FOR(j, w){
				if(a[i][j] >= n){
					if(!found){
						minh = i;
						minw = j;
						found = true;
						break;
					}
					else{
						if(p[minh] > p[i]){
							minh = i;
							found = true;
						}
					}

				}
			}
		}
		if(found) pf("%d\n", n * p[minh]);
		else pf("stay home\n");
	}
	return 0;
}