#include <iostream>
#include <cstdio>
#define pf printf
#define pfn printf("\n")
#define FOR(i,n) for(int i = 0; i < (n); i++)

using namespace std;
int n;
int xo, yo;

string ver[3] = {"N","S"};
string hor[3] = {"E","O"};

int main(){
	while(scanf("%d", &n) && n){
		cin >> xo >> yo;
		int x, y;
		FOR(i,n){
			cin >> x >> y;
			if(x == xo || y == yo) {cout << "divisa\n"; continue;}
			else{
				cout << ver[y < yo ? 1: 0] << hor[x < xo ? 1: 0]<<endl;
			}
		}
	}
	return 0;
}