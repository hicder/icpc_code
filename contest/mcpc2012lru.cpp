#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector< pair<int,char> > cache;
int s; string line;
int c = 0;

void input(){
	cache.clear();
	getline(cin, line);
}

void printcache(){
	if(cache.size() == 0) return;
	sort(cache.begin(), cache.end());
	for(int i = 0; i < (int)cache.size(); i++){
		cout << cache[i].second;
	}
	cout << endl;
}

int exist(char c){
	if(cache.size() == 0) return -1;
	for(int i = 0; i < (int)cache.size(); i++){
		if(cache[i].second == c) {
			return i;
		}
	}
	return -1;
}

void exe(){
	for(int i = 0; i < (int)line.size(); i++){
		if(line[i] == '\n') {
			break;
		}
		else if(line[i] == ' ') {
//			cout  << "there is a space" << endl;
			continue;
		}
		else if(line[i] == '!'){
			printcache();
		}
		else{
			int index = exist(line[i]);
			//check if the element is inside the cache
			if(index >= 0){
				//it doesn't matter if it's full, coz we're not adding anything
				for(int i = index + 1; i < (int) cache.size(); i++){
					cache[i].first --;
				}
				cache[index].first = c -1;
				sort(cache.begin(), cache.end());
			}
			else{
				//if it's not full
				if((int)cache.size() < s){
					cache.push_back(make_pair(c, line[i]));
					c++;
				}
				else{	//if it's full
					cache[0].first = c-1;
					cache[0].second = line[i];
					for(int i = 1; i < (int)cache.size(); i++){
						cache[i].first --;
					}
					sort(cache.begin(), cache.end());
				}
				
			}
		}
	}
}

int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	cin >> s;
	int num = 0;
	while(s > 0){
		cout << "Simulation "<<(++num) << endl;
		input();
		exe();
		cin >> s;
	}
	return 0;
}
