/*
ID: phamduc1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int freq[4];
int cum[4];
int cumupper[4];
int n;
int tab[1001];
int righttab[1001];
int nswap = 0;
int lastoccurances[4];
void swap(int i, int j){
	if(i == j) return;
	nswap ++;
	int temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

bool isout(int idx){
	int temp = tab[idx];
	return (idx >= cum[temp]) && idx < cumupper[temp];
}

int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	memset(freq,0,sizeof(freq));
	memset(tab,0,sizeof(tab));
	memset(cum,0,sizeof(cum));
	memset(lastoccurances,0,sizeof(lastoccurances));
	cin >> n;
	int counter = 0;
	for(int i = 0; i < n; i++){
		cin >> tab[counter++];
		freq[tab[counter-1]] ++;
		if(lastoccurances[tab[counter-1]] < i) lastoccurances[tab[counter-1]] = i;
	}
	
	for(int i = 1; i < 4; i++){
		cum[i] = cum[i-1] + freq[i-1];
		cumupper[i] = cum[i] + freq[i];
	}
	
	for(int i = 1; i < 4; i++){
		for(int j = cum[i]; j < cumupper[i];j++){
			righttab[j] = i;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(tab[i] == righttab[i]) continue;		//it's fine, move on
		bool found = false;
		//check within the range of the wrong value
		int tempj = cum[tab[i]];
		for(int j = cum[tab[i]]; j < cumupper[tab[i]] && !found; j++){
			if(tab[j] == righttab[i]){
				found = true;
				swap(i,j);
			}
			else if (tab[j] != righttab[j]){
				if(tab[tempj] == righttab[j]) tempj = j;
				else{
					//choose the minimum
					if(tab[tempj] > tab[j]) tempj = j;
				}
			}
			
		}
		if(found) continue;
		else{
			swap(tempj,i);
			i--;
		}
	}
	cout << nswap<<endl;
	return 0;
}
