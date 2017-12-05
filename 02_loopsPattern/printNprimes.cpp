#include <iostream>
using namespace std;

int main(){
	// 2 to N
	int N;
	cin >> N;

	int curNum = 2;
	while(curNum <= N){
		int div = 2;
		bool isPrime = true;
		while (div < curNum){
			if (curNum % div == 0){
				isPrime = false;
				break;
			}
			++div;
		}
	// if prime --> print
		if (isPrime) cout << curNum << " ";

	// else check for other prime
		++curNum;		
	}
}