// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool checkOdd(int n){
	// This function return the value if n is odd or not
	
	if (n % 2 == 1) return true;
	return false;
}


int main(){
	int N;
	cin >> N;

	for(int x = 0; x <= N; ++x){
		if (checkOdd(x) == true){
			cout << x << " ";
		}
	}	
}