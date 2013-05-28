/*
ID: phamduc1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, b, d;
int tab[257][257];
bool add[257][257];
int max_num;
vvi data;
queue<int> q;
vi list;
vi acc;

bool done = false;
int dist(int a, int b){
	int x = a ^ b;
	x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	x = (x & 0x0F0F0F0F) + ((x>>4) & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) + ((x>>8) & 0x00FF00FF);
	x = (x & 0x0000FFFF) + ((x>>16)& 0x0000FFFF);
	return x;
}

void input(){
	memset(tab, 0, sizeof(tab));
	memset(add,0,sizeof(add));
	cin >> n >> b >> d;
	max_num = 1 << b;

}

void printvector(vi k){
	for(int i = 0; i < (int)k.size(); i++){
		cout << k[i] << " ";
	}
	cout << endl;
}

bool validate(int idx){
	for(int i = 0; i < (int)acc.size(); i++){
		if(dist(list[idx],acc[i]) < d) return false;
	}
	return true;
}

void dfs(int idx, int num){
	if(num == n){
		int count = 0;
		for(int i = 0; i < num; i++){
			cout << acc[i];
			count ++ ;
			if(count % 10 == 0) cout << endl;
			else if( count != (int)acc.size())cout << " ";
		}
		if(count %10 != 0) cout << endl;
		done = true;
		return;
	}
	if(done) return;
	if(idx == (int)list.size() && num < n) {
		return;
	}
	if(validate(idx)){
		acc.push_back(list[idx]);
		dfs(idx + 1, num + 1);
	}
	else{
		dfs(idx + 1, num);
	}
	if(done) return;
	acc.pop_back();
	
	
}

int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	input();
	list.push_back(0);
	for(int i = 1; i <= max_num; i++){
		if(dist(0,i) >= d) list.push_back(i);
	}
	acc.push_back(0);
	dfs(1,1);
	return 0;
}
