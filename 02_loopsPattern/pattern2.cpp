/*	
	1
   123
  12345
 1234567
123456789
*/
#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >>  nLines;

	// print nLines
	for(int curRow = 1; curRow <= nLines; ++curRow){
		// print space
		int nSpaces = nLines - curRow;
		for(int curSpace = 1; curSpace <= nSpaces; ++curSpace){
			cout << " ";
		}

		// print values
		int nVal = 2 * curRow - 1;
		for(int curVal = 1; curVal <= nVal; curVal = curVal + 1){
			cout << curVal;
		}

		// print an enter
		cout << endl;
	}
}