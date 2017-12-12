// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double fahrToCel(int fahr) {
	double cel =  (5.0 / 9.0) * (fahr - 32);
	return cel;
}

void fahrToCelPrint(int start, int end, int step) {
	while (start <= end) {
		// convert and print

		double ans = fahrToCel(start);
		cout << start << "F\t" << ans << endl;

		start = start + step;
	}
}

int main() {
	int initial, final, step;
	cin >> initial >> final >> step;

	fahrToCelPrint(initial, final, step);
}