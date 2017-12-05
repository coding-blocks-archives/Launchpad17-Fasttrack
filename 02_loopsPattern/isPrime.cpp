#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	int div = 2;
	bool isPrime = true; 	//assumption that no is prime

	while(div < N){
		// check for divisibility
		if (N % div == 0){
			isPrime = false;	//assumption broken
			break;
		}
		div  = div + 1;
	}

	if (isPrime == true){
		cout << N << " is prime\n";
	}
	else {
		cout << N << " is not prime";
	}
}