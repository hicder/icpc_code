#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#define YOUNG 1
#define MID 0
#define UNIDIR 0
#define BIDIR 1
#define MAXXX 100000000
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

int da[26][26];
int db[26][26];
int agepath[1000][1000];
map<char,int> val;
int ncity,nstreet;
int astart;
int bstart;
bool done = true;
vector<char> list;
void init(){
	nstreet = 0;
	ncity = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			da[i][j] = MAXXX;
			db[i][j] = MAXXX;
		}
		da[i][i] = 0;
		db[i][i] = 0;
	}
	val['Y'] = YOUNG;
	val['M'] = MID;
	val['U'] = UNIDIR;
	val['B'] = BIDIR;
}

void printmatrix(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << da[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << db[i][j] << " ";
		}
		cout << endl;
	}
}

void input(){
	char age, dir, u, v;
	int w;
	cin >> nstreet;
	if(!nstreet){
		done = false;
		return;
	}
	for(int i = 0; i < nstreet; i++){
		cin >> age >> dir >> u >> v >> w;
		if(age == 'Y'){
			da[u-65][v-65] = min(da[u-65][v-65],w);
			if(val[dir]){
				da[v-65][u-65] = min(da[u-65][v-65],w);
			}
		}
		else{
			db[u-65][v-65] = min(db[u-65][v-65],w);
			if(val[dir]){
				db[v-65][u-65] = min(db[u-65][v-65],w);
			}
		}
	}
	cin >> u >> v;
	astart = u - 65;
	bstart = v - 65;
//	printmatrix();
}

void travel(){
	for(int k = 0; k < 26; k++){
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				da[i][j] = min(da[i][j], (da[i][k] + da[k][j]));
				db[i][j] = min(db[i][j], (db[i][k] + db[k][j]));
			}
		}
	}
//	printmatrix();

}

int main(){
//	freopen("input","r",stdin);
	while(done){
		init();
		input();
		if(!done) break;
		travel();
		int minsum = MAXXX;
		for(int i = 0; i < 26; i++){
			if(da[astart][i] < MAXXX && db[bstart][i] < MAXXX){
				int d = da[astart][i] + db[bstart][i];
				if(d < minsum) {
					list.clear();
					minsum = d;
					list.push_back(i + 65);
				}
				else if (d == minsum){
					list.push_back(i + 65);
				}
			}
		}
		if(minsum != MAXXX){
			printf("%d",minsum);
			for(int i = 0; i < (int) list.size(); i++){
				printf(" %c",list[i]);
			}
			printf("\n");
		}
		else{
			printf("You will never meet.\n");
		}
	}
	return 0;
}
