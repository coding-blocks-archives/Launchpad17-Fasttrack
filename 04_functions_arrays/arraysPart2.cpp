// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void functionArray(int hathi[], int size){
	for(int i = 0; i < size; ++i){
		hathi[i] = hathi[i] + 2;
	}
}

int main(){
	int arr[100];
	
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}	
	\

	functionArray(arr, n);

	for(int i = 0; i < n; ++i){
		cout << arr[i];
	}
}