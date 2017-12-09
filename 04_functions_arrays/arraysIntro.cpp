// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int sumArr(int arr[5]){
	// sum of array
	int sum = 0;
	for(int i = 0; i < 5; ++i){
		sum = sum + arr[i];
	}
	return sum;
}

int main(){
	int marks[5];	// array of 5 elements
	// these 5 elements can be referred from [0,4]

	for(int i = 0; i < 5; ++i){
		cin >> marks[i];
	}

	int sum = sumArr(marks);
	cout << sum << endl;


}