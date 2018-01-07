// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i) { return i / 2;}
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void heapify(int arr[], int be, int en, int i){
    if ()
}


int main() {
    int arr[] = {5, 4, 3, 2, 1};
    make_heap(arr + 0, arr + 5, greater<int>);
    cout << arr[0];

//     for (int i = 0; i < 5; ++i) {
//         swap(i, 5);
//         heapify(i);
//     }
}