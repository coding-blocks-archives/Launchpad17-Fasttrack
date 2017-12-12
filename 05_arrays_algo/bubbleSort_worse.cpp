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

void bubbleSort(int arr[], int N){
	int nIter = N - 1;

	for(int i = 0; i < N; ++i){

		// size of the remaining unsorted array
		for(int curIdx = 0; curIdx < N; ++curIdx){
			if ((curIdx + 1 < N) && arr[curIdx] > arr[curIdx + 1]){
				// swap
				int tmp = arr[curIdx];
				arr[curIdx] = arr[curIdx + 1];
				arr[curIdx + 1] = tmp;
			}
		}
	}

}

int main() {
	int arr[10];

	int N;
	cin >> N;

	inputArr(arr, N);
	bubbleSort(arr, N);
	outputArr(arr, N);
}