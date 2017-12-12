// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(int arr[], int n) {
	for (int i = 0; i < n; ++i)	{
		cin >> arr[i];
	}
}


void outputArr(int arr[], int n) {
	// print an array and enter a newline
	for (int i = 0; i < n; ++i)	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int binarySearch(int arr[], int N, int x) {
	int be = 0;
	int en = N  - 1;

	while(be <= en){
		int mid = (be + en) / 2;
		if (arr[mid] == x) return mid;	// hunt completed
		else if (arr[mid] < x) be = mid + 1;	// search in the right
		else en = mid - 1;	// search in the left
	}
	return -1;	// element not present
}

int main() {
	int arr[10];

	int N;
	cin >> N;

	inputArr(arr, N);
	selectionSort(arr, N);
	outputArr(arr, N);
}