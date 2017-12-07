/*
   *
  ***
 *****
  ***
   *
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
	//input no of lines
	int N;
	cin >> N;

	//print N/2 + 1 lines in increasing way
	int incRow = N / 2 + 1;

	for (int curRow = 1; curRow <= incRow; ++curRow) {

		// print space
		int nSpaces = incRow - curRow;
		for (int i = 0; i < nSpaces; ++i) {
			cout << " ";
		}

		//print "*"
		int nStar = 2 * curRow - 1;
		for (int i = 0; i < nStar; ++i) {
			cout << "*";
		}

		//one line printed
		cout << endl;
	}

	//print N/2 line in decreasing way
	int decRow = N / 2;
	for (int curRow = 1; curRow <= decRow; ++curRow) {
		int nSpace = curRow;
		for (int i = 0; i < nSpace; ++i) {
			cout << " ";
		}

		//print values
		int nVal = 2 * (decRow - curRow + 1) - 1;
		for(int i = 0; i < nVal; ++i){
			cout <<  "*";
		}
		cout << endl;
	}
}