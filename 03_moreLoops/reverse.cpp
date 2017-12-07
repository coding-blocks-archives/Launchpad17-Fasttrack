// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int reversedNum = 0;

	while(N != 0){
		int unitDigit = N % 10;
		N = N / 10;	//rem Num
		reversedNum = (reversedNum * 10) + unitDigit;
	}	

	cout << reversedNum;
}