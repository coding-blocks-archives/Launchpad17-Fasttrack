#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	if (x == 2) {
		// if input is 2
		/*2 2
		  2 2*/
		cout << "2 2\n\t2 2\n";
	}
	else if (x == 3) {
		// if input is 3
		/*3 3 3
		  3 3 3*/
		cout << "3 3 3 \n\t3 3 3\n";
	}
	else {
		// otherwise
		/*1*/
		cout << "1\n" << endl;
	}





}