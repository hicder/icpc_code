#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define pf printf
#define pb push_back
#define pfn printf("\n")
#define INF 1000000000

using namespace std;
int n, p;
vector<string> name;
vector<int> price;
vector<int> nreq;
int main(){
//	freopen("input","r",stdin);
	string temp;
	int ca = 1;
	while(scanf("%d%d",&n,&p) && n){
		cin.ignore();
		name.clear();
		price.clear();
		nreq.clear();
		FOR(i,n){
			getline(cin, temp);
		}
		double px;
		int _nreq;
		FOR(i,p){
			getline(cin, temp);
			name.pb(temp);
			cin >> px >> _nreq;
			price.pb(px);
			nreq.pb(_nreq);
			cin.ignore();
			FOR(j,_nreq) getline(cin,temp);
		}
		int maxreq = 0;
		FOR(i, name.size()){
			if(nreq[i] > nreq[maxreq]){
				maxreq = i;
			}
			else if(nreq[i] == nreq[maxreq]){
				if(price[i] < price[maxreq]) maxreq = i;
			}
		}

		if(ca != 1) pf("\n");
		pf("RFP #%d\n",ca++);
		cout << name[maxreq]<<endl;
	}
}