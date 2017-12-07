// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	int sum = 0;
	for (int x = 1; x <= N; ++x) {
		sum = sum + (x * x);
	}
	cout << sum;
}