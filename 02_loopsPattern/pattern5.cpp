/*
1
01
101
0101
10101
*/

#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >> nLines;

	for(int curRow = 1; curRow <= nLines; ++curRow){
		int val;	// val is undefined
		// // setting the val
		// if (curRow % 2 == 0){
		// 	val = 0;
		// }
		// else {
		// 	val = 1;
		// }

		val = curRow % 2;

		// print a line
		for(int ithVal = 1; ithVal <= curRow; ++ithVal){
			cout << val;
			// if (val == 1) val = 0;
			// else val = 1;
			val = 1 - val;
		}
		cout << endl;
	}
}
