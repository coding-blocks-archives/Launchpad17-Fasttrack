#include <iostream>
using namespace std;

int main() {
	// input 2 numbers
	int dividend, divisor;
	cin >> dividend >> divisor;

	// divide them
	// if quotient is not zero, divide and print
	if (divisor != 0) {
		double quotient = (double)dividend / divisor;
		cout << quotient;
	}
	else {
	// otherwise, print Plz enter non zero divisor
		cout << "Plz enter non zero divisor";
	}
}