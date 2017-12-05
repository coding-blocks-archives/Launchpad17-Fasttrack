/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
#include <iostream>
using namespace std;

int main() {
	int nLines;
	cin >> nLines;


	//print pattern...no no...n lines
	int val = 1;
	for (int curRow = 1; curRow <= nLines; ++curRow) {
		// print 1 line
		for (int ithVal = 1; ithVal <= curRow; ++ithVal) {
			cout << val << " ";
			++val;
		}

		cout << endl;
	}
}