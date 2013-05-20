/*
ID: phamduc1
PROG: checker
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
int board[14][14];
int n=0;
int backdiag[26];
int forediag[26];
int rowplaced[14];
int nprint=0;
int nsol=0;
int back_trans(int row, int col){
	if (col >= row){
		return (col - row);
	}
	else{
		return ((row - col) + (n-1));
	}
}

int fore_trans(int row, int col){
	return (row + col);
}

bool canplace(int row, int col){
	if((rowplaced[row] == 0) && (backdiag[back_trans(row,col)] == 0) && (forediag[fore_trans(row,col)] == 0)){
		return true;
	}
	else{
		return false;
	}
}

void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[j][i]){
				cout << (j+1);

				if(i != (n - 1)) {
					cout << " ";

				}
				break;
			}
		}
	}
	cout << endl;
}

void printcerr(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[j][i]){
				cerr << (j+1);
				if(i != (n - 1)) {
					cerr << " ";
				}
				break;
			}
		}
	}
	cerr << endl;
}

void place(int col){
	if(col == n) {
		nsol ++;
		if(nprint < 3){
			print();
			nprint++;
		}
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(canplace(i, col)){
			rowplaced[i] = 1;
			board[i][col] = 1;
			backdiag[back_trans(i,col)] = 1;
			forediag[fore_trans(i,col)] = 1;
			place(col + 1);
			backdiag[back_trans(i,col)] = 0;
			forediag[fore_trans(i,col)] = 0;
			board[i][col] = 0;
			rowplaced[i] = 0;
		}
	}
}

int main(){
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	memset(board,0,sizeof(board));
	memset(backdiag,0,sizeof(backdiag));
	memset(forediag,0,sizeof(forediag));
	memset(rowplaced,0,sizeof(rowplaced));
	cin >> n;
	nsol = 0;
	nprint = 0;
	place(0);
	cout<<nsol<<endl;
	return 0;
}
