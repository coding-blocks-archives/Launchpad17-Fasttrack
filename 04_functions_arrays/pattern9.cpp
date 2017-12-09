// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

/*
*_***_***_*
**_**_**_**
***_*_*_***
*/

#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	for (int curRow = 1; curRow <= N; ++curRow) {
		// think about line only....NOT pattern

		// print curRow times stars
		for (int star = 1; star <= curRow; ++star) {
			cout << "*";
		}

		// print space
		cout << " ";

		// print N + 1 - curRow stars
		int nStars = N + 1 - curRow;
		for (int star = 1; star <= nStars; ++star) {
			cout << "*";
		}

		// print space
		cout << " ";
		// print the other half

		// print N + 1 - curRow stars
		for (int star = 1; star <= nStars; ++star) {
			cout << "*";
		}

		cout << " ";

		// print curRow star
		for (int star = 1; star <= curRow; ++star) {
			cout << "*";
		}
		cout << endl;
	}
}