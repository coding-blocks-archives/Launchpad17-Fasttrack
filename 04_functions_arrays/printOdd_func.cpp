// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printOdd(int n){
	for(int x = 1; x <= n; ++x){
		if (x % 2 == 1){
			cout << x << " ";
		}
	}
}


int main(){
	int N;
	cin >> N;
	printOdd(N);	
}