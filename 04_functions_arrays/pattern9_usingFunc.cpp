// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


void printStar(int n){
	for(int curStar = 1; curStar <= n; ++curStar){
		cout << "*";
	}
}

int main() {
	int N;
	cin >> N;

	for (int curRow = 1; curRow <= N; ++curRow) {
		printStar(curRow);
		cout << " ";
		printStar(N + 1 - curRow);
		cout << " ";
		printStar(N + 1 - curRow);
		cout << " ";
		printStar(curRow);
		cout << endl;
	}
}