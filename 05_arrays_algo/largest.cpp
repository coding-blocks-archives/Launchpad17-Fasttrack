// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int findElement(int arr[], int sze, int elementToSearch){
	for(int i = 0; i < sze; ++i){
		if (arr[i] == elementToSearch){
			return i;
		}
	}
	return -1;
}

void findElement_1(int arr[], int sze, int elementToSearch){
	for(int i = 0; i < sze; ++i){
		if (arr[i] == elementToSearch){
			cout << i << " ";
		}
	}
	// return -1;
}

int largest(int arr[], int N){
	const int inf = 100000000;
	int larEleSoFar = -inf;

	for(int i = 0; i < N; ++i){
		if (larEleSoFar < arr[i]){
			larEleSoFar = arr[i];
		}
	}
	return larEleSoFar;
}

int main(){
	int arr[10];
	int N;
	cin >> N;

	// input arr
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}

	int x;
	cin >> x;

	// int ans = findElement(arr, N, x);
	// cout << ans;	

	// findElement_1(arr, N, x);

	int ans = largest(arr, N);
	cout << ans;
}