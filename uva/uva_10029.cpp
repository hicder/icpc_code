#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>
#include <map>
using namespace std;

string dict[25001];
int n = 0;
int cost[25001];

string add(string s, char t, int idx){
	return s.substr(0,idx) + t + s.substr(idx);
}

string chg(string s, char t, int idx){
	return s.substr(0,idx) + t + s.substr(idx+1);
}

string del(string s, int idx){
	return s.substr(0,idx) + s.substr(idx+1);
}

int bsearch(string s, int end){
	int left = 0;
	int right = end - 1;
	
	while(left <= right){
		int mid = (left + right)/2;
		int t = s.compare(dict[mid]);
		if(t == 0) return mid;
		else if(t < 0)  right = mid - 1;
		else left = mid + 1;
	}
	
	return -1;
}

int main(){
	freopen("in","r",stdin);

	while(cin >> dict[n]){
		n++;
	}
	memset(cost, 0, sizeof(cost));
	int max = 0;
	for(int i = 0; i < n; i++){
		int len = dict[i].length();
		//add
		string t;
		for(int j = 0; j < len; j++){
			for(int k = 0; k < 26; k++){
				if(dict[i][j] >= 'a' + k){
					t = add(dict[i], 'a' + k, j);
					if(dict[i].compare(t) >= 0) {
						int m = bsearch(t, i);
						if(m >= 0 && cost[i] < cost[m] + 1) cost[i] = cost[m] + 1;
					}
					t = chg(dict[i],'a' + k, j);
					if(dict[i].compare(t) >= 0) {
						int m = bsearch(t, i);
						if(m >= 0 && cost[i] < cost[m] + 1) cost[i] = cost[m] + 1;
					}
				}
				else{
					break;
				}
			}
			
			if(j == len - 1 || dict[i][j] >= dict[i][j + 1]){
				t = del(dict[i], j);
				if(dict[i].compare(t) >= 0) {
					int m = bsearch(t, i);
					if(m >= 0 && cost[i] < cost[m] + 1) cost[i] = cost[m] + 1;
				}
			}
		}
		
		for(int k = 0; k < 26; k++){
			t = add(dict[i], 'a' + k, len);
			if(dict[i].compare(t) < 0) break;
			int m = bsearch(t, i);
			if(m >= 0 && cost[i] < cost[m] + 1) cost[i] = cost[m] + 1;
		}
		if(cost[i] > max) {
			max = cost[i];
		}
	}
	max ++ ;
	cout << max << endl;
	return 0;
}
