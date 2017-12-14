// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	char arr[20];	// declaration
	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = '\0';
	arr[3] = 'e';	// assignment

	for(int i = 0; i < 5; ++i) cout << arr[i];
	cout << endl;

	// int x = 4;
	// cout << &x;

	// char arr[] = "a bcde";
	cout << arr << endl;


	// cout << sizeof(arr);

	// cout << "X" << arr[1] << "X";
	// cout << "X" << arr[4] << "X";

	// cout << (int)'A' << endl;
	// cout << (int)'\0' << endl;
	// cout << (int)' ' << endl;

	// cout << arr[0] << endl;
	// cout << arr[3] << endl;


}