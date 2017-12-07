/*
ABCDEEDCBA
ABCDDCBA
ABCCBA
ABBA
AA
*/

// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >> nLines;

	for(int curRow = nLines; curRow > 0; --curRow){
		int nVal = 2 * curRow;
		char val = 'A';
		for(int ithVal = 1; ithVal <= nVal; ++ithVal){
			cout << val;
			if (ithVal > curRow) val = val - 1;
			else if (ithVal == curRow) val = val;
			else val = val + 1;
		}
		cout << endl;
	}	
}