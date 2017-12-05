#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int curNum = 2; curNum <= N; curNum = curNum + 1) {
		int div = 2;
		bool isPrime = true;
		while (div < curNum) {
			if (curNum % div == 0) {
				isPrime = false;
				break;
			}
			++div;
		}
		// if prime --> print
		if (isPrime) cout << curNum << " ";
	}
}