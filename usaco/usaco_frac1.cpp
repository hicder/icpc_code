/*
ID: phamduc1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define min(a,b) (a)<(b)?(a):(b)

using namespace std;
class node_t{
	public:
	node_t();
	node_t(int a, int b): num(a), deno(b){
	}
	int num;
	int deno;
	bool operator==(const node_t &lhs){
		return (lhs.num*deno == lhs.deno*num);
	}
	bool operator!=(const node_t &lhs){
		return (lhs.num*deno != lhs.deno*num);
	}
	void simplify(){
		if(num == 0) {
			deno = 1;
			return;
		}
		int k = 2;
		while(k <= num && k <= deno){
			if(num % k == 0 && deno %k == 0){
				num = num/k;
				deno = deno/k;
				k = 2;
				continue;
			}
			k++;
		}
	}
};
typedef vector<node_t> vn;

class mycomparison{
	public:
	mycomparison(){};
	bool operator()(const node_t &lhs, const node_t &rhs){
		return (lhs.num * rhs.deno > rhs.num * lhs.deno);
	}
};

typedef priority_queue<node_t, vn, mycomparison> pqvn;

int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int k;
	cin >> k;
	pqvn a;
	a.push(node_t(0,1));
	for(int i = 0; i < k; i++){
		for(int j = i; j != 0 && j <= k; j++){
			if(j == i && j != 1) continue;
			node_t temp(i,j);
			a.push(temp);
		}
	}
	if(k == 1) a.push(node_t(1,1));
	node_t prev(1,10000);
	
	while(!a.empty()){
		node_t cur = a.top();
		cur.simplify();
		a.pop();
		if(cur != prev) cout << cur.num <<"/"<<cur.deno<<endl;
		prev = cur;
	}
	
	/*
	node_t temp(2,6);
	temp.simplify();
	cout << temp.num << " " <<temp.deno<<endl;
	*/
	return 0;
}
