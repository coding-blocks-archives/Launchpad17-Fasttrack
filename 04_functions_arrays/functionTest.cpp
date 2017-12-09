// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int updateN(int x){
	++x;
	return x;

}

int main(){
	int n = 2;
	updateN(n);
	cout << n;	
}