#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int main(){
  string in;
  bool len = false;
  bool large = false;
  bool small = false;
  bool digit = false;
  cin >> in;
  if(in.length() >= 5) len = true;
  for(int i = 0; i < in.length(); i++){
    if(islower(in[i])) small = true;
    if(isupper(in[i])) large = true;
    if(isdigit(in[i])) digit = true;
  }
  if(len && large && small && digit) cout << "Correct"<<endl;
  else cout << "Too weak"<<endl;
  return 0;
}
