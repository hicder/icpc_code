#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long n, m, a, ret;
  cin >> n >> m >> a;
  ret = ceil(n/(double)a) * ceil ( m/(double)a);
  cout << ret << endl;
  return 0;
}
