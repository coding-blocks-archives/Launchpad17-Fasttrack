// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool checkPrime(int num){
	// logic to test if the num is prime or not
	int div = 2;
	while(div < num){
		if (num % div == 0) return false;
	div++;
	}
	return true;
}

void primesUptoN(int N){
	for(int curNum = 2; curNum <= N; ++curNum){
		if (checkPrime(curNum) == true){
			cout << curNum << " ";
		}
	}
}


int main(){
	int N;
	cin >> N;

	primesUptoN(N);	
}