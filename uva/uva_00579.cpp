#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000

using namespace std;
int h, m;

double geta(double x){
	while(x > 180) x = 360 - x;
	return x;
}

int main(){
//	freopen("input","r",stdin);
	double hang, mang, diff;
	while(scanf("%d %*c %d", &h, &m) == 2){
		hang = h/12.0 * 360 + m/60.0 * 30;
		mang = m/60.0 * 360;
		if(hang == 0 && mang == 0) break;
		diff = geta(abs(hang - mang));
		pf("%.3f\n",diff);
	}
	return 0;
}