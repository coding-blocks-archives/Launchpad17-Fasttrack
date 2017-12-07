/*
5
5 4
5 4 3
5 4 3 2
5 4 3 2 1
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >> nLines;

	// print N lines
	for(int curRow = 1; curRow <= nLines; ++curRow){
		int val = nLines;
		//print curRow jitni values
		for(int curValCount = 1; curValCount <= curRow; ++curValCount){
			cout << val << " ";
			val = val - 1;
		}
		cout << endl;
	}
}