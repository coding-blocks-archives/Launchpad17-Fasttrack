#include <iostream>
using namespace std;

int main(){
	char c;
	cout << "Please enter a character ";
	cin >> c;

	cout << "Next 5 chars are : ";
	cout << (char)(c + 1) << endl;
	cout << c + 2 << endl;
	cout << c + 3 << endl;
	cout << c + 4 << endl;
	cout << c + 5 << endl;


}