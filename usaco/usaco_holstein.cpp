/*
ID: phamduc1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int v, g;
int vitareq[1000];
int feedtab[15][1000];
int btrtab[15];
int temptab[1000];
bool ret = false;
void input(){
	memset(vitareq,0,sizeof(vitareq));
	memset(feedtab,0,sizeof(feedtab));
	memset(btrtab,0,sizeof*(btrtab));
	
	cin >> v;
	for(int i = 0; i < v; i++){
		cin >> vitareq[i];
	}
	
	cin >> g;
	for(int i = 0; i < g; i++){
		for(int j = 0; j < v; j++){
			cin >> feedtab[i][j];
		}
	}
}

bool checkreq(){
	memset(temptab, 0, sizeof(temptab));
	for(int i = 0; i < v; i++){
		for(int j = 0; j < g; j++){
			if(btrtab[j] == 0) continue;
			else{
				temptab[i] += feedtab[j][i];
			}
		}
		if(temptab[i] < vitareq[i]) return false;
	}
	
	return true;
}

void backtrack(int lev, int num, int totalnum){
	//base case:
	if(num == totalnum){
		ret = checkreq();
		if(ret){
			cout << num;
			for(int i = 0; i < g; i++){
				if(btrtab[i]) cout << " "<<(i+1);
			}
			cout << endl;
		}
		return;
	}
	else if(lev == g && num < totalnum) return;
	
	if(ret) return;
	//recursive cases
	if(num < totalnum){
		btrtab[lev] = 1;
		backtrack(lev +1, num + 1, totalnum);
	}
	btrtab[lev] = 0;
	backtrack(lev + 1, num, totalnum);
	
	
}

int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	input();
	for(int i = 1; i <= g; i++){
		if(ret) break;
		backtrack(0,0, i);
	}
	return 0;
}
