/*
1
1 2 3
1 2 3 4
*/
#include <iostream>
using namespace std;

int main() {
	int lines;
	cin >> lines;

	//print n lines
	for (int curRow = 1; curRow <= lines; ++curRow) {

		// print current line
		for (int val = 1; val <= curRow; ++val) {
			cout << val << " ";
		}
		cout << endl;

	}
}