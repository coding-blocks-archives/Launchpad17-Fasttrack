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

int findLargest(int arr[], int be, int en){
	int largestPos = be;

	while(be <= en){
		if (arr[be] > arr[largestPos]){
			largestPos = be;
		}
		++be;
	}
	return largestPos;
}

int largest(int arr[], int N){
	int largestPos = 0;

	for(int i = 0; i < N; ++i){
		if (arr[largestPos] < arr[i]){
			largestPos = i;
		}
	}
	return largestPos;
}

void selectionSort(int arr[], int N){
	
	for(int endPos = N - 1; endPos >= 0; --endPos){
		int pos = findLargest(arr, 0, endPos);

		// swap arr[endPos] with arr[pos]
		int tmp = arr[endPos];
		arr[endPos] = arr[pos];
		arr[pos] = tmp;
	}	

}

int main() {
	int arr[10];

	int N;
	cin >> N;

	inputArr(arr, N);
	selectionSort(arr, N);
	outputArr(arr, N);
}