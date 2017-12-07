// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	char c;
	cin >> c;

	if (c >= 'A' and c <= 'Z'){
		cout << c << " is a uppercase letter\n";
	}
	else if (c >= 'a' && c <= 'z'){
		cout << c << " is a lowercase letter" << endl;
	}
	else {
		cout << "Not a letter" << endl;
	}


}