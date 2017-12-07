/*
5
4 4
3 3 3
2 2 2 2
1 1 1 1 1
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	for (int curRow = 1; curRow <= N; ++curRow) {
		//printing one line
		int valToBePrinted = N - curRow + 1;
		for (int curValCount = 1; curValCount <= curRow; ++curValCount) {
			cout << valToBePrinted << " ";
		}
		// printing one line completed...successfully!!!
		cout << endl;
	}
}