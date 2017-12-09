// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

// bool checkOdd(int n); // function declaration

bool checkOdd(int n) {
	// function definition
	// This function return the value if n is odd or not

	if (n % 2 == 1) return true;
	return false;
}



void inputPrintOdd() {
	// THis function accepts N from user and prints odd numbers from [1, N]
	int N;
	cin >> N;
	for (int x = 1; x <= N; ++x) {
		if (checkOdd(x) == true) {
			cout << x << " ";
		}
	}
}

int main() {
	inputPrintOdd(); // function calling
}


