// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntDollar(){
	// cntDollar takes input from user and returns the cnt

	int cnt = 0;
	char c;

	// cin >> c;	// this ignores whitespace
	c = cin.get();

	while(c != '$'){
		++cnt;
		// cin >> c;
		c = cin.get();
	}
	return cnt;
}


int main(){
	int ans = cntDollar();	
	cout << ans << endl;

	char c;
	// cin >> c;
	// cout << c;
	// cin >> c;
	// cout << c;
}