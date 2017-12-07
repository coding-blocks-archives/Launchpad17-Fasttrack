// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int nDigits = 0;	//assumption : the num has 0 digits

	while(num != 0){
		int rem = num % 10;
		num = num / 10;
		nDigits = nDigits + 1;
	}	

	cout << num << endl;
	cout << nDigits << endl;
}