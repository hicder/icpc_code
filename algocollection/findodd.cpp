#include <iostream>
using namespace std;
int arr[5] = {3,2,3,2,5};

int main(){
	int sum = 0;
	for(int i = 0; i < 5; i++){
		sum = sum ^ arr[i];
	}
	cout << sum << endl;
	return 0;
}