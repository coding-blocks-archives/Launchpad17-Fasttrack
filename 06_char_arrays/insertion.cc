// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

void outputArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertionSort(int arr[], int n) {
	for (int unsorted_position = 1; unsorted_position < n; ++unsorted_position) {
		int cur_element = arr[unsorted_position];

		int pos_to_insert = unsorted_position - 1;	// one_pos_prior

		while (pos_to_insert >= 0 && arr[pos_to_insert] > cur_element) {
			// sort ckt evaluation
			// order matters
			arr[pos_to_insert + 1] = arr[pos_to_insert];
			--pos_to_insert;
		}
		arr[pos_to_insert + 1] = cur_element;
	}
}

double Median(int arr[], int N) {
	insertionSort(arr, N);

	double ans = (N % 2 == 1) ? arr[N / 2] : (0.5 * (arr[N / 2] + arr[N / 2 - 1]);
		
	if (N % 2 == 1) {
	ans = arr[N / 2];
	} else {
		ans = 0.5 * (arr[N / 2] + arr[N / 2 - 1]);
	}
	return ans;
}

int main() {
	int arr[10];
	int N;
	cin >> N;

	inputArr(arr, N);
	// insertionSort(arr, N);

	double middle = Median(arr, N);

	outputArr(arr, N);

	cout << middle << endl;
}