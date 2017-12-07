// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int N) {
	int nFact = 1;
	for (int x = 1; x <= N; ++x) {
		nFact = nFact * x;
	}

	// ---nFact = n!
	return nFact;
}


int main() {
	int n;
	int r;
	cin >> n >> r;

	int nFact = factorial(n);
	int rFact = factorial(r);
	int nrFact = factorial(n - r);

	int ans = nFact / (rFact * nrFact);
	cout << ans;
	



}