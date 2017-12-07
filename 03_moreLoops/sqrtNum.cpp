// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int root = 0;

	while(root * root <= N){
		root = root + 1;
	}	

	cout << root - 1;
}